#include <iostream>
#include <vector>
using namespace std;

void solve(){
  int N;cin>>N;
  int M;cin>>M;
  int state[N][M];
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      cin>>state[i][j];
    }
  }
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      bool row = false;
      for(int k=0;k<M;++k){
        if(state[i][j]<state[i][k])row=true;
      }
      bool col = false;
      for(int k=0;k<N;++k){
        if(state[i][j]<state[k][j])col=true;
      }
      if(row&&col){
        cout<<"NO"<<endl;
        return;
      }
    }
  }  
  cout << "YES" << endl;
}
int main(){
  int N;cin>>N;
  for(int i=1;i<=N;++i){
    cout << "Case #" << i <<": ";
    solve();
  }
  return 0;
}

