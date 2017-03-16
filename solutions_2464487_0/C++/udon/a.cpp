#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
int T;
bool check(ld r,ld t,ld n){
  return t>=(2*n*n+(2*r-1.0)*n);
}
int main(){
  cin>>T;
  for(int i=1;i<=T;i++){
    ld a,b,c,r,t,ans;
    cin>>r>>t;
    a=2.0;b=(2*r-1.0);c=-t;
    //cout<<b*b-4*a*c;
    ans=-b+sqrt(b*b-4*a*c);
    ans/=2*a;
    for(ll j=(ll)ans-1;j<=(ll)ans;j++){
      if(check(r,t,j))ans=j;
    }
    ans=(int)ans+1;
    ans=(check(r,t,ans))?ans:ans-1;
    printf("Case #%d: %d\n",i,(int)ans);
  }
}
