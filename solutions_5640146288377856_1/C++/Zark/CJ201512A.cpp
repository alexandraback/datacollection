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
	int dp(int len, int st, int ed);
	int dpN(int len);
	int dpG(int code);
	
private:
    static const int MAX_ROW = 20;
    static const int MAX_COL = 20;
    int caseNum, caseIndex;
    int rowNum, colNum, length;
	int dpBuffer[MAX_COL][MAX_COL][MAX_COL];
	int dpBuf[MAX_COL];
	int dpGlobal[1 << MAX_COL];
	int result;
};

void Solver::exe()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		input();
		run();
		output();
	}
}

void Solver::input()
{
	scanf("%d%d%d", &rowNum, &colNum, &length);
}

void Solver::run()
{
    memset(dpBuffer, 0xff, sizeof(dpBuffer));
    memset(dpBuf, 0xff, sizeof(dpBuf));
    memset(dpGlobal, 0xff, sizeof(dpGlobal));
    result = 0;
    result += dpN(colNum) * (rowNum - 1);
    result += dpG(0);
}

int Solver::dp(int len, int st, int ed)
{
    if(dpBuffer[len][st][ed] >= 0) return dpBuffer[len][st][ed];
    
    if(ed - st + 1 == length) return dpBuffer[len][st][ed] = 0;
    
    int count = -1;
    for(int i = 0; i < st; ++i)
    {
        int tmpMax = 0;
        if(ed - i + 1 <= length)
        {
            int tmp = 1 + dp(len, i, ed) + st - i - 1;
            tmpMax = max(tmpMax, tmp);
        }
        
        if(len - i - 1 >= length)
        {
            int tmp = 1 + dp(len - i - 1, st - i - 1, ed - i - 1);
            tmpMax = max(tmpMax, tmp);
        }
        
        if(count < 0 || count > tmpMax)
        {
            count = tmpMax;
        }
    }
    
    for(int i = ed + 1; i < len; ++i)
    {
        int tmpMax = 0;
        if(i - st + 1 <= length)
        {
            int tmp = 1 + dp(len, st, i) + i - ed - 1;
            tmpMax = max(tmpMax, tmp);
        }
        
        if(i >= length)
        {
            int tmp = 1 + dp(i, st, ed);
            tmpMax = max(tmpMax, tmp);
        }
        
        if(count < 0 || count > tmpMax)
        {
            count = tmpMax;
        }
    }
    
    return dpBuffer[len][st][ed] = count;
}

int Solver::dpN(int len)
{
    if(dpBuf[len] >= 0) return dpBuf[len];
    if(len < length) return dpBuf[len] = 0;
    
    int count = -1;
    for(int i = 0; i < len; ++i)
    {
        int tmp = 1 + dpN(i) + dpN(len - i - 1);
        if(count < 0 || count < tmp)
        {
            count = tmp;
        }
    }
    return dpBuf[len] = count;
}

int Solver::dpG(int code)
{
    if(dpGlobal[code] >= 0) return dpGlobal[code];
    
    int last = 0;
    int posCount = 0;
    for(int i = 0; i < colNum; ++i)
    {
        if((1 << i) & code)
        {
            if(i - last >= length)
            {
                ++posCount;
            }
            last = i + 1;
        }
    }
    if(colNum - last >= length) ++posCount;
    if(posCount == 0)
    {
        return dpGlobal[code] = 1000;
    }
    
    int count = -1;
    last = 0;
    for(int i = 0; i < colNum; ++i)
    {
        if((1 << i) & code)
        {
            last = i + 1;
        }
        else
        {
            int tmpMax = -1;
            int tmp = dpG(code | (1 << i));
            if(tmp != 1000)
            {
                tmpMax = tmp + 1;
            }
            int ed = i + 1;
            for(; ed < colNum; ++ed)
            {
                if((1 << ed) & code)
                {
                    break;
                }
            }
            tmp = 1 + dp(ed - last, i - last, i - last);
            
            if(tmpMax < 0 || tmpMax < tmp)
            {
                tmpMax = tmp;
            }
            
            if(count < 0 || count > tmpMax)
            {
                count = tmpMax;
            }
        }
    }
    
    return dpGlobal[code] = count;
}

void Solver::output()
{
	printf("Case #%d: %d\n", caseIndex, result);
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

