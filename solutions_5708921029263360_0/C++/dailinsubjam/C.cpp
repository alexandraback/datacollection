#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int V = 5000;
const int E = 1e5;

const int tt = 15;
int a, b, c, K;
int ab[tt][tt], bc[tt][tt], ac[tt][tt];
pair<int, pair<int, int> > id[V];

const int INF = 1e9;

int tot;
int hd[V], th[E], nx[E], f[E];
void addedge(int x, int y, int flow)
{
    cerr << x << " " << y << " " << flow << endl;
    ++tot;
    th[tot] = y; nx[tot] = hd[x]; hd[x] = tot; f[tot] = flow;
    ++tot;
    th[tot] = x; nx[tot] = hd[y]; hd[y] = tot; f[tot] = 0;
}

int S, T;
int v[V], dd[V];
int sap(int x,int flow)
{
    if(x==T) return flow;
    int now=0;
    for(int i = hd[x]; i; i = nx[i])
    {
        if(f[i] > 0 && dd[x]==dd[th[i]]+1)
        {
            int t=sap(th[i],min(f[i],flow-now));
            f[i]-=t; f[i ^ 1]+=t;
            now+=t;
            if(now==flow) return now;
            if(dd[S]>=T) return now;
        }
    }
    --v[dd[x]];
    if(!v[dd[x]]) dd[S]=T;
    ++dd[x];
    ++v[dd[x]];
    return now;
}

int main()
{
    int TT;
    scanf("%d", &TT);
    for(int Case = 1; Case <= TT; ++Case)
    {
        scanf("%d%d%d%d", &a, &b, &c, &K);
        
        tot = 1;
        memset(hd, 0, sizeof(hd));
        
        int num = 0;
        S = 1; T = 1 + a*b + b*c + a*c + a*b*c + 1;
        num = 1;
        for(int i = 1; i <= a; ++i)
            for(int j = 1; j <= b; ++j)
            {
                ab[i][j] = ++num;
                addedge(num, T, K);
            }
        for(int i = 1; i <= b; ++i)
            for(int j = 1; j <= c; ++j)
            {
                bc[i][j] = ++num;
                addedge(num, T, K);
            }
        for(int i = 1; i <= a; ++i)
            for(int j = 1; j <= c; ++j)
            {
                ac[i][j] = ++num;
                addedge(num, T, K);
            }
        
        for(int i = 1; i <= a; ++i)
            for(int j = 1; j <= b; ++j)
                for(int k = 1; k <= c; ++k)
                {
                    ++num;
                    addedge(S, num, 3);
                    addedge(num, ab[i][j], 1);
                    addedge(num, bc[j][k], 1);
                    addedge(num, ac[i][k], 1);
                    id[num] = make_pair(i, make_pair(j, k));
                }
        
        memset(v, 0, sizeof(v));
        memset(dd, 0, sizeof(dd));
        int res = 0;
        v[S] = T;
        while(dd[S]<T)
        {
            res+=sap(S,INF);
        }
        
        printf("Case #%d: %d\n", Case, res / 3);
        for(int i = hd[S]; i; i = nx[i])
            if(f[i] == 0)
            {
                pair<int, pair<int, int> > cur = id[th[i]];
                printf("%d %d %d\n", cur.first, cur.second.first, cur.second.second);
            }
    }
    return 0;
}