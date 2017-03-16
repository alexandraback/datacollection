#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    ll K,C,S;
    cin>>K>>C>>S;
    cout<<"Case #"<<t<<": ";
    ll kc = 1, kcsum=1;
    for(int c=1;c<C;c++){
      kc*=K;
      kcsum += kc;
    }
    for(ll i=0;i<K;i++)
      cout<<(kcsum*i+1)<<' ';
    cout<<endl;
  }
  return 0;
}
