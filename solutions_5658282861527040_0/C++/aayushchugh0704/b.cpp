#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>

typedef long long int ll;
typedef long double ld;
#define SLL(x) scanf("%lld",&(x))
#define REP(i,n) for(i=0;i<(n);i++)
#define SI(x) scanf("%d",&(x))
using namespace std;
void pans(int n, string s){
  cout<<"Case #"<<n<<": "<<s<<endl;// %d: %d
}
void pans(int n, int s){
  cout<<"Case #"<<n<<": "<<s<<endl;// %d: %d
}
int main(){
  int i,j,k,n;
  int t,a,b;
  SI(t);
  for(int i_=0;i_<t;i_++){
    cin>>a;
    cin>>b;
    cin>>k;
  
    ll ans=0;
    for(i=0;i<a;i++){
      for(j=0;j<b;j++){
	if((i&j)<k)ans++;
      }
    }
    pans(1+i_,ans);
  }
  return 0;
}
