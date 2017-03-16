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
struct riadok{
    int val;
    int pos;
    riadok(int v, int p){
        val = v;
        pos = p;
    }
    riadok(){}
    friend bool operator<( const riadok & x,const riadok & y){return x.val < y.val;}
};

int lawn[101][101];
int cut[101][101];
riadok maxes[202];
int N,M;

bool solve(){
    int maxi, k = 0;
    REP (i,N){
        maxi = 1;
        REP(j,M){
            if ( lawn[i][j] > maxi) maxi = lawn[i][j];
        }
        maxes[k++] = riadok( maxi, i);
    }
    REP (i,M){
        maxi = 1;
        REP(j,N){
            if ( lawn[j][i] > maxi) maxi = lawn[j][i];
        }
        maxes[k++] = riadok( maxi, i + 200);
    }
    sort(maxes, maxes + k);
    REP(i,k){
        if (maxes[i].pos < 150){
            REP(j,M){
                if ( lawn[ maxes[i].pos ][ j ] < maxes[i].val &&  cut[ maxes[i].pos ][ j ] == 0 )return false;
                cut[ maxes[i].pos ][ j ] = 1;
            }
        }
        else{
            maxes[i].pos -= 200;
            REP(j,N){
                if ( lawn[ j ][ maxes[i].pos ] < maxes[i].val &&  cut[ j ][ maxes[i].pos ] == 0 )return false;
                cut[ j ][ maxes[i].pos ] = 1;
            }

        }
    }
    return true;


}

int main() {

    int n;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&N,&M);
        REP(j,N)REP(k,M) cut[j][k] = 0;
        REP(j,N)REP(k,M) scanf("%d",&lawn[j][k] );

        if ( solve() ) printf("Case #%d: YES\n",i);
        else printf("Case #%d: NO\n",i);
    }

  return 0;
}
