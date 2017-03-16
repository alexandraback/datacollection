#include <bits/stdc++.h>
using namespace std;


#define ll long long 

int f[1111];

bool ban[1111];

void init(){
	memset(ban,0,sizeof(ban));
}

int n;

int ans = 0;

void dfs(vector<int> vec){
	
	
	int sz = vec.size();
	ban[vec[sz-1]]=1;
	if(sz>1){
		if( f[vec[sz-1]]==vec[0] || f[vec[sz-1]]==vec[sz-2]){
			if(f[vec[0]]==vec[sz-1] || f[vec[0]]==vec[1]){
				ans = max(ans,sz);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(ban[i])continue;
		if(vec.size()==1){
			vector<int> nextVec = vec;
			nextVec.push_back(i);
			dfs(nextVec);
		}else{
			if(f[vec[sz-1]] == vec[sz-2]){
				vector<int> nextVec = vec;
				nextVec.push_back(i);
				dfs(nextVec);
			}else if(f[vec[sz-1]] == i){
				vector<int> nextVec = vec;
				nextVec.push_back(i);
				dfs(nextVec);
			}
		}
	}
	ban[vec[sz-1]]=0;
	
	
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	int cas = 0;
	while(t--){
		init();
		cas++;
		
		
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>f[i];
		}
		
		ans = 0;
		for(int i=1;i<=n;i++){
			vector<int> tmp;
			tmp.push_back(i);
			dfs(tmp);
		}
		
		printf("Case #%d: ",cas);
		cout<<ans<<endl;
		
	}
	return 0;
}
