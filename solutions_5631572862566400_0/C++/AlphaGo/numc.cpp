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
#define C1(x)  cout<<x<<endl;
#define C2(x,y)  cout<<x<<" "<<y<<endl;
#define C3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl;
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
const int maxn = 100100;
const ll M = 1e9+7;
int i,j,k,l,m,n,x,y,z,ans,num,aa;
int a[maxn]={0};
int v[maxn]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


void dfs(int f,int x,int z)
{
	//printf("%d  %d  %d\n",f,x,z);
	if (x==aa) 
	{
		if (ans<z+1) ans=z+1;
		//printf ("ans£º%d\n",z+1);
		return ;
	}
	
	if (v[x]==1) 
	{
		//printf("fail\n") ;
	return ;
	}
	 
	v[x]=1;

	if (a[x]==f) 
	{
		//printf(" rwer ");
		//for (int i=1;i<=n;i++) printf("v[i]=%d  ",v[i]);printf("\n");
		for (int i=1;i<=n;i++)
		{
			if (v[i]==0) 
			{
				dfs(x,i,z+1);
			}
		}
			
		if (ans<z+2) ans=z+2;
		//printf ("ans£º%d\n",z+1);
		return ;
	}
	//v[x]=0;
	dfs(x,a[x],z+1);
	v[x]=0;
	return ;
}

int main () 
{
	#ifdef ONLINE_JUDGE
	
	#else
	
	    freopen("C-small-attempt2.in","r",stdin);
		freopen("in.out","w",stdout);
	
	#endif
	int cas;
	scanf("%d",&cas);
	for (int casi=1;casi<=cas;casi++)
	{
		//printf("\n");
		scanf("%d",&n);
		ans=0;
		
		
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		//for (int i=1;i<=n;i++)printf("%d ",a[i]);cout<<endl;
		
		for (int i=1;i<=n;i++)
		{//printf("%d\n",i);
			for (int j=1;j<=n;j++) v[j]=0;
			aa=i;
			dfs(i,a[i],1);
			//printf("  \n");
		}
		
		
		printf("Case #%d: %d\n",casi,ans-1);
		
	}
	return 0;
}
