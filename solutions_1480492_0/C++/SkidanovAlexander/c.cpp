#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;

int node(int a, int b)
{
    return a * n + b;
}

class sat
{
public:
    static const int maxn = 2000000;
    static const int maxm = 5000000;

    int n;
    int z[2 * maxn];
    int q[2 * maxn]; int qn;
    int fs[2*maxn], nx[2*maxm], to[2*maxm]; int ifs[2*maxn], inx[2*maxm], ito[2*maxm];
    int cnt;

    int inv( int a ) { if( a >= n ) return a - n; return a + n; }
    void adde( int a, int b ) { nx[cnt] = fs[a]; fs[a] = cnt; to[cnt] = b; inx[cnt] = ifs[b]; ifs[b] = cnt; ito[cnt] = a; ++ cnt; }
    void add( int a, int b ) { adde( inv( a ), b ); adde( inv( b ), a ); }
    bool solve( ) { int i; fi( n ) if( !z[i] ) if( !moo( i, -1 ) ) if( !moo( i, 1 ) ) return false; return true; }

    bool moo( int id, int val )
    {
        z[id] = val; z[inv( id )] = - val; qn = 0; q[qn ++] = ( val == 1 ) ? id : inv( id );
        int i; fi( qn )
        {
            for( int j = fs[q[i]]; j != -1; j = nx[j] ) if( z[to[j]] == -1 ) { fi( qn ) z[q[i]] = z[inv( q[i] )] = 0; return false; } else if( !z[to[j]] ) { z[to[j]] = 1; z[inv( to[j] )] = -1; q[qn ++] = to[j]; }
            for( int j = ifs[inv( q[i] )]; j != -1; j = inx[j] ) if( z[ito[j]] == 1 ) { fi( qn ) z[q[i]] = z[inv( q[i] )] = 0; return false; } else if( !z[ito[j]] ) { z[ito[j]] = -1; z[inv( ito[j] )] = 1; q[qn ++] = inv( ito[j] ); }
        }
        return true;
    }

    sat( int a ) { n = a; cnt = 0; memset( fs, -1, sizeof( fs ) ); memset( ifs, -1, sizeof( ifs ) ); memset( z, 0, sizeof( z ) ); }
};

struct car_t
{
    string line;
    int speed;
    int pos ;
};

struct interv_t
{
    double pos;
    int mode;
    int i, j;
    void swap() { if (j < i)std::swap(i, j); }
};

bool operator < (const interv_t &a, const interv_t &b)
{
    if (a.pos < b.pos - 1e-5) return true;
    if (a.pos > b.pos + 1e-5 ) return false;

    return a.mode < b.mode;
}

double inf = 1000000;
double interv(double x1, double s1, double x2, double s2)
{
    double ret = (x2 - x1) / (s1 - s2);
    if (ret < 0) ret = 0;
    if (ret > inf) assert(false);
    return ret;
}

int main( )
{
    int i, j, k, t, tt;

    scanf( "%d\n", &tt );
    for( t = 1; t <= tt; ++ t )
    {
        fprintf(stderr, "%d\n", t);
        n = ni();
        vector<car_t> cars;
        set<pair<int, int> > conf, safeC;

        fi(n)
        {
            car_t car;
            car.line = ns();
            car.speed = ni();
            car.pos = ni();
            cars.pb(car);
        }

        random_shuffle(all(cars));

        vector<interv_t> ints;

        fi(n) fj(i)
        {
            if (cars[i].speed == cars[j].speed)
            {
                if (cars[i].pos - cars[j].pos < 5 && cars[j].pos - cars[i].pos < 5)
                {
                    conf.insert(mp(i, j));
                }
            }
            else
            {
                double a = interv(cars[i].pos + 5, cars[i].speed, cars[j].pos, cars[j].speed);
                double b = interv(cars[j].pos + 5, cars[j].speed, cars[i].pos, cars[i].speed);
                if (a > b) swap(a, b);
                if (b - a > 1e-9)
                {
                    interv_t ii;
                    ii.i = i; ii.j = j;
                    ii.pos = a;
                    ii.mode = 1;
                    ii.swap();
                    ints.pb(ii);
                    ii.mode = 2;
                    ints.pb(ii);
                    ii.pos = b;
                    ii.mode = -1;
                    ii.swap();
                    ints.pb(ii);
                }
            }
        }

        interv_t iii;
        iii.mode = 3;
        iii.pos = 0;
        ints.pb(iii);

        safeC = conf;

        sort(all(ints));

        double l = 0.0; double r = inf;
        int iter; fr(iter, 45)
        {
            conf = safeC;

            sat *solver = new sat((1 + ints.size()) * n);
            bool ok = true;

            double e = (l + r) / 2;

            fi(ints.size())
            {
                int cur = i + 1;
                int prev = i;
                if (ints[i].pos > e) break;
                if (!ok) break;
                if (ints[i].mode == -1)
                {
                    conf.erase(mp(ints[i].i, ints[i].j));
                }
                if (ints[i].mode == 3)
                {
                    fj(n)
                    {
                        if (cars[j].line == "L") solver->add(node(cur, j), node(cur, j));
                        else if (cars[j].line == "R") solver->add(solver->inv(node(cur, j)), solver->inv(node(cur, j)));
                        else assert(0);
                    }
                }

                if (conf.size() > 105)
                {
                    ok = false;
                    break;
                }

                int hasC[55];
                _(hasC, 0);

                for (set<pair<int, int> >::iterator it = conf.begin(); it != conf.end(); ++ it)
                {
                    hasC[it->first] ++; hasC[it->second] ++;
                    
                    solver->add(node(cur, it->first), node(cur, it->second));
                    solver->add(solver->inv(node(cur, it->first)), solver->inv(node(cur, it->second)));
                }

                fj(n)
                {
                    if(hasC[j]) solver->add(node(cur, j), solver->inv(node(prev, j)));
                    if(hasC[j]) solver->add(node(prev, j), solver->inv(node(cur, j)));
                }

                if (ints[i].mode  == 1)
                {
                    conf.insert(mp(ints[i].i, ints[i].j));
                }
            }

            if (!solver->solve()) ok = false;

            delete solver;

            if (ok) l = e;
            else r = e;
        }

        if (r != inf)
        {
            printf( "Case #%d: %.18lf\n", t, r );
        }
        else
        {
            printf( "Case #%d: Possible\n", t );
        }
    }

    return 0;
}

