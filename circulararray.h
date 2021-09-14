#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back=front-1, front=0;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    int mostrar_front();
    int mostrar_back();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
template <class T>
int CircularArray<T>::mostrar_front(){
    return array[front];
}

template <class T>
int CircularArray<T>::mostrar_back(){
    return array[back];
}
template <class T>
void CircularArray<T>::push_front(T data){
    if((front==0 and back==capacity-1) or (back+1 == front) ){
        T* temp= new T [capacity+10];
        for(int i =front; i<back;i++){
            temp[i+1]= array[i];
        }
        temp[front]=data;
        array= temp;
    }
    else {
        if(front == 0) front= capacity-1;
        else front --;
        array[front]=data;
    }

}
template <class T>
void CircularArray<T>::push_back(T data){
    if((front==0 and back==capacity-1) or (back+1 == front) ) {
        T* temp= new T [capacity+10];
        for(int i =front; i<back;i++){
            temp[i+1]= array[i];
        }
        temp[front]=data;
        array= temp;
    }
    else{
        if(back==-1) front = 0, back = 0;
        else if (back == capacity-1) back =0;
        else back++;
        array[back]=data;

    }
}
template <class T>
T CircularArray<T>::pop_front(){
    if(front == 0 and back == -1) cout<<"Array Vacio"<<endl;
    else if(front == capacity-1){
        array[front]= NULL;
        front = 0;
    }
    else if(front == back)cout<<"Array Vacio"<<endl;
    else front++;


}

template <class T>
T CircularArray<T>::pop_back(){
    if(front == 0 and back == -1) cout<<"Array Vacio"<<endl;
    else if(back == 0){
        array[back]= NULL;
        back = capacity-1;
    }
    else if(front == back)cout<<"Array Vacio"<<endl;
    else back--;
}
template <class T>
bool CircularArray<T>::is_full(){
    if(back+1 == front or (front == 0 and back ==capacity-1)) return true;
    else return false;
}
template <class T>
bool CircularArray<T>::is_empty(){
    if((front==0 and back == -1) or (front+1 == back)) return true;
    else return false;
}
template <class T>
void CircularArray<T>::clear(){
    while (array[front] != array[back]){
        array[back]=NULL;
        if(back == 0)back=capacity-1;
        else back--;
    }
}
