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
lli fair[1000000];
int n[15];
lli st, fi;

bool isPal(lli num){
    int i = 0;
    while( num ){
            n[i++] = num % 10;
            num /= 10;
    }
    int end = i >> 1;
    i--;
    REP(j,end){
        if ( n[j]!= n[i-j]) return false;
    }
    return true;

}

void getFair(){
    int k = 0;
    lli li;
    FOR(i,1,2002000){
        if ( isPal(i) ){
           li = i * ( lli ) i;
           if ( isPal(li) ) fair[k++] = li;
        }
    }
    fair[k] = 2e14;
    //REP( i , k ) cout << fair[i] << endl;

}
int solve(){
    int ret = 0, i = 0;
    while( fair[i] <= fi ){
        if (fair[i] >= st) ret++;
        i++;
    }

    return ret;

}

int main() {

    int n;
    getFair();
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%lld%lld",&st,&fi);
        printf("Case #%d: %d\n",i, solve() );
    }


    return 0;
}
