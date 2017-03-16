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

const int N=1000005;

int f[N],g[N];

bool check(char a)
{
	if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return 1;
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
		string s;
		int m;
		cin>>s>>m;
		int n=s.size();
		f[n]=0;
		for (int i=n-1;i>=0;--i)
		{
			f[i]=f[i+1];
			if (check(s[i])) ++f[i];
		}
		for (int i=0;i<n;++i)
		{
			int j=i+m-1;
			g[i]=-1;
			if (j>=n) continue;
			if (f[i]-f[j+1]!=0) continue;
			g[i]=j;
		}
		for (int i=n-2;i>=0;--i)
		{
			if (g[i]==-1) g[i]=g[i+1];
		}
		long long ans=0;
		for (int i=0;i<n;++i)
		{
			if (g[i]==-1) continue;
			ans+=n-g[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
