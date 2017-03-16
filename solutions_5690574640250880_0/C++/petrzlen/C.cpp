#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

void solve(){
  int R, C, M; 
  cin >> R >> C >> M; 
  int E = R*C-M; 
  
  int m=max(R,C);
  string S[m];
  REP(i, m) S[i] = string(m, '*'); 
  
  int s=0; 
  if(R>C) {swap(R,C); s=1;}
  
  if(E>1){
    if(R==1) REP(i, E) S[0][i] = '.'; 
    else if(R==2) {
      if(E==2 || E%2==1) s=-1; 
      REP(i, E/2) S[0][i] = S[1][i] = '.'; 
    }
    else{ // R>2
      if(E<4 || E==5 || E==7) s = -1; 
      else{ // E>=4
        S[0][0] = S[0][1] = S[1][0] = S[1][1] = '.'; 
        int T=4; 
        bool h=true; 
        int r=2; 
        int c=2; 
        while(T<E){
          if(E-T==1 || (r==R && c==C)){ //TODO suboptimal speed by factor of O(m^2) 
            int f=false;
            for(int i=2; i<R && !f ; i++) for(int j=2; j<C && !f; j++) if(S[i][j]=='*'){
              f=true; 
              S[i][j]='.';
              T++; 
            }
          }
          else{ 
            if(h || (!h && r==R)) {
              S[0][c] = S[1][c] = '.';
              T+=2;
              c++; 
              h = false; 
            }
            else{
              S[r][0] = S[r][1] = '.';
              T+=2; 
              r++;
              h = true; 
            }
          }
        }
      }
    }
  }
  
  if(s==1){
    REP(i, R) REP(j, C) if(i<j) swap(S[i][j], S[j][i]);
    swap(R,C); 
  }
  
  if(s==-1){
    cout << "Impossible" << endl;
  }
  else{  
    S[0][0]='c'; 
    REP(i, R) {REP(j, C) cout << S[i][j]; cout << endl;} 
  }
}

int main(){
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": " << endl; 
    solve(); 
  } 
  return 0; 
}
