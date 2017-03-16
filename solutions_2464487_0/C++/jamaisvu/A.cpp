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


int main() {
    int cs;
    lli r, t , a;

    scanf("%d",&cs);


    FOR(i,1,cs){

        scanf("%lld%lld",&r,&t);

        a =  ( r + 1) * 2 - 1;


        lli j=1;

        while(j < 1000000 ){
             if ( ( j * ( a + 2*j- 2) ) > t ) break;
            j++;
        }
        if (j == 1000000){



       int k = 1000000;
        while(1){
            if ( ( k * ( a + 2*k- 2) ) < t ) j = k;
            else break;
            k+=1000000;
        }

        while(1){
             if ( ( j * ( a + 2*j- 2) ) > t ) break;
            j++;
        }

        }

        printf("Case #%d: %lld\n",i, j-1);
    }


  return 0;
}
