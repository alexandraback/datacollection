#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
//#define mDEBUG
#ifdef mDEBUG

#include <fstream>


ifstream input_stream("input.txt", std::ifstream::in);
ofstream output_stream("output.txt", std::ofstream::out);
#endif

#ifndef mDEBUG
#define input_stream std::cin
#define output_stream std::cout
#endif

inline bool check_goodness(const bool* arr, const int size, int& found_index){
    for(found_index = size-1; found_index>=0 && arr[found_index]; found_index--);
    return found_index<0;
}

void negate_start(bool* arr){
    for (int i = 0; arr[i]; ++i)
    {
        arr[i]=false;
    }
}

void revenge(bool* arr, const int last_index){
    int left = 0, right = last_index;
    while (left<right){
        std::swap(arr[left],arr[right]);
        arr[left] = !arr[left];
        arr[right] = !arr[right];
        left++;
        right--;
    }
    if(left == right)
        arr[left] = !arr[left];
}

int calculate(bool* stack, int length){
    int last_false;
    int changes_count = 0;
    if(check_goodness(stack,length, last_false))
        return 0;
    while (last_false>=0)
    {
        if (last_false == 0)
        {
            return changes_count + 1;
        }
        else
        {
            if (stack[0])
            {
                changes_count++;
                negate_start(stack);
            }
            revenge(stack,last_false);
            changes_count++;
            if(check_goodness(stack,last_false,last_false)) // all elements in [last_false, length) are true, so we don't need to check them
                return changes_count;
        }
    }
}

bool*  parse_string(bool* arr, const std::string s, size_t& length){
    length = s.length();
    for (int i = 0; i < length; ++i)
    {
        arr[i] = s[i] == '+';
    }
    return arr;
}



int main()
{
    bool* stack = new bool[200];
    int test_count;
    string s;
    stringstream results;
    input_stream>>test_count;
    for (int i = 0; i < test_count; ++i)
    {
        size_t length;
        input_stream>>s;
        stack = parse_string(stack,s,length);
        results<<"Case #"<<i+1<<": "<<calculate(stack,length)<<"\n";
    }
    output_stream<<results.str();
#ifdef mDEBUG
    output_stream.close();
#endif
    return 0;
}