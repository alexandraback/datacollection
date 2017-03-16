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
		return y<b.y;	
	}
};
const int inf = 0x3f3f3f3f; 
const double eps = 1e-15;
const double pi = acos((double)-1) ;
const int maxn = 100100;
const ll M = 1e9+7;
ll i,j,k,l,m,n,x,y,z,s,p,num;
stu a[100][100]={0};
stu ans[maxn];
int v[maxn]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
map<int,int>m1;
map<int,int>m2;
map<int,int>m3;
map<int,int>m4;

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
	
	    freopen("C-small-attempt0 (2).in","r",stdin);
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
		m0(a);
		num=0;
		m1.clear();
		m2.clear();
		m3.clear();
		scanf("%d%d%d%d",&j,&p,&s,&k);
		printf("Case #%d: ",casi);
		//C4(j,p,s,k);
		for (int i=1;i<=j;i++)
		{
			for (int jj=0;jj<s;jj++)
			{
				a[i][jj].x=jj+1;
				a[i][jj].y=0;
			}
		}
		
		for (int i=1;i<=j;i++)
		{
			for (int jj=1;jj<=p;jj++)
			{
				sort(a[i],a[i]+s);
				/*
				C1("---------------");
				for (int kk=1;kk<=s;kk++) C2(a[i][kk-1].x,a[i][kk-1].y);
				C1("---------------");
				*/
				for (int kk=1;kk<=s;kk++)
				{
					int q=a[i][kk-1].x;
					int aa=i*10+jj;
					int bb=i*10+q;
					int cc=jj*10+q;
					if (m1[aa]>=k || m2[bb]>=k || m3[cc]>=k) continue;
					m1[aa]++;
					m2[bb]++;
					m3[cc]++;
					a[i][kk-1].y++;
					num++;
					ans[num].x=i;
					ans[num].y=jj;
					ans[num].z=q;
				}
			}
		}
		printf("%d\n",num);
		for (int i=1;i<=num;i++)
		{
			printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
		}
	}
	
	
	return 0;
}
