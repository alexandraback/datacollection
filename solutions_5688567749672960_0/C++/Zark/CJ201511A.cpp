#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <memory>

#pragma comment(linker, "/STACK:104857600,104857600")

using namespace std;

#define FILE_IO

class Solver
{
public:
	void exe();
	
private:
	void input();
	void run();
	void output();
	long long revert(int digit[], int len);
	
private:
	int caseNum, caseIndex;
	long long ten[20];
	long long n;
	long long result;
};

void Solver::exe()
{
	cin >> caseNum;
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		input();
		run();
		output();
	}
}

void Solver::input()
{
	cin >> n;
}

void Solver::run()
{
    ten[0] = 1;
    for(int i = 1; i < 20; ++i)
    {
        ten[i] = ten[i - 1] * 10;
    }
    
    long long num = n;
    int digit[100];
    int len;
	result = 0;
	while(num)
	{
	    long long tmp = num;
	    len = 0;
	    while(tmp)
	    {
	        digit[len++] = tmp % 10;
	        tmp /= 10;
	    }
	    if(len == 1)
	    {
	        result += num;
	        num = 0;
	        break;
	    }
	    
	    if(digit[0] == 0)
	    {
	        ++result;
	        --num;
	    }
	    else if(digit[len - 1] == 1 && digit[0] == 1)
	    {
	        long long newNum = revert(digit, len);
	        if(newNum < num)
	        {
	            num = newNum;
	            ++result;
	        }
	        else
	        {
	            bool isFind = false;
	            for(int i = 1; len - 1 - i > i; ++i)
	            {
	                result += digit[i] * ten[i];
	                digit[i] = 0;
	                if(digit[len - 1 - i] > 0)
	                {
	                    isFind = true;
	                    break;
	                }
	            }
	            if(isFind)
	            {
	                num = revert(digit, len);
	                ++result;
	            }
	            else
	            {
	                ++result;
	                --num;
	            }
	        }
	    }
	    else if(digit[len - 1] == 1)
	    {
	        result += digit[0] - 1;
	        num -= digit[0] - 1;
	    }
	    else
	    {
	        result += digit[0] - 1;
	        digit[0] = 1;
	        long long newNum = revert(digit, len);
	        num = newNum;
	        ++result;
	    }
	}
}

long long Solver::revert(int digit[], int len)
{
    long long newNum = 0;
    for(int i = 0; i < len; ++i)
    {
        newNum *= 10;
        newNum += digit[i];
    }
    return newNum;
}

void Solver::output()
{
    cout << "Case #" << caseIndex << ": " << result << endl;
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\A.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\A.out", "w", stdout);
#endif
	
	instance.exe();
	return 0;
}

