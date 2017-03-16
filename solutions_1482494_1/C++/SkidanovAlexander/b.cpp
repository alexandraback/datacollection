
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

int main( )
{
    int i, j, k, t, tt;

    scanf( "%d\n", &tt );
    for( t = 1; t <= tt; ++ t )
    {
        vector<pair<int, int> > moo;
        n = ni();
        fi(n)
        {
            int a= ni(); int b = ni();
             moo.pb(mp(a, b));
        }

        int ans = 0;
        int two = 0;
        int stars = 0;
        while(two < n)
        {
            bool ok = false;
            fi(n)
            {
                if (moo[i].second != -1 && moo[i].second <= stars)
                {
                    stars += (moo[i].first == -1 ? 1 : 2);
                    moo[i].second = moo[i].first = -1;
                    ++ two;
                    ans ++;
                    ok = true;
                    break;
                }
            }
            if (!ok)
            {
                int id = -1;
                fi(n)
                {
                    if (moo[i].first != -1 && moo[i].first <= stars && (id == -1 || moo[i].second > moo[id].second))
                    {
                        id = i;
                    }
                }
                if (id != -1)
                {
                    stars += 1;
                    moo[id].first = -1;
                    ans ++;
                    ok = true;
                }
            }
            if (!ok)
            {
                ans = -1;
                break;
            }
        }

        if (ans != -1)
            printf( "Case #%d: %d\n", t, ans );
        else
            printf( "Case #%d: Too Bad\n", t );
    }

    return 0;
}

