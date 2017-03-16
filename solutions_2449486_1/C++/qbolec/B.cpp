#include "common.h"
void solve(){
  int rows,cols;
  cin >> rows >> cols ;
  vector<vector<int> > t(rows,vector<int>(cols,100));
  for(int r=0;r<rows;++r){
    for(int c=0;c<cols;++c){
      cin >> t[r][c];
    }
  }
  for(int i=1;i<100;++i){
    bool ok = true;
    vector<vector<int> > b(rows,vector<int>(cols,0));
    for(int r=0;r<rows;++r){
      for(int c=0;c<cols;++c){
        b[r][c]=(t[r][c]==i);
      }
    }
    vector<vector<int> > rest = b;
    
    for(int r=0;r<rows;++r){
      bool whole = true;
      for(int c=0;c<cols;++c){
        if(!b[r][c]){
          whole=false;
          break;
        }
      }
      if(whole){
        for(int c=0;c<cols;++c){
          rest[r][c] = false;
        }      
      }
    }
    for(int c=0;c<cols;++c){
      bool whole = true;
      for(int r=0;r<rows;++r){
        if(!b[r][c]){
          whole=false;
          break;
        }
      }
      if(whole){
        for(int r=0;r<rows;++r){
          rest[r][c] = false;
        }      
      }
    }
    for(int r=0;r<rows;++r){
      for(int c=0;c<cols;++c){
        if(rest[r][c]){
          ok=false;
          break;
        }
      }
    }
    if(ok){
      for(int r=0;r<rows;++r){
        for(int c=0;c<cols;++c){
          if(b[r][c]){
            t[r][c]=i+1;
          }
        }
      }    
    }else{
      cout << "NO" << endl;
      return;
    }
  }
  for(int r=0;r<rows;++r){
    for(int c=0;c<cols;++c){
      assert(t[r][c]==100);
    }
  }
  cout << "YES" << endl;
  
}
int main(){
  int t;
  cin >> t;
  for(int i=1;i<=t;++i){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}