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

double binary_search(double d, double v, double a)
{
    double l = 0;
    double h, m;

    if(v!=0) h = d/v;
    else h = d/a;

    double e = 1e-7;

int ctr = 0;

    while(ctr++ < 50 && l<h && h-l > e)
    {
        m = (h+l)/2;
        double s = ( v * m ) + ( 0.5 * a * m * m);
        if(s > d)
            h = m;
        else 
            l = m;
    }

    return l;
}

int main()
{
    int i, j, k, t1, tt;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    tt = ni();

    for( t1 = 1; t1 <= tt; t1++ )
    {
        double d = nf();
        int n = ni();
        int A = ni();

        double x[2000] = {0};
        double t[2000] = {0};
        double a[250] = {0};

        fi(n) { t[i] = nf(); x[i] = nf(); }
        fi(A) a[i] = nf();

        // v*t + 0.5*a*t^2
        double cal;
        printf("Case #%d:\n", t1);
        fj(A) 
        {
            bool flag = false;
            double pos = 0;
            double v = 0;
            double time = 0;
            cal = 0;
            fi(n) 
            {
                // Go to x at highest speed possible
                // If blocked, make your speed reach his

                double s = ( v * t[i] ) + ( 0.5 * a[j] * t[i] * t[i]);

                double oldpos = pos;
                pos = min(x[i], s+pos);

                // Check if pos > D

                if(pos > d) 
                {  
                    double v2 = (x[i] - x[i-1]) / (t[i] - t[i-1]);
                    double acc = i==0 ? a[j] : 0;
                    cal = binary_search(d-oldpos, v2, acc);
                    flag = true;
                    break;
                }

                double u = v;
                if ( pos < x[i]) v =  v + a[j] * t[i]; 
                else if(i!=n-1) v = (x[i+1] - x[i]) / (t[i+1] - t[i]);

                // If we overshoot
                s = ( v * t[i] ) + ( 0.5 * a[j] * t[i] * t[i]);
                if(s>pos && i!=n-1) { cal = t[i] + binary_search(d-oldpos, u, a[j]); flag = true; break; }


                // if(v>u+a[j]*t[i]) v = u+a[j]*t[i];

                
                // if(i != n-1) v = min(v + a[j] * t[i], (x[i+1] - x[i]) / (t[i+1] - t[i]));

                time += t[i];
            }
            double extra = 0.0;
            if(flag) extra = cal;
            else if(pos<d)
            {
                extra = binary_search(d-pos, v, a[j]);
            }
            printf("%.7f\n", time + extra);
        }

    }

    return 0;
}
