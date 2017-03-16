#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-7
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

int a[600],made;
set <int> v,v1,v2;

int call(int i,int rem)
{
	if (!rem)
	{
		if (!made) {made++;v1= v;}
		else {made++;v2=v;}
		return 1;
	}
	if (!i) return 0;
	
	int ans= 0;
	if (a[i]<=rem)
	{
		v.insert(a[i]);
		ans+= call(i-1,rem-a[i]);
		if (ans>1) return 2;
		v.erase(a[i]);
	}
	ans+= call(i-1,rem);
	
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,t;
	scanf("%d",&t);
	
	for (x=1; x<=t; ++x)
	{
		int n,sum= 0;
		scanf("%d",&n);
		for (int i=1; i<=n; ++i)
		{
			cin >> a[i];
			sum+= a[i];
		}
		bool f= 0;
		for (int i=1; i<=sum; ++i)
		{
			made= 0;
			//v.empty();v1.empty();v2.empty();
			int ans= call(n,i);
			if (ans>1) {f=1; break;}
		}
		printf("Case #%d:\n",x);
		if (!f) {puts("Impossible");continue;}
		
		bool f2= 0;
		
		set <int> :: iterator i;
		
		for (i=v1.begin(); i!=v1.end();++i)
		{
			if (f2) cout<<" ";
			cout<<*i;
			f2= 1;
		}
		puts("");
		f2= 0;
		for (i=v2.begin(); i!=v2.end();++i)
		{
			if (f2) cout<<" ";
			cout<<*i;
			f2= 1;
		}
		puts("");
	}
	
	return 0;	
}
