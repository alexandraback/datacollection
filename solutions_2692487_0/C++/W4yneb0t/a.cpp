#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll sz[109];
ll t;
int main(){
  ll t;
  ll n,a;
  cin>>t;
  for(int z=1;z<=t;z++){
    cout<<"Case #"<<z<<": ";
    cin>>a>>n;
    for(int i=0;i<n;i++){
      cin>>sz[i];
    }
    sort(sz,sz+n);
    int bt=1000;
    int cm=0;
    int cg=0;
    while(cm<=n && cg<=105){
      while(cm<n && a>sz[cm]){
	a+=sz[cm++];
      }
      if(n-cm+cg<bt)
	bt=n-cm+cg;
      a+=(a-1);
      cg++;
    }
    cout<<bt<<endl;
  }
  return 0;
}
