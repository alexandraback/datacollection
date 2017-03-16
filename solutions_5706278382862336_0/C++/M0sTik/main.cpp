#include<iostream>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<ctime>
#include<map>
#include<sstream>
#include<set>
#include<cctype>
#include<queue>
#include <memory.h>

using namespace std;

#define all(c) (c).begin(), (c).end()

template<typename T> inline string intToString(T x){ostringstream q;q << x;return q.str();}
template<typename T> inline T myPow(T x, T n, T MOD){T res = 1;while (n>0) {if (n & 1) {res = 1ll*res * x % MOD;}x = 1ll*x * x % MOD;n/=2;}return res;}
template<typename T> inline T gcd(T a, T b){a=abs(a);b=abs(b);while ((a>0) && (b>0)) {if (a>b)a%=b;else b%=a;}return a+b;}


typedef unsigned long long LLong;
typedef long double LDb;


int main()
{
#ifdef m0stik
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("river.in","r",stdin);
    //freopen("river.out","w",stdout);
#endif
    int t;
    scanf("%d\n",&t);
    for (int tt = 0; tt < t; ++tt) {
        cout << "Case #" << tt+1 << ": ";
        long long n, d;
        scanf("%lld/%lld\n",&n,&d);
        //cout << n << " " << d<< endl;
        long long q = gcd(n,d);
        n/=q;
        d/=q;
        int res = 0;
        while (d%2==0) {
            d/=2;
            res++;
        }
        if (d!=1 || res>40) {
            cout << "impossible" << endl;
            continue;
        }
        while (n > 1) {
            n/=2;
            res--;
        }
        
        cout << res << endl;
    }
    return 0;
} 