#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());


bool s[4][4][4] ={
{
{1,0,0,0},
{1,1,0,0},
{1,0,0,0},
{1,1,0,0}
},
{
{1,1,0,0},
{1,1,0,0},
{1,1,1,0},
{1,1,0,0}
},
{
{1,0,0,0},
{1,1,1,0},
{1,0,1,0},
{1,1,1,1}
},
{
{1,1,0,0},
{1,1,0,0},
{1,1,1,1},
{1,1,0,1}
}
};

int main(){
  int n, m, x;
  int T;
  ri(T);
  
  for(int i = 0;i < 4; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        if(s[i][j][k]){
          assert((((i+1)*(j+1))%(k+1)==0));
        }
      }
    }
  }
  
  for(int k = 0; k < n; k++){
    for(int i = 0;i < 4; i++){
      for(int j = 0; j < n; j++){
        assert(s[i][j][k] ==s[j][i][k]);
        
      }
    }
  }
  for(int t = 0; t < T; t++){
    ri(x); ri(n); ri(m);
    printf("Case #%d: %s\n", t+1, s[n-1][m-1][x-1]?"GABRIEL":"RICHARD");
  }
  return 0;
}

