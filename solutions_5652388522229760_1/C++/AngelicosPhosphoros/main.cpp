#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <string.h>

using namespace std;

//#define mDEBUG
#ifdef mDEBUG

#include <fstream>
ifstream input_stream("input.txt", std::ifstream::in);
#endif

#ifndef mDEBUG
#define input_stream std::cin
#endif

int* input_numbers(size_t& size){
    input_stream>>size;
    int* res = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
        input_stream>>res[i];
    }
    return res;
}

inline void getDigits(long val, bool* digit_set){
    while(val>0){
        digit_set[val%10]= true;
        val/=10;
    }
}

inline bool check_digits(bool* digit_set){
    return digit_set[0]&&
            digit_set[1]&&
            digit_set[2]&&
            digit_set[3]&&
            digit_set[4]&&
            digit_set[5]&&
            digit_set[6]&&
            digit_set[7]&&
            digit_set[8]&&
            digit_set[9];
}

inline long process_value(int value){
    if(value==0){
        return -1;
    }
    bool digit_set[10];
    memset(digit_set,false,10);
    long sum = 0;
    do{
        sum+=value;
        getDigits(sum,digit_set);
    }
    while (!check_digits(digit_set));
    return sum;
}

int main()
{
    size_t number_count;
    int* numbers = input_numbers(number_count);
    std::set<int> uniq_nums(numbers, numbers+number_count);
    std::map<int,long> results;
    for (int i : uniq_nums)
    {
        long res = process_value(i);
        results.insert(make_pair(i,res));
    }
    stringstream ss;
    for (int i = 0; i<number_count; i++)
    {
        ss<<"Case #"<<i+1<<": ";
        int res = results[numbers[i]];
        if(res<0){
            ss<<"INSOMNIA";
        }
        else{
            ss<<res;
        }
        if(i<number_count-1) ss<<"\n";
    }
    std::cout<<ss.str();
    return 0;
}