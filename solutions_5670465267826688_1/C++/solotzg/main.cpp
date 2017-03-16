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
typedef long long LL;
int ad[300];
int mmp[9][10] = {{},
    {0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}
};
struct node
{
    int n,f;
    node operator * (const node &a)
    {
        node res = node {mmp[n][a.n],f*a.f};
        if (res.n < 0) res.f = -res.f, res.n = -res.n;
        return res;
    }
    bool operator == (const node &a) const
    {
        return n == a.n && f == a.f;
    }
};
node mpow(node a, LL n)
{
    node p = a, res {1,1};
    while (n)
    {
        if (n & 1LL) res = res*p;
        p = p*p;
        n >>= 1;
    }
    return res;
}
node pow(node a, int n)
{
    node res {1,1};
    if (n <= 0) return res;
    n %= 4;
    for (LL i = 0; i< n; ++i)
        res = res * a;
    return res;
}
node num[MAXN], lbg[MAXN], rbg[MAXN];
char s[MAXN];
int solve()
{
    int n;
    LL m;
    scanf("%d%lld", &n, &m);
    scanf("%s", s+1);
    node seg {1,1};
    rbg[0] = {1,1};
    for (int i = 1; i<= n; ++i)
    {
        num[i] = node {ad[s[i]], 1};
        seg = seg * num[i];
        rbg[i] = rbg[i-1]*num[i];
    }
    lbg[n+1] = {1,1};
    for (int i = n; i>0; --i)
    {
        lbg[i] = num[i]*lbg[i+1];
    }
    node sum {1,1};
    LL df = (m*n - 4LL*n)/(4LL*n);
    int mn = m*n-4LL*n*df;
    for (int i = 1, ii; i<= mn; ++i)
    {
        ii = (i-1)%n + 1;
        sum = sum * num[ii];
        if (sum == node {2,1})
        {
            node bsum {1,1};
            for (int j = i+1, jj; j<= mn; ++j)
            {
                jj = (j-1)%n + 1;
                bsum = bsum*num[jj];
                if (bsum == node {3,1})
                {
                    if (j == mn) continue;
                    int kk = (j)%n + 1;
                    node csum = lbg[kk]*pow(seg, (mn-j-1)/n);
                    if (csum == node{4,1})
                        return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen("/home/solotzg/下载/C-large.in", "r",stdin);
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
        printf("Case #%d: ", _);
        if (solve())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
/*
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
    freopen("in.txt", "r",stdin);
    //freopen("out.txt", "w", stdout);
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
*/
