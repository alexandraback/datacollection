//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<list>
//#include<ext/rope>
#define PB push_back
#define MP make_pair
#define PF push_front
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef const long long cll;

const int N = 100005;

ll mul_mod(ll a, ll b, cll &n)
{
    ll ans(0), tmp((a % n + n) % n);
    b = (b % n + n) % n; //b%=n;
    while(b)
    {
        if(b & 1)   if((ans += tmp) >= n) ans -= n;
        if((tmp <<= 1) >= n) tmp -= n;
        b >>= 1;
    }
    return ans;
}

ll pow_mod(ll a, ll n, ll p)
{
    ll ans(1), d(a % p);
    while(n)
    {
        if(n & 1) ans = mul_mod(ans, d, p); //ans=((long long)ans*d)%p;
        d = mul_mod(d, d, p); //d=((long long)d*d)%p;
        n >>= 1;
    }
    return ans;
}

bool miller_rabin(cll &a, cll &n, ll t, cll &u) //2^t*u =n-1
{
    ll x = pow_mod(a, u, n);
    if(x == 1) return true;
    while(t--)
    {
        if(x == n - 1)return true;
        x = mul_mod(x, x, n);
    }
    return false;
}

bool isprime(cll &n, int count = 5)
{
    ll r = 0, s = n - 1;
    while(!(s & 1))
    {
        s >>= 1;
        ++r;
    }
    if(n == 1 || (n != 2 && !(n % 2)) || (n != 3 && !(n % 3)) || (n != 5 && !(n % 5)) || (n != 7 && !(n % 7)))return false;
    while(count--)
        if(!miller_rabin(rand() % (n - 1) + 1, n, r, s)) return false;
    return true;
}

ll gcd(ll a, ll b)
{
    if(a > b) swap(a, b);
    while(a)
    {
        ll t = a;
        a = b % a;
        b = t;
    }
    return b;
}

ll rho(cll &n)
{
    for(ll x, y, d, c = -1;; --c)
        for(y = x = 2;;)
        {
            x = mul_mod(x, x, n);
            x = (x - c) % n;
            y = mul_mod(y, y, n);
            y = (y - c) % n;
            y = mul_mod(y, y, n);
            y = (y - c) % n;
            d = gcd(y - x + n, n);
            if(d == n) break;
            else if(d > 1) return d;
        }
}
ll a[20], b[20];

int chai(ll n)
{
    int len(0);
    while(n)
    {
        a[len++] = n & 1;
        n >>= 1;
    }
    return len;
}

ll he(int len, ll base)
{
    ll res(0);
    while(len)
        res = res * base + a[--len];
    return res;
}

void print(int len)
{
    while(len) printf("%lld", a[--len]);
}

int main()
{
#ifdef PKWV
    freopen("in.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
#endif // PKWV
    int LEN(16), TOT(50);
    int st = (1 << LEN - 1) + 1;
    int cnt(0);
    printf("Case #1:\n");
    while(cnt < TOT)
    {
        int len = chai(st);
        bool fd(true);
        for(ll base = 2; base <= 10; base++)
        {
            b[base] = he(len, base);
//            printf("  %I64d",b[base]);
            if(isprime(b[base]))
            {
                fd = false;
                break;
            }
        }
//        printf("\n");
        if(fd)
        {
            ++cnt;
            print(len);
            for(int i = 2; i <= 10; i++) printf(" %lld", rho(b[i]));
            printf("\n");
        }
//        print(len);
//        printf("\n");
        st += 2;
    }
    return 0;
}

