#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

long long a[200],b[200],c[200],d[200];
int n,m;

long long dfs(vector<long long> e,int p,int q)
{
	if(p>=4)return 0;
	if(b[p]!=d[q]) return dfs(e,p,q+1);
	if(e[p]==0) dfs(e,p+1,q);
	if(q>=m) return 0;
	long long ans=0;
	long long tmp=min(c[q],e[p]);
	e[p]-=tmp;
	if(p<4) ans=max(ans,tmp+dfs(e,p+1,q));
	ans=max(ans,tmp+dfs(e,p,q+1));
	return ans;
}

int main()
{
	int x;
	cin>>x;
	for(int y=1;y<=x;y++){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(i>0 && b[i]==b[i-1]){
				a[i-1]+=a[i];n--;i--;
			}
		}
		for(int i=0;i<m;i++){
			cin>>c[i]>>d[i];
			if(i>0 && d[i]==d[i-1]){
				c[i-1]+=c[i];m--;i--;
			}
		}
		long long ans=0;
		vector<long long> e;
		e.push_back(a[0]);
		e.push_back(a[1]);
		e.push_back(a[2]);
		e.push_back(0);
		ans=dfs(e,0,0);
		if(n>1) ans=max(ans,dfs(e,1,0));
		if(n>2) ans=max(ans,dfs(e,2,0));
		cout<<"Case #"<<y<<": "<<ans<<endl;
	}
}