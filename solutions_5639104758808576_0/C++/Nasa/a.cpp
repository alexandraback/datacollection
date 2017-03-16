#include <iostream>
using namespace std;

char s[1011];

int main(){
  int t,u,n,i,tot,ans;
  cin>>t; for (u=0; u<t; u++){
    cin>>n>>s; tot=s[0]-'0';
    ans=0;
    for (i=1; i<=n; i++) if (s[i]-'0'){
	if (tot<i) ans+=i-tot;
	tot=max(tot,i)+s[i]-'0';
      }
    cout<<"Case #"<<(u+1)<<": "<<ans<<endl;
  }
  return 0;
}

				
