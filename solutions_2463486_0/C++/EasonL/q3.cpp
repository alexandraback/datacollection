#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;

int beg, end;

bool check_hui(int number)
{
    char sznum[100];
    sprintf(sznum, "%d", number);
    int len = strlen(sznum);

    for(int i = 0; i < len / 2; ++i)
    {
        if(sznum[i] != sznum[len - i - 1])
            return false;
    }

    return true;
}

int calc()
{
    int sum = 0;

    for(int temp = beg; temp <= end; ++temp)
    {
        float sq = sqrt(temp);
        if(sq - (int)sq != 0 || !check_hui(temp))
            continue;

        if(check_hui(sq))
        {    
            sum++;
        }
    }


    return sum;
}

int main()
{


    int test_case;
    cin>>test_case;
    for(int i = 0; i < test_case; ++i)
    {
        cin>>beg>>end;
        cout<<"Case #"<<i+1<<": "<<calc()<<endl;
    }


    return 0;
}
