#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
//#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

ll gcd(ll a, ll b)
{
    while(a && b)
    {
        a %= b;
        swap(a, b);
    }
    return a+b;
}

void test(int T)
{
    ll p,q;
    scanf("%lld/%lld", &p, &q);
    ll x = gcd(p, q);
    p /= x;
    q /= x;
    int answ = 0;
    while(p < q)
    {
        p*=2;
        ++answ;
    }
    if(q != (q & -q))
    {
        printf("impossible\n");
        return;
    }
    printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/a.in", "r", stdin);
    freopen("/Users/olpet/Downloads/a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}