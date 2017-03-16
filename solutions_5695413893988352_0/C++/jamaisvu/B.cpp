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

typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
int n;

ll dp[25][10][10];
ii tb[25][10][10];
string s1,s2; int len;
ll INF;

ll pw(ll d, int l ){REP(i,l)d*=10; return d;}


void solve(){

  REP(i,25)REP(j,10)REP(k,10)dp[i][j][k] = INF;

  REP(i,10)REP(j,10){
    int pos = 0;

    if(s1[pos] == '?'  && s2[pos] == '?');
    else if ( (s1[pos]-'0') == i && s2[pos] == '?');
    else if (  s1[pos] == '?' && (s2[pos]-'0') == j );
    else if (  (s1[pos]-'0') == i  && (s2[pos]-'0') == j );
    else continue;

    //cout << s1[pos] << " " << s2[pos] << endl;
    //cout << i << " " << j << endl;

    dp[0][i][j] = pw(i, len-1) - pw(j, len-1);


  }

  FOR(pos,1,len-1){
    REP(i2,10)REP(j2,10){

      REP(i,10)REP(j,10){

          if(s1[pos] == '?'  && s2[pos] == '?');
          else if ( (s1[pos]-'0') == i && s2[pos] == '?');
          else if (  s1[pos] == '?' && (s2[pos]-'0') == j );
          else if (  (s1[pos]-'0') == i  && (s2[pos]-'0') == j );
          else continue;



         // REP(i2,10)REP(j2,10){

            ll diff = pw(i, len-pos-1) - pw(j, len-pos-1);

            if (dp[pos-1][i2][j2] == INF) continue;


            //DEB(i)
            //DEB(j)
            //DEB(dp[pos-1][i2][j2])
            ll sumd = diff + dp[pos-1][i2][j2];
           // DEB(sumd)

           // if(sumd == 5) {DEB(i)DEB(j)}

            if ( abs(sumd) < abs(dp[pos][i][j])  ) {
                dp[pos][i][j] = sumd;
                //DEB(sumd)

                tb[pos][i][j] = MP(i2,j2);
            }
            else if ( abs(sumd) == abs(dp[pos][i][j])  ){

                  ll vu = 0, vd=0;
                  ii best = MP(i2,j2);
                  ll r = 1;
                  FORD(y,pos-1,0){
                    vu+= best.ff * r;
                    vd+= best.ss *r;
                    r*=10;
                    best = tb[y][best.ff][best.ss];
                  }

                  ll vuo = 0, vdo = 0;
                   best = tb[pos][i][j];
                  r = 1;
                  FORD(y,pos-1,0){
                    vuo+= best.ff * r;
                    vdo+= best.ss *r;
                    r*=10;
                    best = tb[y][best.ff][best.ss];
                  }

                  if (vu < vuo || ((vu == vuo && vd < vdo))  ){
                      tb[pos][i][j] = MP(i2,j2);
                  }

            }

           // if(pos== len-1) DEB(dp[len-1][i][j])

          }
  }

  }

  ll mn = INF;
  ii best;
  REP(i,10)REP(j,10){
  //DEB(dp[len-1][i][j])

    if (abs(dp[len-1][i][j]) < abs(mn)){
      //DEB(0)
      mn = dp[len-1][i][j];
      best = MP(i,j);
    }
  }
  vi vu, vd;
  FORD(i,len-1,0){
    vu.PB( best.ff);
    vd.PB( best.ss);
    best = tb[i][best.ff][best.ss];
  }

  FORD(i,len-1,0)cout<<vu[i];
  cout << " ";
  FORD(i,len-1,0)cout<<vd[i];



}

bool ok(int i2, int j2){

    FORD(k,len-1,0){
      if( s1[k] == '?' || s1[k]-'0' == i2% 10  ); else return false;
      if( s2[k] == '?' || s2[k]-'0' == j2% 10  ); else return false;
      i2/=10;
      j2/=10;
    }
    return true;
}

void bf(){

  int mn = 1000000;
  ii best;
  REP(i,999)REP(j,999){
    if (ok(i,j) ){
        if( abs(i-j)  < abs(mn)  ){
          mn = i-j;
          best = MP(i,j);
        }
    }

  }
  if (best.ff < 100 && len ==3) cout << "0";
  if (best.ff < 10 && len ==2) cout << "0";
  cout << best.ff << " ";
  if (best.ss < 100&& len ==3) cout << "0";
  if (best.ss < 10 && len ==2 ) cout << "0";
  cout << best.ss;

}



int main() {
  // freopen("B.in","r",stdin);
   // freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
  	//freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
  	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	//  freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);

  INF = pw(1,17);


  DRI(cs);
  FOR(ci,1,cs){



    cin >> s1 >> s2; len = s1.size();

    //rec(0,0, 0, 0 );


    printf("Case #%d: ",ci);
    //bf();
    solve();
    printf("\n");

  }
  return 0;
}
