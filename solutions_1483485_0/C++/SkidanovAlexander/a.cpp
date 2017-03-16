
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
int ni() { int a; scanf( "%d\n", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { gets(sbuf); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;

char q[300];

char a[] = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
char b[] = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
int main( )
{
    int i, j, k;

/*    char c;
    int cnt = 0;
    while (scanf("%c", &c)!= EOF)    
    {
        if (c >= 'a'&&c <= 'z')
        {
            printf("%c", c);
//            if (!q[c]) ++ cnt;
//            q[c] = 1;
        }
    fi(300) if (i >= 'a' && i <= 'z' && !q[i])
    {
        printf("%c ", i);
    }
    printf("%d\n", cnt);*/

    for (i = 0; a[i]; ++ i) q[a[i]] = b[i];
    q['z'] = 'q';
    q['q'] = 'z';

    fi(300) if (i >= 'a' && i <= 'z' && !q[i]) printf("MOO! %c\n", i);

    n = ni();
    fi(n)
    {
        string s = ns();
        fj(s.size()) if (s[j] >= 'a' && s[j] <= 'z') s[j] = q[s[j]];
        printf("Case #%d: %s\n", i + 1, s.c_str());
    }

    return 0;
}

