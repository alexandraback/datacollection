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
int l, r;

int moo[2000005];

int rec(int a)
{
    int c = a;
    int mod = 1;
    int b = a;
    int iter  =0;
    while(b >= 10)
    {
        mod *= 10;
        b /= 10;
        ++ iter;
    }

    int ret =0;
    int i; fi(iter)
    {
        int q = a % 10;
        a /= 10;
        a += q * mod;
        if (q != 0 && a >= l && a <= r && a < c && moo[a] != c)
        {
            ++ ret;
            moo[a] = c;
        }
    }
    return ret;
}

int main( )
{
    int i, j, k;

    int t= ni();
    int tt; fr(tt, t){
        _(moo, 0);
        int ans = 0;
        l = ni();
        r = ni();
        for (int i = l; i <= r; ++ i)
        {
            ans += rec(i);
        }
        printf("Case #%d: %d\n", tt + 1, ans);
    }

    return 0;
}

