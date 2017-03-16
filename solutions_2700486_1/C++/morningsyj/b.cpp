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

const int N = 10005;

int n,x,y,p,q,m,h;
double ans;
double f[N+5][N+5];

void dfs(int n, int l, int r, double pr)
{
	if (l>y) {printf("%d %d %.4lf\n", l, r, pr);ans+=pr;return;}
	if (n==0) return;
	dfs(n-1,l+1,r,pr*(0.5+(r+1==h)));
	if (r+1<h) dfs(n-1,l,r+1,pr*0.5);
}

int main()
{
//	freopen("b.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	int task;
	scanf("%d", &task);
	for (int _i=1;_i<=task;++_i)
	{
		scanf("%d%d%d", &n, &x, &y);
		ans=0;
		if (x<0) x=-x;
		if (!(x+y&1))
		{
			m=0;
			for (int i=0,j=1;i<=x+y;i+=2,j=(i-1)*2+3)
			{
				if (i==x+y)
				{
//					printf("%d %d %d\n", n, m,j);
					p=n-m;
					q=j;
					break;
				}
				m+=j;
				if (m>n)
				{
					p=-1;
					q=0;
					break;
				}
			}
//			printf("%d %d %d\n", n, p, q);
			if (p>=q)
				ans=1;
			else
			if (0<p&&x!=0)
			{
				if (p==q-1)
					ans=1;
				else
				{
					h=x+y;
					f[0][0]=1;

	for (int i=0;i<=h;++i)
		for (int j=0;j<=h;++j) if (i+j)
		{
			f[i][j]=0;
			if (i)
				f[i][j]+=f[i-1][j]*(0.5+0.5*(j==h));
			if (j)
				f[i][j]+=f[i][j-1]*(0.5+0.5*(i==h));
//			printf("%d %d %.3lf\n", i, j, f[i][j]);
//			f[i][j]=f[i][j-1]*0.5+f[i-1][j]*0.5;
		}

					for (int i=max(p-h,0);i<=y;++i)
						ans+=f[i][p-i];
					ans=1-ans;
				}
			}
		}
			
		printf("Case #%d: %.10lf\n",_i,ans);
	}


	return 0;
}
