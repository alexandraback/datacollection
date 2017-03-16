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
#define ff first
#define ss second
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d", &a, &b, &c);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define MM(arr, num) memset((arr), (num), sizeof((arr)))
#define DEB(x) cerr << ">>> " << (#x) << " -> " << (x) << endl;
#define DEBA(x,n) cerr << (#x) << " "; deba((x),(n));
void deba(int * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<30;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
int n;
ll mx[52];
int out[60][60];

int main() {
  // freopen("B.in","r",stdin);
    //freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
  	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
  //	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	//  freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);

  mx[0] = 0; mx[1] = 1;
  mx[2]= 1;
  FOR(i,3,52){ mx[i] = 0;  REP(j,i) mx[i]+= mx[j];  }

  DRI(cs);
  FOR(ci,1,cs){
    ll b,m;
    cin >> b >> m;
    printf("Case #%d: ",ci);

    REP(i,b)REP(j,b)out[i][j] = 0;




    if(m > mx[b]) cout << "IMPOSSIBLE" << endl;
    else{ cout << "POSSIBLE" << endl;

      REP(i,b-1)REP(j,b-1){
        if(i<j)out[i][j] = 1;
      }
      FORD( i, b-2, 0 ){
        if(m>= mx[i+1]) { out[i][b-1] = 1; m-= mx[i+1]; }
      }

      REP(i,b){ REP(j,b) cout << out[i][j]; cout << endl;  }
    }

  }
  return 0;
}
