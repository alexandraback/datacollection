#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
int t,n,m,i,j,k,o;
int s[111][111],x[111],y[111];
vector< pair<int,int> > que[111];
bool can;
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&t);
	for(o=1;o<=t;o++){
		scanf("%d%d",&n,&m);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for (i=1;i<=100;i++)que[i].clear();
		can=true;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				scanf("%d",&s[i][j]);
				que[s[i][j]].push_back(pair<int,int>(i,j));
			}
		cout<<"Case #"<<o<<": ";
		for(k=100;k>0;k--){
			for(i=0;i<que[k].size();i++)
				if (x[que[k][i].first]>0&&y[que[k][i].second]>0)can=false;
			for(i=0;i<que[k].size();i++)
				x[que[k][i].first]++,y[que[k][i].second]++;
		}
		if (can)cout<<"YES";
		else	cout<<"NO";
		cout<<endl;
	}
	return 0;
}
