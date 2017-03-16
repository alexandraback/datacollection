#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>



using namespace std;

typedef long long ll;


ll lpow(ll a, int b){
  ll c=1;
  while(b>0){
    if (b%2) c*=a;
    b/=2;
    a*=a;
  }
  return c;
}


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int k, c, s; cin>>k>>c>>s;
    cout<<"Case #"<<tc<<": ";
    if (c*s<k){
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    ll a=1;
    for (int i=0; i*c<k; ++i){
      a=1;
      for (int j=0; i*c+j<k && j<c; ++j)
	a+=lpow(k,j)*(i*c+j);
      cout<<a<<" ";
    }
    cout<<endl;
  }
  return 0;
}
