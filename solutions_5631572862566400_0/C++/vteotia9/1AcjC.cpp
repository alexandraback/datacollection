#include<bits/stdc++.h>
#define mod 1000000007
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define ff first
#define ss second
#define big 100000000000000000
using namespace std;

ll tc,ans,n,visited[2000],outgo[2000],num;
vector<ll> incum[2000];

void dfs(ll in,ll run,bool flag1){
	if(visited[in])
		return;
	run++;
	visited[in] = 1;
	ans = max(ans , run);
	
	dfs(outgo[in],run,0);
	bool flag2 = 0;
	for(ll i=0;i<incum[in].size();i++)
		if(incum[in][i] == outgo[in] && visited[incum[in][i]])
			flag2 = 1;
	if(flag1 || flag2)
		for(ll i=0;i<incum[in].size();i++)
			dfs(incum[in][i],run,1);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>tc;
	for(ll t=1;t<=tc;t++){
		ans = 0;
		memset(incum,0,sizeof(incum));
		memset(outgo,0,sizeof(outgo));
		
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>num;
			outgo[i] = num;
			incum[num].push_back(i);
		}
		
		for(ll i=1;i<=n;i++){
			memset(visited,0,sizeof(visited));
			dfs(i,0,0);
		}
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}

