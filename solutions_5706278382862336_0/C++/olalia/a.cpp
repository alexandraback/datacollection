#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstdlib>
#include<queue>
#include<cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
  if (a==0)
    return b;
  return gcd(b%a, a);
}


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    string s; cin>>s;
    ll p=0, q=0;
    int i;
    for (i=0; s[i]!='/'; ++i){
      p*=10;
      p+=ll(s[i]-'0');
    }
    ++i;
    for (i=i; i<s.size(); ++i){
      q*=10;
      q+=ll(s[i]-'0');
    }
    ll gc=gcd(p,q);
    p/=gc;
    q/=gc;
    int ans=0;
    ll hei=1;
    for (i=0; hei<=q; ++i){
      ans+=!!(hei&q);
      hei*=2;
    }
    if (ans!=1){
      cout<<"impossible\n";
      continue;
    }
    ans=0;
    while(p!=1){
      p/=2;
      q/=2;
    }
    while(q!=1){
      q/=2;
      ++ans;
    }
    cout<<ans<<endl;

  }
  return 0;
}
