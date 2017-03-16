#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>

using namespace std;

typedef long long ll;

int T;

ll firs(ll a, int c){
  for  (int i=0; i<(c+1)/2; ++i)
    a/=10;
  ll d=0;
  for (int i=0; i<c/2; ++i){
    d*=10;
    d+=(a%10);
    a/=10;
  }
  return d;
}

ll las(ll a, int c){
  ll d=0;
  ll ti=1;
  for (int i=0; i<(c+1)/2; ++i){
    d+=ti*(a%10);
    ti*=10;
    a/=10;
  }
  return d;
}
    


int main(){
  cin>>T;
  for (int tc=1; tc<=T; ++tc){
    ll n; cin>>n;
    ll ans=0;
    ll ti=1;
    int c=0;
    cout<<"Case #"<<tc<<": ";
    if (n<10){
      cout<<n<<endl;
      continue;
    }
    
    if (n%10==0){
      ++ans;
      n--;
    }
    while(n>=ti){
      ti*=10;
      ++c;
    }
    while(c>1){
      ll a, b;
      a=firs(n, c);
      b=las(n, c);
      ans+=a+b+(a!=1);
      ti/=10;
      c--;
      n=ti-1;
    }
    ans+=9;
    cout<<ans<<endl;
    
  }
  return 0;
}
