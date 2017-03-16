#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,D,V;


ll solve(){
  ll ans=0;
  vector<ll> t(D);
  for(int i=0;i<D;i++)cin>>t[i];
  if(t[0]!=1){
    ans++;
    t.push_back(1);
  }
  t.push_back(V+1);
  sort(t.begin(),t.end());
  
  ll sum=0;
  for(int i=0;i+1<(int)t.size();i++){
    sum+=C*t[i];
    if(sum < t[i+1]-1){
      ans++;
      t[i]=sum+1;
      i--;
    }		     
  }
  return ans;
}

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>C>>D>>V;
    cout<<"Case #"<<tc<<": "<<solve()<<endl;
  }
  return 0;
}
