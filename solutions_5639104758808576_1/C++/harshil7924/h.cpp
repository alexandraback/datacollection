#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n;
	string s;
	cin>>t;
	int cnt=0;
	while(t--){
		cnt++;
		cin>>n>>s;
		ll cur=0;
		ll ans=0;
		for(int i=0;i<=n;i++){
			if(s[i]!='0'){
				if(cur<i){
					ans=ans+i-cur;
					cur=i;
				}
			}
			cur+=s[i]-'0';
		}
		cout<<"Case #"<<cnt<<": "<<ans<<"\n";
	}
}
