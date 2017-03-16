#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

#define fo(a,b,c) for(a = (b); a < (c); a++)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define fn fr
#define forit(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fill(a,b) memset(a, b, sizeof(a))

using namespace std;

int ni() { int x; scanf( "%d", &x ); return x; }
double nf() { double x; scanf( "%lf", &x ); return x; }
char sbuf[10000]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long x; scanf( "%lld", &x ); return x; }

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
template <class T> T abs(T x) { return x < 0 ? -x : x; }
template <class T> T sqr(T x) { return x*x; }
template <class T> inline string toStr(const T& a) { ostringstream os(""); os << a; return os.str(); }

const long double PI = acos(-1.0);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;
typedef set<int> si;

// #define dbg(x) cout << (#x) << "= " << (x) << endl;

int main()
{
    int i, j, k, t, tt;
    int n;
    long s[20];
    si q;
    vi v1,v2;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    tt = ni();
    for( t = 1; t <= tt; t++ )
    {
        printf( "Case #%d:\n", t );

        n = ni();
        fi(n) cin >> s[i];
        long p = 1 << n;
        q.clear();
        v1.clear();
        v2.clear();
        ull sum;
        long m1, m2;

        bool flag = false;

        for(long x = 1; x < p; x++)
        {
            sum = 0;
            for(long y = 0; y < n; y++)
            {
                if(x & 1 << y)
                {
                    sum += s[y];
                        //cout << s[y] << ' ';
                }
            }
                //cout << " = " << sum << endl;
                
            
            if(q.count(sum) != 0) 
            {
                m2 = x;
                flag = true;
                break;
            }

            q.insert(sum);
        }

        if(flag)
        {
            ull target = sum;

            for(long z = 1; z < m2; z++)
            {
                ull sum = 0;
                for(long y = 0; y < n; y++)
                {
                    if(z & 1 << y)
                    {
                        sum += s[y];
                    }
                }

                if (sum == target)
                {
                    m1 = z;
                    break;
                }
            }

            for(long y = 0; y < n; y++)
            {
                if(m1 & 1 << y)
                    v1.pb(s[y]);

                if(m2 & 1 << y)
                    v2.pb(s[y]);
            }

            out(all(v1));
            out(all(v2));
    
        }

        else cout << "Impossible\n";
    }

    return 0;
}
