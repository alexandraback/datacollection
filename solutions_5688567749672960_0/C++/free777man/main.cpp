#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

int const MXN = 1000*1000*100;
int dist[MXN], mrev[MXN];

int getrev(int x)
{
    if(x < MXN && mrev[x] != -1)return mrev[x];

    int res = 0;
    while(x)
    {
        res = res*10 + (x%10);
        x /= 10;
    }

    if(x < MXN) mrev[x] = res;
    return res;
}

void f()
{
    REP(i,MXN)dist[i]=mrev[i]=-1;

    queue<int> q;
    dist[1] = 1;
    q.push(1);

    while(!q.empty())
    {
        int a = q.front();
        q.pop();

        int b = a + 1, d = dist[a];
        if(d>3500)break;

        if (dist[b] == -1)
        {
            dist[b] = d + 1;
            q.push(b);
        }

        b = getrev(a);
        if (b < MXN && dist[b] == -1)
        {
            dist[b] = d + 1;
            q.push(b);
        }
    }
}

void solve()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", dist[n]);
}

int main()
{
    f();
    //freopen("input.txt","r",stdin);
    freopen("A-small-attempt1.in","r",stdin);
    freopen("outputA.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    REP(i,T)printf("Case #%d: ",i+1),solve();
}
