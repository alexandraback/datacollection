#include <bits/stdc++.h>
using namespace std;


#define ll long long 

int f[1111];

bool ban[1111];
int dp[1111];

int match[1111];

bool cyc[1111];

void init(){
	memset(ban,0,sizeof(ban));
	memset(dp,0,sizeof(dp));
}

int n;



int fun(int u){
	if(dp[u]){
		return dp[u];
	}
	int res = 1;
	for(int i=1;i<=n;i++){
		if(match[i]==u)continue;
		if(f[i]==u){
			res = max(res,fun(i)+1);
		}
	}
	dp[u] = res;
	return res;
}

int ans = 0;

int main(){
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int t;
	cin>>t;
	int cas = 0;
	while(t--){
		init();
		memset(match,0,sizeof(match));
		cas++;
		
		
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>f[i];
		}
		
		ans = 0;
		for(int i=1;i<=n;i++){
			if(ban[i])continue;
			int cur=i;
			bool vis[1111];
			memset(vis,0,sizeof(vis));
			int tmp=0;
			while(1){
				vis[cur] = 1;
				cur = f[cur];
				tmp++;
				if(cur==i){
					
					while(1){
						ban[cur] = 1;
						cur = f[cur];
						if(cur==i)break;
					}
					
					ans = max(ans,tmp);
					break;
				}
				if(vis[cur]){
					break;
				}
			}
		
		}
		
		int ans2 = 0;
		init();
		for(int i=1;i<=n;i++){
			if(ban[i])continue;
			if(f[f[i]]==i){
				ban[i]=1;
				ban[f[i]]=1;
				match[i] = f[i];
				match[f[i]] = i;
				ans2+=2;
			}
		}
		
	
		
		for(int i=1;i<=n;i++){
			if(ban[i]){
				ans2+=fun(i)-1;
			//	cout<<"dp "<<i<<" = "<<fun(i)<<endl;
			}
		}
			
		
		
		
		printf("Case #%d: ",cas);
	//	cout<<ans<<" "<<ans2<<endl;
		cout<<max(ans,ans2)<<endl;
		
	}
	return 0;
}
