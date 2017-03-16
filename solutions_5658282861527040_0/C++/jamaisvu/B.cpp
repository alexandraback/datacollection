#include <algorithm>
#include <cmath>
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
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define RI(a) scanf("%lld", &a);
#define RII(a, b) scanf("%d %d", &a, &b);

#define MM(arr, num) memset((arr), (num), sizeof((arr)))

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
ll cs, N,A,B,K;

ll solve(){
  if( K >= A || K >= B) return A * B;

  ll all = A*B;
  A--;B--;K--;

  int que = (A-K)*(B-K);



}


int main() {

    	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
    //  freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);


    scanf("%lld",&cs);
    FOR(ii,1,cs){


          RI(A);
          RI(B);
          RI(K);

        ll x = 0;
        REP(i,A)REP(j,B){
            if( (i&j) < K)x++;
        }

        printf("Case #%d: %lld\n",ii, x );
        //printf("Case #%d: %lld\n",ii, solve() );
    }


    return 0;
}
