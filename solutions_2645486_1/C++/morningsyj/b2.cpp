#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define ST begin()
#define ED end()
#define XX first
#define YY second
#define elif else if 
#define foreach(i,x) for (__typeof((x).ST) i=(x).ST;i!=(x).ED;++i) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef pair<int,int> PII;

const int N = 20005;

int E,R,n;
int a[N], q[N];
ll u[N], v1[N], v2[N];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	int task;
	scanf("%d", &task);
	for (int _i=1;_i<=task;++_i)
	{
		scanf("%d%d%d", &E, &R, &n);
		for (int i=1;i<=n;++i)
			scanf("%d", &a[i]);
		/*
		for (int i=0;i<=m;++i)
			f[i]=0;
		for (int i=1;i<=n;++i)
		{
			int x=E+(i-1)*R;
			for (int j=(i-1)*R;j<x;++j)
				if (f[j]+a[i]>f[j+1])
					f[j+1]=f[j]+a[i];
		}*/
		int st=1,ed=0;
		for (int i=1;i<=n;++i)
		{
			while (ed>=st&&a[i]>a[q[ed]])
			{
				if (v1[ed]<=1LL*R*(i-1))
				{
					v2[ed]=1LL*R*(i-1);
					break;
				}
				--ed;
			}
			q[++ed]=i;
			u[ed]=u[ed-1]+(v2[ed-1]-v1[ed-1]+1)*a[q[ed-1]];
			v1[ed]=v2[ed-1]+1;
			v2[ed]=1LL*R*(i-1)+E;
		}
		cout<<"Case #"<<_i<<": "<<u[ed]+(v2[ed]-v1[ed]+1)*a[q[ed]]<<endl;
	}


	return 0;
}
