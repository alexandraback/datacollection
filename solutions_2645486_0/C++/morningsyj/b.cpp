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

int E,R,n;
int a[20];
int f[20][20];

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	int task;
	scanf("%d", &task);
	for (int _i=1;_i<=task;++_i)
	{
		scanf("%d%d%d", &E, &R, &n);
		for (int i=1;i<=n;++i)
			scanf("%d", &a[i]);
		for (int i=0;i<=n;++i)
			for (int j=0;j<=E;++j)
				f[i][j]=-(1<<29);
		f[0][E]=0;
		for (int i=0;i<n;++i)
			for (int j=0;j<=E;++j)
				for (int k=0;k<=j+R&&k<=E;++k)
					if (f[i][j]+k*a[i+1]>f[i+1][min(j+R-k,E-k)])
						f[i+1][min(j+R-k,E-k)]=f[i][j]+k*a[i+1];
/*		for (int i=0;i<=n;++i)
			for (int j=0;j<=E;++j)
				printf("f[%d][%d] = %d\n", i, j, f[i][j]);*/
		int ans=0;
		for (int j=0;j<=E;++j)
			if (f[n][j]>ans)
				ans=f[n][j];
		printf("Case #%d: %d\n",_i,ans);
	}


	return 0;
}
