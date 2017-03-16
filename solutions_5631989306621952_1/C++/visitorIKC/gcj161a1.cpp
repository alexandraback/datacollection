#include <bits/stdc++.h>

using namespace std;
int main(){
	int tc,i=0;
	cin>>tc;
	while(tc-->0){
		i++;
		string st,ans;
		cin>>st;
		ans+=st[0];
		for(int i=1;i<st.size();i++){
			if(st[i]>=ans[0]){
				ans=st[i]+ans;
			}else{
				ans=ans+st[i];
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
