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

int main() 
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int n;
        scanf("%d", &n);
        vector <pair <int, int> > v;
        for (int i = 0; i < n; i++)
        {
            int d, h, m;
            scanf("%d%d%d", &d, &h, &m);
            for (int j = 0; j < h; j++)
                v.push_back(mp(m + j, d));
        }
        assert(v.size() <= 2);
        printf("Case #%d: ", t + 1);
        if (v.size() == 1)
        {
            puts("0");
            continue;
        }
        sort(v.begin(), v.end());
        //printf("%d %d\n", v[0].first, v[1].first);
        if (v[0].first == v[1].first)
            puts("0");
        else
        {
            LL max1 = (720 - v[0].second) * 1ll * v[0].first;
            LL min1 = (360 - v[1].second) * 1ll * v[1].first;
            if (min1 < max1)
                puts("0");
            else
                puts("1");
        }
    } 
    return 0;
}