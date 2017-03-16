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

int N,TT;
PII L[1050];
int hral[1005];

int main(){
  scanf("%d ",&TT);  
  FOR(tt,TT){
    scanf("%d ",&N);
    FOR(i,N) scanf("%d %d ",&L[i].second,&L[i].first);
    sort(L,L+N);
    int lvl = 0;
    int hier = 0;
    memset(hral,0,sizeof(hral));    
    FOR(i,N){
      if (L[i].first <= lvl){
	if (hral[i] == 1) lvl++;
	else lvl+=2;
	hral[i] = 2;
	hier++;
      }else{
	int best = -1;
	int besti = -1;
	for(int j=i;j<N;j++) if (hral[j] == 0){
	  if (L[j].second > lvl) continue;
	  if (L[j].first > best){
	    best = L[j].first;
	    besti = j;
	  }
	}
	if (besti == -1){
	  lvl = -1;
	  break;
	}else{
	  hier++;
	  hral[besti] = 1;
	  lvl++;
	}
	i--;
      }
    }
    printf("Case #%d: ",(tt+1));
    if (lvl == -1) printf("Too Bad\n");
    else printf("%d\n",hier);
  }
}
