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


void f()
{

}

void solve()
{
    int n;
    scanf("%d", &n);

    vector<pair<int,int>> hs;
    REP(i,n)
    {
        int d,h,m;
        scanf("%d %d %d",&d, &h,&m);
        REP(j,h)hs.push_back(make_pair(d, m++));
    }

    sort(ALL(hs));

    if(SZ(hs)>2)
    {
        printf("-1\n");
        return;
    }

    if(SZ(hs)<2 || (hs[0].second == hs[1].second))
    {
        printf("0\n");
        return;
    }

    ll d1= hs[0].first, d2 = hs[1].first, v1 = hs[0].second, v2 = hs[1].second, res = 2;
    if(v1<v2)swap(v1,v2), swap(d1,d2);

    if (d1 < d2)
    {
        int c = 0;
        REP(k,10)if(360*k+d1-d2>=0)if((360*k+d1-d2)*360*v1*v2 <= v1*(360-d1)*360*(v1-v2))++c;
        res = min(c,2);
    }
    else if ((360-d1)*v1 <= v2*(360-d2))
    {
        res = 0;
    }
    else
    {
        int c = 0;
        REP(k,10)if(360*k+d1-d2>=0)if((360*k+d1-d2)*360*v1*v2 <= v1*(360-d1)*360*(v1-v2))++c;
        res = min(c-1,2);
        if(res<0)res=0;
    }

    if(res==2)res=1;
    printf("%d\n", res);
}

int main()
{
    f();
    //freopen("input.txt","r",stdin);
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("outputC.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    REP(i,T)printf("Case #%d: ",i+1),solve();
}
