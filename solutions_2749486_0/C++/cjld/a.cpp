#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

char ans[1000005];

bool cal(int i,int j,int d)
{
	return 1LL*(i+j)*(j-i+1)/2<d;
}

bool dfs(int i,int j,int x,int y,int p,int q)
{
	if (i>j) return (x==p && y==q);
	if (cal(i,j,abs(p-x)+abs(q-y))) return 0;
	ans[i]='N'; if (dfs(i+1,j,x,y+i,p,q)) return 1;
	ans[i]='S'; if (dfs(i+1,j,x,y-i,p,q)) return 1;
	ans[i]='E'; if (dfs(i+1,j,x+i,y,p,q)) return 1;
	ans[i]='W'; if (dfs(i+1,j,x-i,y,p,q)) return 1;
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	int task;
	cin>>task;
	for (int tt=1;tt<=task;++tt)
	{
		cout<<"Case #"<<tt<<": ";
		int x,y;
		cin>>x>>y;
		int t;
		for (t=1;;++t)
			if (dfs(1,t,0,0,x,y)) break;
		for (int i=1;i<=t;++i) cout<<ans[i]; cout<<endl;
	}
	return 0;
}
