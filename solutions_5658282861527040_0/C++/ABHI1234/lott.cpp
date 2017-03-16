#include<iostream>
using namespace std;
int main(){
  int t,a,b,k,ans,l=1,i,j,x;
  cin>>t;
  while(l<=t){
    cin>>a>>b>>k;
    ans = 0;
    for(i=0;i<a;i++){
      for(j=0;j<b;j++){
	x = i & j;
	if(x<k)
	  ans++;
      }
    }
    cout<<"Case #"<<l<<": "<<ans<<endl;
    l++;
  }
  return 0;
}
