#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <queue>

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

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( ", " ); first = false; cout << * i; } printf( "\n" ); }
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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    tt = ni();

    for( t = 1; t <= tt; t++ )
    {
        int n = ni();
        bool arr[1000][1000] = {0};
        int p[1000][1000] = {0};

        fi(n)
        {
            int m = ni();

            fj(m)
            {
                int k = ni();
                arr[i][k-1] = true;
                p[i][k-1] = i;
            }
        }

        bool flag = false;

        // fi(n) {fj(n) cout << arr[i][j] << ' '; cout << endl;}
        // cout << endl;

        fk(n) fi(n) fj(n)
        {
            bool a = arr[i][j];
            bool b = (arr[i][k] && arr[k][j]);

            if((a && b) && k!=p[i][j])
            {
                flag = true;
                goto done;
            }
            
            if(!a && b) p[i][j] = k;
            arr[i][j] = a || b;
        }

        // fi(n) {fj(n) cout << arr[i][j] << ' '; cout << endl;}
        // cout << endl;

        done: printf("Case #%d: %s\n", t, flag ? "Yes" : "No");

    }

    return 0;
}
