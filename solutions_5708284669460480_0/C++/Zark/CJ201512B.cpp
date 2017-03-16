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
	
private:
    static const int MAX_ROW = 20;
    static const int MAX_COL = 20;
    int caseNum, caseIndex;
    int k, l, s;
    char keys[20];
    char target[20];
    char typedS[20];
    int bananaCount;
    int totalCount;
    int maxBanana;
	double result;
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
	scanf("%d%d%d", &k, &l, &s);
	scanf("%s", keys);
	scanf("%s", target);
}

void Solver::run()
{
    bananaCount = 0;
    totalCount = 0;
    maxBanana = 0;
    dfs(0);
    result = maxBanana - ((double)bananaCount) / totalCount;
}

int Solver::countBanana()
{
    int c = 0;
    for(int i = 0; i + l <= s; ++i)
    {
        bool isFind = true;
        for(int j = 0; j < l; ++j)
        {
            if(typedS[i + j] != target[j])
            {
                isFind = false;
                break;
            }
        }
        if(isFind) ++c;
    }
    return c;
}

void Solver::dfs(int len)
{
    if(len == s)
    {
        int tmp = countBanana();
        bananaCount += tmp;
        ++totalCount;
        maxBanana = max(maxBanana, tmp);
    }
    else
    {
        for(int i = 0; i < k; ++i)
        {
            typedS[len] = keys[i];
            dfs(len + 1);
        }
    }
}

void Solver::output()
{
	printf("Case #%d: %.10lf\n", caseIndex, result);
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\B.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\B.out", "w", stdout);
#endif

	instance.exe();
	return 0;
}

