#include <bits/stdc++.h>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,n,m;
	cin>>t;
	string s,ans;
	for(te=0;te<t;te++){
		cin>>s;
		ans="a";
		ans[0]=s[0];
		for(i=1;i<s.size();i++){
			ans=max(s[i]+ans,ans+s[i]);
		}
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";

	}
	return 0;
}