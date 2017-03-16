#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

typedef long long ll;
ll r,c;

void solve(int ca)
{
    ll cnt = 0;
    while(true)
    {
        int r1 = r+1;
        int r2 = r;
        int a = r1*r1 - r2*r2;
        //cerr << a << endl;
        if(a > c) break;
        c -= a;
        cnt++;
        r+=2;
    }
    printf("Case #%d: %I64d\n",ca,cnt);
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
       scanf("%I64d %I64d",&r,&c);
       solve(ca);
    }
    return 0;
}
