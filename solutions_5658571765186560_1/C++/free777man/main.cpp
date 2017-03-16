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

void solve()
{
    int x,r,c;
    scanf("%d %d %d",&x,&r,&c);
    if(r>c)swap(r,c);

    if((r*c)%x!=0)
    {
        printf("RICHARD\n");
        return;
    }

    if(x<3)
    {
        printf("GABRIEL\n");
        return;
    }

    if(x==3)
    {
        if(r==1)printf("RICHARD\n");else printf("GABRIEL\n");
        return;
    }

    if (x==4)
    {
        if(r<3)printf("RICHARD\n");else printf("GABRIEL\n");
        return;
    }

    if (x==5)
    {
        if(r<4)printf("RICHARD\n");else printf("GABRIEL\n");
        return;
    }

    if (x==6)
    {
        if(r<4)printf("RICHARD\n");else printf("GABRIEL\n"); // ?
        return;
    }

    printf("RICHARD\n");
}

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("outputD.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    REP(i,T)printf("Case #%d: ",i+1),solve();
}
