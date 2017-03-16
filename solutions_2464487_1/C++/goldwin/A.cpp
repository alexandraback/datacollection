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
/*
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
}*/

double findProduct(ll ans, ll a)
{
    return (double)(a-2LL)*(double)ans + (double)2LL * ((double)ans * (double)ans);
}

bool test(ll ans, ll a)
{
    return (double)(2LL * (double)ans * (double)ans - (double)c) + (double)(a-2LL) * (double)ans <= 0;
}

void solve(int ca)
{
    ll a = (r+1)*(r+1) - (r * r);
    ll left = 1,right = (1000000000),mid,ans = 0;
    double res;
    while(left <= right)
    {
        mid = (left + right) / 2;
        res = findProduct(mid,a);
        //cerr << left << " " << right << " " << res << " " << c << " " << (res < c) << endl;
        if(test(mid,a))
        {
            ans = max(ans,mid);
            left = mid+1;
        }
        else 
        {
            right = mid-1;
        }
    }
    printf("Case #%d: %I64d\n",ca,ans);
}

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small.out","w",stdout);    
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
       scanf("%I64d %I64d",&r,&c);
       solve(ca);
    }
    return 0;
}
