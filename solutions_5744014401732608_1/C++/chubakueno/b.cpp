#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	ll fib[64];
	fib[0]=fib[1]=1;
	for(int i=2;i<60;++i){
		fib[i]=1LL<<(i-1);
	}
	for(int z=1;z<=t;++z){
		ll m,b;
		cin>>b>>m;
		printf("Case #%d: ",z);
		if(m>fib[b-1]) {cout<<"IMPOSSIBLE"<<endl;continue;}
		cout<<"POSSIBLE"<<endl;
		int ans[200][200];
		memset(ans,0,sizeof ans);
		--m;
		for(int i=0;i<b;++i){
			if(i!=b-1){
				for(int j=0;j<i;++j)
					ans[i][j]=1;
			}else{
				ans[i][0]=1;
				for(int j=1;j<b;++j)
					ans[i][j]=((m>>(j-1))&1);
			}
		}
		for(int i=0;i<b;++i){
			for(int j=0;j<b;++j){
				cout<<ans[j][i];
			}
			cout<<endl;
		}
	}
}