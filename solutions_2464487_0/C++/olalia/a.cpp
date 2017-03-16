#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<algorithm>
#include<cmath>


using namespace std;


typedef long long ll;
typedef long double ld;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    
    ld r, t;
    
    cin>>r>>t;
    ld f=sqrt(2*r-1)*sqrt((2*r-1)/16+t/2/(2*r-1))-.5*r+.25;
    ll ans=floor(f);  
    cout<<"Case #"<<tc<<": "<<ans<<endl;
  }
  return 0;
}
