#include <assert.h>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h> 
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int temp;
int count_n(int a, int target, int &temp)
{
    int count = 0;
    while (a <= target)
    {
        count++;
        a = 2*a - 1;
        temp = a;
    }
    return count;
}
//#define inFile cin
//#define  outFile cout

int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("A-small-attempt5.in");
    outFile.open("A-small-attempt5.out");
    int motes_size[105];
    int num_cases;
    inFile>>num_cases;
    for (int i = 1; i < num_cases + 1; i++ )
    {
        int count = 0;
        int A_size;
        int motes_num;
        inFile>>A_size>>motes_num;
        for (int j = 0; j != motes_num; j++)
        {
            inFile>>motes_size[j];
        }
        if (A_size == 1)
        {
            outFile<<"Case #"<<i<<": "<<motes_num<<'\n';
            continue;
        }
        sort(motes_size, motes_size + motes_num);
        for (int j = 0; j != motes_num; j++)
        {
            if (motes_size[j] < A_size)
            {
                A_size += motes_size[j];
            }
            else
            {
                if(count_n(A_size, motes_size[j], temp) < motes_num - j)
                {
                    count += count_n(A_size, motes_size[j], temp);
                    A_size = temp;
                    j--;
                }
                else
                {    
                    count += motes_num - j;
                    break;
                }
            }
            if (A_size > 100)
            {
                break;
            }
        }
        if (count > motes_num || A_size == 1)
        {
            count = motes_num;
        }
        outFile<<"Case #"<<i<<": "<<count<<'\n';
    }
    return 0;
}


