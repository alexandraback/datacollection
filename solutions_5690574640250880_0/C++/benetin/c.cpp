#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int R,C,M,G;
char bd[100][100];

void show() {
  REP(i, R) cout<<bd[i]<<endl;
}

void play() {
  if (G == 1) {
    bd[0][0]='c';
    show();
    return;
  }
  if (R == 1) {
    REP(i,G) bd[0][i]='.';
    bd[0][0]='c';
    show();
    return;
  }
  if (C == 1) {
    REP(i,G) bd[i][0]='.';
    bd[0][0]='c';
    show();
    return;
  }
  FOR(x,2,R)
    FOR(y,2,C)
    if(G<=x*y && G>=(x*y-(x-2)*(y-2))) {
      REP(i,x) bd[i][0]=bd[i][1]='.';
      REP(i,y) bd[0][i]=bd[1][i]='.';
      int rem = G - (x*y-(x-2)*(y-2));
      FOR(ii,2,x-1)
        FOR(jj,2,y-1) {
        if (rem) {
          bd[ii][jj]='.';
          rem--;
        }
      }
      bd[0][0]='c';
      show();
      return;
    }
  cout<<"Impossible"<<endl;
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>R>>C>>M;
    G = R*C-M;
    REP(i,R) {
      REP(j,C) bd[i][j]='*';
      bd[i][C]=0;
    }
    cout << "Case #" << cs << ":"<<endl;
    play();
  }
  return 0;
}
