#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int c[20],q[20],ans[20],a[20],mymax,n;
bool g[20],f[20];

void dfs2(int d){
	if (d>c[0]){
		for (int i=2;i<c[0];i++)
			if (q[i+1]!=a[q[i]] && q[i-1]!=a[q[i]]) return;
		if (q[2]!=a[q[1]] && q[c[0]]!=a[q[1]]) return;
		if (q[1]!=a[q[c[0]]] && q[c[0]-1]!=a[q[c[0]]]) return;
		mymax=c[0];
		for (int i=1;i<=c[0];i++)
			ans[i]=q[i];
		return;
	}
	for (int i=1;i<=c[0];i++)
		if (!g[i]){
			g[i]=1;
			q[d]=c[i];
			dfs2(d+1);
			g[i]=0;
		}
}

void dfs(int d){
	if (d>n){
		if (c[0]<=mymax) return;
		for (int i=1;i<=c[0];i++)
			if (!f[a[c[i]]]) return;
		dfs2(1);
		return;
	}
	dfs(d+1);
	f[d]=1;
	c[++c[0]]=d;
	dfs(d+1);
	c[0]--;
	f[d]=0;
}

int main(){
	int tt;
	cin>>tt;

	for (int cs=1;cs<=tt;cs++){
		mymax=0;
		printf("Case #%d: ",cs);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		c[0]=0;
		dfs(1);
		printf("%d\n",mymax);
	}

	return 0;
}