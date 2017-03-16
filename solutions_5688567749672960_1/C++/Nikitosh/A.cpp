#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

LL foo(LL k)
{
    LL k2 = k;
    int res = 0;
    vector <int> v;
    while (k2 > 0)
    {
        v.pb(k2 % 10);
        k2 /= 10;
        res++;
    }
    k2 = k;
    LL ans = 0;
    int ten = 1;
    for (int i = 0; i < res / 2; i++)
    {
        ans += ten * (v[i] + v[res - i - 1]);
        ten *= 10;
    }
    if (res % 2 == 1)
        ans += ten * v[res / 2];      
    for (int i = 0; i < res / 2; i++)
        if ((i == 0 && v[res - i - 1] != 1) || (i != 0 && v[res - i - 1] != 0))
        {
            ans++;
            break;
        }
    return ans;
}

int main() 
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        LL k = 1;
        LL N;
        scanf("%I64d", &N);
        LL ANS = 0;
        if (N % 10 == 0)
        {
            N--;
            ANS++;
        }
        while (10 * k <= N)
        {
            ANS += foo(10 * k - 1);
            k *= 10;       
            //printf("%I64d\n", ANS);
        }
        ANS += foo(N);
        printf("Case #%d: %I64d\n", t + 1, ANS);
    } 
    return 0;
}