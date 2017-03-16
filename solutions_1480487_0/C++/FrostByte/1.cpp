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

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout.precision(6); cout << fixed << * i; } printf( "\n" ); }
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

int n, s[201] = {0};
vi v;
vector<double> a;

int check(double, int, int);
void do_thing(int, int);

int main()
{
    int i, j, k, t, tt;
    int x;
    double y;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    tt = ni();

    for( t = 1; t <= tt; t++ )
    {
        x = 0;
        v.clear();
        a.clear();

        n = ni();
        fi(n) 
        {
            s[i] = ni();
            v.pb(s[i]);
            x += s[i];
        }

        //sort(all(v));

        fi(n) do_thing(i, x);
        printf( "Case #%d: ", t );
        out(all(a));

        //cout << x << endl;

        //cout.precision(6)
        //cout << fixed << y << endl;

    }

    return 0;
}

//int check(double m, int pos)
void do_thing(int i, int y)
{
    double l = 0, h = 2*y;
    double e = 1e-7;
    double m, x;

    while(l <= h && h - l > e)
    {
        m = (l+h)/2;
        //cout << " > " << m << endl;

        x = check(s[i]+m, i, y);

        if(x == 0) 
            break;

        else if(x < 0)
            l = m;

        else 
            h = m;
    }

    a.pb((m)*100/y);
    //cout << "done" << endl;
}

int check(double m, int pos, int x)
{
    int i;
    float f = x;
    fi(n)
    {
        if(s[i] < m)
            f -= (m - s[i]);

        if(f<0) return 1;
    }

    if(f>0) return -1;

    return 0;
}
