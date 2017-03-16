#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            1
#define INF             0x3fffffff
#define MM(s,a)         memset((s),(a),sizeof((s)))
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;

int T;
int N,M;
vector<int> V[1001];
int B[1001];
bool found;

void dfs(int s, int color){
  B[s]=color;
  for (vector<int>::iterator it=V[s].begin(); it!=V[s].end(); ++it){
    int y=*it;
    if (B[y]==color) {found=true;}
    else dfs(y,color);
  }
}

int main(){
  scanf("%d",&T);
  for (int t=1; t<=T; ++t){
    for (int i=0; i<1001; ++i) V[i].clear();
    memset(B,-1,sizeof B);
    printf("Case #%d: ",t);
    scanf("%d",&N);
    for (int i=0; i<N; ++i){
      scanf("%d",&M);
      for (int j=0; j<M; ++j){
	int tmp;
	scanf("%d",&tmp);
	--tmp;
	V[i].push_back(tmp);
      }
    }
    found=false;
    for (int i=0; i<N; ++i){
      dfs(i,i);
      if (found) break;
    }
    printf("%s\n",found?"Yes":"No");
  }
}
