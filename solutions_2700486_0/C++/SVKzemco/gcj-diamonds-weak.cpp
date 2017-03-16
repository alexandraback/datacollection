#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef long double LD;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-10
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)

#define MP make_pair
#define PB push_back

int N,X,Y;

double DP[3000][3000];

int spustame,mx;

double kolko(int spravna, int druha){
  cout << "hladam: " << spravna << ", " << druha << endl;
  if (spravna == 0 && druha == 0) return 1.0;
  //cout << "!" << endl;
  if (DP[spravna][druha] > -0.5) return DP[spravna][druha];

  //printf("trt res\n");

  double res = 0.0;
  if (spravna == 0) res = 0.5*kolko(spravna, druha-1);
  if (druha == 0) res = 0.5*kolko(spravna -1, druha);

  //printf("res %lf\n", res);

  if (spravna > 0 && druha > 0){
    res = 0.5*kolko(spravna-1,druha) + 0.5*kolko(spravna,druha-1);
  }

  DP[spravna][druha] = res;
  return res;
}

void solve(int tt){
  scanf("%d %d %d ", &N, &X, &Y);

  X = abs(X);
  Y = abs(Y);

  int plnych_urovni = 1;
  int ostalo = N-1;
  int treba = 5;

  while(ostalo >= treba){
    ostalo -= treba;
    plnych_urovni++;
    treba += 4;
  }

  int uroven = (X+Y)/2 + 1;
  if (uroven <= plnych_urovni){
    printf("Case #%d: 1.0\n", tt+1);
    return;
  }
  if (uroven > plnych_urovni+1){
    printf("Case #%d: 0.0\n", tt+1);
    return;
  }

  double res = 0;
  double chunk = 1.0/(1<<ostalo);
  mx = uroven*2 - 2;

//  cout << ostalo << endl;

  FOR(i,(1<<ostalo)){
    int spravna = 0;
    int druha = 0;
    FOR(j,ostalo){
      if (i & (1<<j)) spravna++;
      else druha++;
      if (spravna > mx){
	spravna--;
	druha++;
      }
      if (druha > mx){
	spravna++;
	druha--;
      }
    }
    if (spravna >= Y+1) res += chunk;
  }
  
  printf("Case #%d: %.10lf\n", tt+1, res);
  return;

  FOR(i,ostalo+5)FOR(j,ostalo+5) DP[i][j] = -1.0;

  cout << "mx: " << mx << ", ostalo: " << ostalo << endl;
  
//  printf("kk %lf\n", kolko(2,0));
//  return;

  double sm = 0.0;
  for(int y = Y+1; y <= mx; y++){
    int druha = ostalo - y;
    if (druha > mx) continue;
   // cout << "budem zistovat: " << y << " " << druha << endl;
    sm+=kolko(y, druha);
  }

  FOR(i,5){
    FOR(j,5) printf("%lf ", DP[i][j]);
    printf("\n");
  }

  printf("Case #%d: %.10lf\n", tt+1, sm);

}

int main(){
  int TT;
  scanf("%d ", &TT);
  FOR(tt,TT) solve(tt);
}
