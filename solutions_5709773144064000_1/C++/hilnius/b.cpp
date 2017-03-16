#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )

using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

int main()
{
    int i, j, k;
    int nbTestCases = 0;
    freopen ("B-large-attempt0.in","r",stdin);
    freopen ("B-large-attempt0.out","w",stdout);
    cin >> nbTestCases;

    fi(nbTestCases) {
       double c = nf(), f = nf(), x = nf();
       double currentF = 2.0;
       double nextF = currentF+f;
       double currentTime = x/currentF;
       double nextTime = c/currentF + x/nextF;
       double totalTime = x/currentF;
       double finalF = currentF;
       while (nextTime < currentTime) {
            totalTime += -x/currentF + c/currentF + x/nextF;
            currentF = nextF;
            nextF = currentF + f;
            currentTime = x/currentF;
            nextTime = c/currentF + x/nextF;
       }

        cout << "Case #" << i+1 << ": ";
        printf("%.7f", totalTime);
        cout << endl;
    }
    return 0;
}
