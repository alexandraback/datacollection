#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int N,M,K;
int a[100];
int ans;

int num[10];
int dfs(int dep)
{
	if(dep==4)
	{
		int i;
		for(i=1;i<=K;i++)
		{
			int is=0;
			if(a[i]==1)
				is=1;
			if(N>=1&&a[i]==num[1])
				is=1;
			if(N>=2&&(a[i]==num[2]||a[i]==num[1]*num[2]))
				is=1;
			if(N>=3&&(a[i]==num[3]||a[i]==num[1]*num[3]||a[i]==num[2]*num[3]||a[i]==num[1]*num[2]*num[3]))
				is=1;
			if(!is)
				return 0;
		}
		return 1;
	}
	for(int i=2;i<=M;i++)
	{
		num[dep]=i;
		if(dfs(dep+1))
			return 1;
	}
	return 0;
}
int main()
{
	int t,R,i,j;

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int ii=0;
	cin>>t;

	while(t--)
	{
		cin>>R>>N>>M>>K;

		printf("Case #%d:\n",++ii);
		for(i=1;i<=R;i++)
		{
			for(j=1;j<=K;j++)
				cin>>a[j];
			dfs(1);
			for(j=1;j<=N;j++)
				cout<<num[j];
			cout<<endl;
		}
	}
}