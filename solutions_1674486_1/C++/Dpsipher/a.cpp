#include "iostream"
#include "cstdio"
#include "vector"
#include "math.h"
#include "algorithm"
#include "string.h"
#include "sstream"
#include "stack"
#include "queue"
#include "map"
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<(0)?(a)*(-1):(a))
#define pb(x) push_back(x)
#define pii pair<int,int>
#define ll long long
using namespace std;

vector<int> G[1010];
int vis[1010];
int In[1010];
int solve(int u,int cnt)
{
	if(vis[u]==cnt)
		return true;
	vis[u]=cnt;
	int i;
	for(i=0;i<G[u].size();i++)
		if(solve(G[u][i],cnt))
			return true;
	return false;
}
int main()
{
	int test,tt,n,i,j,v,m;
	cin>>test;
	for(tt=1;tt<=test;tt++){
		printf("Case #%d: ",tt);
		cin>>n;
		memset(In,0,sizeof In);
		memset(vis,0,sizeof vis);
		//cout<<n<<endl;
		for(i=1;i<=n;i++)
		{
			G[i].clear();
			cin>>m;
			//if(tt==22)cout<<m<<" ";
			for(j=0;j<m;j++){
				cin>>v;
				//if(tt==22)cout<<v<<" ";
				G[i].push_back(v);
				In[v]++;
			}
			//if(tt==22)cout<<endl;
		}
		
		bool f=0;
		for(i=1;i<=n;i++){
			if(!In[i] && !vis[i]){
				if(solve(i,i)){
					//cout<<"i "<<i<<endl;
					cout<<"Yes\n";
					f=1;
					break;
				}
			}
		}
		if(!f)
			cout<<"No\n";
	}
	return 0;
}
