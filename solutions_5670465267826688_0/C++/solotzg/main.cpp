#include <cstdio>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstring>
#include <array>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int MAXN = 10005;
int ad[300];
int mmp[9][10] = {{},
    {0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}
};
int dp[MAXN][4], num[MAXN];
char s[MAXN];
map<int,int> pp;
map<int,int>::iterator it;
int solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 0; i< n; ++i)
    {
        num[i] = ad[s[i]];
    }
    for (int i = 1; i< m; ++i)
    {
        memcpy(num+i*n, num, 4*n);
    }
    n = n*m;
    int ok = 0;
    for (int i = 0, as = 1, f = 1; i< n; ++i)
    {
        as = mmp[as][num[i]];
        if (as < 0) f = 1-f, as= -as;
        if (as==2 && f==1)
        {
            for (int j = i+1, bs=1, bf=1; j< n; ++j)
            {
                bs = mmp[bs][num[j]];
                if (bs < 0) bf = 1-bf, bs=-bs;
                if (bs==3 && bf==1)
                {
                    if ((it=pp.find(j+1)) != pp.end())
                    {
                        if (it->second) return 1;
                    }
                    else
                    {
                        int k = j+1, cs=1, cf=1;
                        for (; k < n; ++k)
                        {
                            cs = mmp[cs][num[k]];
                            if (cs < 0) cf = 1-cf, cs=-cs;
                        }
                        pp[j+1] = cs==4&&cf==1;
                        if (cs==4&&cf==1)
                            return 1;
                    }

                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen("/home/solotzg/下载/C-small-attempt1.in", "r",stdin);
    //freopen("in.txt", "r",stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    ad['1']=1;
    ad['i']=2;
    ad['j']=3;
    ad['k']=4;
    for (int _ = 1; _<= t; ++_)
    {
        pp.clear();
        printf("Case #%d: ", _);
        if (solve())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
