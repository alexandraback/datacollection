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
ll n,x;
int tab[5][5];
char s[12345];
int p[223456];
int ie[223456];
int kb[223456];
int js[10];

int prevod(int y, int nw){
  int k = y<0?-1:1;
  int k2 = nw<0?-1:1;
  y = tab[abs(y)][abs(nw)];
  return y*k*k2;
}

bool solve(){
    cin >> n >> x;
    if (x > 20){
      ll mod = x%4;
      x = 20 - (4-mod);
    }

    scanf("%s",s);
    REP(i,n){
      if(s[i]=='i')p[i] = 2;
      if(s[i]=='j')p[i] = 3;
      if(s[i]=='k')p[i] = 4;
      REP(j,x) p[i+j*n]= p[i];
    }
    int bl = 1;
    REP(i,n*x){ bl = prevod(bl,p[i]); ie[i] = (bl==2)?1:0; }
    bl = 1;
    FORD(i,n*x-1,0){  bl = prevod(p[i],bl); kb[i] = (bl==4)?1:0 ; }
    MM(js,0);
    REP(i,n*x-1){
      vi vec;
      REP(j,9){
        if (js[j])vec.PB(prevod(j-4,p[i]) );
        js[j]=0;
      }
      REP(j,vec.size())js[vec[j]+4] = 1;

      if (js[7] && kb[i+1])return true;

      if(ie[i]){
          js[5]=1;
      }

    }
    return false;
}

int main() {

  DRI(cs);
  tab[2][3] = 4;
  tab[2][4] = -3;
  tab[3][2] = -4;
  tab[3][4] = 2;
  tab[4][2] = 3;
  tab[4][3] = -2;
  REP(i,5)tab[i][i] = -1;
  REP(i,5)tab[i][1] = tab[1][i] = i;
  REP(i,5)tab[i][0] = tab[0][i] = 0;

  FOR(ic,1,cs){
    solve() ? printf("Case #%d: YES\n",ic):printf("Case #%d: NO\n",ic);
  }
  return 0;
}
