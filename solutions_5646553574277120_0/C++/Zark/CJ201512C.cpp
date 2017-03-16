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
	void dfs(int len);
	int countBanana();
	void dfs(int money, int count);
	
private:
    int caseNum, caseIndex;
    int c, d, v;
    int coin[10];
    bool isCovered[100];
    bool choice[100];
    int unCovered[100];
    int unCoveredLen;
    int totalLen;
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
    scanf("%d%d%d", &c, &d, &v);
    for(int i = 0; i < d; ++i)
    {
        scanf("%d", coin + i);
    }
}

void Solver::run()
{
    memset(isCovered, 0, sizeof(isCovered));
    isCovered[0] = true;
    for(int i = 0; i < d; ++i)
    {
        for(int j = v; j >= 0; --j)
        {
            if(isCovered[j])
            {
                for(int k = 0, p = j + coin[i]; k < c && p <= v; ++k, p += coin[i])
                {
                    isCovered[p] = true;
                }
            }
        }
    }
    
    unCoveredLen = 0;
    for(int i = 0; i <= v; ++i)
    {
        if(!isCovered[i])
        {
            unCovered[unCoveredLen++] = i;
        }
    }
    
    memset(choice, 0, sizeof(choice));
    for(int i = 0; i < d; ++i)
    {
        choice[coin[i]] = true;
    }
    
    result = 100;
    totalLen = unCoveredLen;
    dfs(1, 0);
}

void Solver::dfs(int money, int count)
{
    if(unCoveredLen == 0)
    {
        result = min(result, count);
        return;
    }
    
    if(money > v) return;
    
    if(count >= result) return; 
    
    if(choice[money] == false)
    {
        vector<int> store;
        for(int i = totalLen - 1; i >= 0; --i) if(isCovered[unCovered[i]] == false)
        {
            if(unCovered[i] - money >= 0 && isCovered[unCovered[i] - money])
            {
                isCovered[unCovered[i]] = true;
                --unCoveredLen;
                store.push_back(unCovered[i]);
            }
        }
        if(store.size() > 0)
            dfs(money + 1, count + 1);
        for(int i = 0; i < store.size(); ++i)
        {
            isCovered[store[i]] = false;
            ++unCoveredLen;
        }
    }
    
    dfs(money + 1, count);
}

void Solver::output()
{
	printf("Case #%d: %d\n", caseIndex, result);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\C.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\C.out", "w", stdout);
#endif

	instance.exe();
	return 0;
}

