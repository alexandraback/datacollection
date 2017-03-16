#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL unsigned long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;

int R, N=3, M=5, K=4, PLIM = 200;
int v[20];
int t[20];
set<LL> prods;
int iter = 10000;
void solve() {
  FORN(i, iter) {
    FORN(j, N) {
      t[j] = 2+(rand()%(M-1));
    }
    prods.clear();
    FORN(j, (1<<N)) {
      LL x = 1;
      FORN(k, N) {
        if(j&(1<<k)) {
          x*=(LL)t[k];
        }
      }
      prods.insert(x);
    }
    bool done = 0;
    FORN(j, K) {
      if(prods.find(v[j]) == prods.end()) {
        done = 1;
        break;
      }
    }
    if (!done) {
      FORN(k, N) {
        cout<<t[k];
      }
      cout<<endl;
      return;
    }
  }
  FORN(k, N) {
    cout<<2;
  }
  cout<<endl;
}

int main() {
  int T;
  GI(T);
  srand(time(NULL));
  cin>>R>>N>>M>>K;
  cout<<"Case #"<<1<<":"<<endl;
  FORN(i, R) {
    FORN(j, K) {
      GI(v[j]);
    }
    solve();
  }
  return 0;
}
