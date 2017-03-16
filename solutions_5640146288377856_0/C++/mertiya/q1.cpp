#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,t,count,r,c,w,ans;
	
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin>>t;
	count=1;
	while(t--){
		ans=0;
		cout<<"Case #"<<count<<": ";
		cin>>r>>c>>w;
		if(w==c){
			ans+=(r-1);
			ans+=w;
			cout<<ans<<endl;
		}
		else {
			ans+=((r-1)*(c/w));
			if(c%w){
				ans+=(c/w);
				ans+=w;
			}
			else{
				ans+=(c/w);
				ans--;
				ans+=w;
			}
			cout<<ans<<endl;
		}
		
		count++;
		
	}
	
return 0;
}
