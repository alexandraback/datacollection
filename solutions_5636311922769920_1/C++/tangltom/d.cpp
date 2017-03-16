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
    vector<ll> kc;
    kc.push_back(1);
    for(int c=1;c<C;c++)
      kc.push_back(kc.back()*K);
    vector<ll> pos;
    for(ll i=0;i<K;){
      ll p = 1;
      for(int c=C-1;c>=0 && i<K;c--,i++){
	p += i*kc[c];
      }
      pos.push_back(p);
    }
    if(pos.size()>S)
      cout<<"IMPOSSIBLE";
    else
      for(ll p:pos)
	cout<<p<<" ";
    cout<<endl;
  }
  return 0;
}
