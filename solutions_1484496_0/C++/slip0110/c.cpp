#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int use[2000010];
int in[30];
int n;

void show(int sum , int idx){
  int bit = use[sum];
  bool first = true;
  for(int i = 0 ; i < n ; i++){
    if(bit & (1<<i)){
      if(!first){
        cout<<" ";
      }
      cout<<in[i];
      first = false;
    }
  }
  cout<<endl;
  first = true;
  for(int i = 0 ; i < n ; i++){
    if(idx & (1<<i)){
      if(!first){
        cout<<" ";
      }
      cout<<in[i];
      first = false;
    }
  }
  cout<<endl;
}

int main(){
  int T;
  cin>>T;
  for(int t = 1 ; t <= T ; t++){
    cout<<"Case #"<<t<<":\n";
    memset(use , -1 , sizeof(use));
    cin>>n;
    rep(i,n){
      cin>>in[i];
    }
    
    bool f = false;
    for(int i = 1 ; i < (1<<n) ; i++){
      int sum = 0;
      for(int j = 0 ; j < n ; j++){
        //cout<<i<<" "<<j<<endl;
        if(i & (1<<j)){
          sum += in[j];
        }
      }
      if(use[sum] == -1){
        use[sum] = i;
      }
      else{
        f = true;
        show(sum , i);
        break;
      }
    }
    if(!f){
      cout<<"Impossible"<<endl;
    }
  }
}
