#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long int lli;
/*******************************************************/

int hodn[10000];

int cs;
int E, R, N, out;
int rec( int hlb, int ener ){

    if (ener > E) ener = E;

    if (hlb == N-1) return ener * hodn[hlb];
    int max = 0;
    FOR(i,0,ener){
         if ( ( out = ( rec(hlb+1, ener + R - i) + i * hodn[hlb]  ) ) > max ) max = out;
    }
    return max;

}

int main() {

    scanf("%d",&cs);


    FOR(i,1,cs){

        scanf("%d%d%d",&E,&R,&N);
        REP(j,N){
               scanf("%d", &hodn[j]);
        }



        printf("Case #%d: %d\n",i, rec(0, E));
    }


  return 0;
}
