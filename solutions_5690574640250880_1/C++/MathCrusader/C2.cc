#include <iostream>
#include <set>
#include <vector>
#include <cassert>
using namespace std;

void f(int R,int C,int M){
  bool transpose = (R < C);
  if(R < C) swap(R,C);
  
  int orig_m = M;
  
  int blanks;
  
  vector<vector<char> > ans(R,vector<char>(C,'.'));
  vector<char> full(C,'*');
  
  if(R*C == M+1) {
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        ans[i][j] = '*';
    goto return_me;
  }
  if(C == 1){
    for(int i=0;i<M;i++)
      ans[i][0] = '*';
    goto return_me;
  }
  
  if(C == 2){
    if(M % 2) goto impossible;
    if(R*C-M == 2) goto impossible;
    
    for(int i=0;i<M/2;i++)
      ans[i][0] = ans[i][1] = '*';
    goto return_me;
  }
  
  if(M <= (R-3)*C){
    for(int i=0;i<R;i++){
      if(M == 0){
        // Do nothing...
      } else if(M >= C){
        ans[i] = full;
        M -= C;
      } else if(M <= C-2){
        for(int j=0;j<M;j++)
          ans[i][j] = '*';
        M = 0;
      } else if(M == C-1){
        for(int j=0;j<C-2;j++)
          ans[i][j] = '*';
        M = 1;
      }
    }
    goto return_me;
  }
  
  for(int i=0;i<R-3;i++) ans[i] = full;
  M -= (R-3)*C;
  
  if(M <= (C-3)*3){
    for(int j=0;j<C;j++){
      if(M == 0){
        // Do nothing...
      } else if(M >= 3){
        for(int i=R-3;i<R;i++)
          ans[i][j] = '*';
        M -= 3;
      } else if(M == 1 || M == 2){
        ans[R-3][j] = '*';
        M--;
      }
    }
    goto return_me;
  }
  
  M -= (C-3)*3;
  
  // Fill in everything (switch will unfill)
  for(int j=0;j<C;j++){
    for(int i=R-3;i<R;i++)
      ans[i][j] = '*';
  }
  
  switch(9-M){
    case 2:
    case 3:
    case 5:
    case 7:
      goto impossible;
    case 9:
      ans[R-3][C-3] = '.';
    case 8:
      ans[R-2][C-3] = ans[R-1][C-3] = '.';
    case 6:
      ans[R-3][C-1] = ans[R-3][C-2] = '.';
    case 4:
      ans[R-2][C-1] = ans[R-1][C-2] = ans[R-2][C-2] = '.';
    case 1:
      ans[R-1][C-1] = '.';
      goto return_me;
    default:;
  }
  
  
impossible:
  cout << "Impossible" << endl;
  return;
  
  
return_me:
  int ctr = 0;
  if(transpose){
    for(int i=0;i<C;i++){
      for(int j=0;j<R;j++){
        cout << (i == C-1 && j == R-1 ? 'c' : ans[j][i]);
        if((i != C-1 || j != R-1) && ans[j][i] == '*')
          ctr++;
      }
      cout << endl;
    }
  } else {
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        cout << (i == R-1 && j == C-1 ? 'c' : ans[i][j]);
        if((i != R-1 || j != C-1) && ans[i][j] == '*')
          ctr++;
      }
      cout << endl;
    }
  }
  if(orig_m != ctr){
    cout << "NOO " << orig_m << " " << ctr << endl;
    assert(false);
  }
}

int main(){
  int T,CC=1,R,C,M;
  cin >> T;
  while(T--){
    cout << "Case #" << CC++ << ":" << endl;
    cin >> R >> C >> M;
    f(R,C,M);
  }
  return 0;
}
