#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define LL long long
#define ULL unsigned long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v) {
  s << '{';
  for (int i = 0 ; i < v.size(); ++i)
    s << (i ? "," : "") << v[i];
  return s << '}';
}
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p){
  return s << "(" << p.first << "," << p.second << ")";
}

// 1 = 1
// 2 = i
// 3 = j
// 4 = k

int fromch(char c){
  return c - 'i' + 2;
}

int multiply(int l, int r){
  if(l<0) return -multiply(-l,r);
  if(r<0) return -multiply(l,-r);

  switch(l){
    case 1:
    switch(r){ // 1 * {1,i,j,k}
      case 1: return 1;
      case 2: return 2;
      case 3: return 3;
      case 4: return 4;
    }
    break;
    case 2:
    switch(r){ // i * {1,i,j,k}
      case 1: return 2;
      case 2: return -1;
      case 3: return 4;
      case 4: return -3;
    }
    break;
    case 3:
    switch(r){
      case 1: return 3;
      case 2: return -4;
      case 3: return -1;
      case 4: return 2;
    }
    break;
    case 4:
    switch(r){
      case 1: return 4;
      case 2: return 3;
      case 3: return -2;
      case 4: return -1;
    }
    break;
  }
}

int L,X,LX;
string str;
vector<int> sv;
int dp[10005][10005];

int main(){

  int TC;cin>>TC;
  for(int tc=1; tc<=TC; tc++){
    cin>>L>>X>>str;
    LX = L*X;
    sv.clear();
    for(int i=0; i<L*X; i++){
      sv.push_back(fromch(str[i%L]));
    }

    // init dp
    for(int s=0; s<LX; s++){
      int accum = sv[s];
      dp[s][s] = accum;
      for(int t=s+1;t<LX;t++){
        accum = multiply(accum, sv[t]);
        dp[s][t] = accum;
      }
    }

    // brute force
    bool success = false;
    for(int a=1; a<LX; a++){
      int prod1 = dp[0][a-1];
      for(int b=a; b<LX; b++){
        if(LX - b < 1) continue;
        if(b - a < 1) continue;
        int prod2 = dp[a][b-1];
        int prod3 = dp[b][LX-1];
        //printf("%d %d %d %d %d\n", a,b,prod1,prod2,prod3);
        if(prod1 == 2 && prod2 == 3 && prod3 == 4){
          success = true;
          break;
        }
      }
    }
    
    printf("Case #%d: %s\n", tc, success?"YES":"NO");
  }
}

