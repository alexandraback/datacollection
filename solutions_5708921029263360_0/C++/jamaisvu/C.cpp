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

int used[5][15][15];

int out[10000][3];
int cnt;

ii a[150];

ii in[3];

int main() {
  // freopen("C.in","r",stdin);
    freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
  //	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
  //	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	//  freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);

  DRI(cs);
  FOR(ci,1,cs){

    REP(i,3){ DRI(x); in[i] = MP(x, i); };
    DRI(K);
    sort(in,in+3);
    int o[3];
    REP(i,3)REP(j,3) if(in[j].ss == i) o[i] = j;

    cnt = 0;


    REP(k,(min(K,in[2].ff) ) ){
            int bb = k;
            REP(i,in[0].ff){
              int b = (k + 1 + i)%in[1].ff;


              int t = cnt;

              REP(j, (min(in[1].ff,in[2].ff))  ){
                    //DEB(0)
                    //int t2 = cnt
                    int pos = (b+j)%in[1].ff;


                    out[t+pos][0] = (bb+i)%in[2].ff +1;
                    out[t+pos][1] = pos+1;
                    out[t+pos][2] = j+1;
                    cnt++;
            }
      }

    }



    printf("Case #%d: %d\n",ci, cnt);
    REP(i,cnt){
      printf("%d %d %d\n", out[i][ o[0] ], out[i][ o[1] ], out[i][ o[2] ] );
    }

  }
  return 0;
}
