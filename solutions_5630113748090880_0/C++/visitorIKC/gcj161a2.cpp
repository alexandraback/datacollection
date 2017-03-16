#include <bits/stdc++.h>

using namespace std;
int cnt[2519];
int main(){
	int tc,i=0;
	cin>>tc;
	while(tc-->0){
		i++;
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		for(int i=0;i<n*(n*2-1);i++){
			int t;
			cin>>t;
			cnt[t]^=1;
		}
		vector<int>ans;
		for(int i=0;i<2519;i++){
			if(cnt[i]==1){
				ans.push_back(i);
			}
		}
		cout<<"Case #"<<i<<": ";
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" \n"[i==n-1];
		}
	}
	return 0;
}
