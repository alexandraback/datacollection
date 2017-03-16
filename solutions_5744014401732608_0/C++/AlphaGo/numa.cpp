#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <vector>
#include <ctime>
#include <cctype>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <utility> 
using namespace std;
#define ll long long 
#define m0(a) memset(a, 0, sizeof(a))
#define m1(a) memset(a, -1, sizeof(a))
#define C1(x)  cout<<x<<endl
#define C2(x,y)  cout<<x<<" "<<y<<endl
#define C3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define C4(x,y,z,zz)  cout<<x<<" "<<y<<" "<<z<<" "<<zz<<endl
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))
#define r() (rand()/(double)(RAND_MAX))
struct stu
{
	int x,y,z;
	bool operator < (const stu &b) const
	{
		return x<b.x;	
	}
};
const int inf = 0x3f3f3f3f; 
const double eps = 1e-15;
const double pi = acos((double)-1) ;
const int maxn = 70;
const ll M = 1e9+7;
ll i,j,k,l,m,n,x,y,z,ans,num;
int a[maxn][maxn]={0};
int v[maxn]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
string s;
ll gcd(ll x,ll y)
{
	if (x==0 || y==0)  return x+y;
	return (x%y==0)?y:gcd(y,x%y);
}
int main () 
{
	srand((unsigned)time(NULL));
	#ifdef ONLINE_JUDGE
	
	#else
	
	    freopen("B-small-attempt1 (2).in","r",stdin);
	    freopen("in.out","w",stdout);
	
	#endif
	int cas;
	/*
	while (scanf("%d",&x)!=EOF) 
	{
		C1(x);
	}
	*/
	
	scanf("%d",&cas);
	for (int casi=1;casi<=cas;casi++)
	{
		cin>>n>>m;
		printf("Case #%d: ",casi);
		
		for (int i=1;i<=n;i++)
		{
			v[i-1]=0;
			for (int j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		if (m>((ll)1<<(n-2))) {
			printf("IMPOSSIBLE\n");
			continue;
			
		}
		printf("POSSIBLE\n");
		//C2(n,m);
		z=n;
		for (int i=1;i<=n-1;i++)
		{
			for (int j=i+1;j<=n-1;j++)
			{
				a[i][j]=1;
			}
		}
		l=(ll)1<<(n-3);
		for (int i=n-3;i>=0;i--)
		{
			l=(ll)1<<(i);
			//C2(m,l);
			if (m>=l)
			{
				a[i+2][z]=1;
				m=m-l;
			}
			
		}
		if (m>0) a[1][n]=1;
		for (int i=1;i<=z;i++)
		{
			for (int j=1;j<=z;j++)
			{
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
		
	}
	return 0;
}
