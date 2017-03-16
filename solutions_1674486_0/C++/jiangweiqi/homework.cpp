#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <string.h>

using namespace std; 
#define N 100001
#define MOD 1000000007
typedef long long ll;


/*bool arr[N];
void prim()
{
arr[0]=1;
arr[1]=1;
int i;
ll j;
for(i=2;i<N;i++)
{
if(arr[i]==0)
{
for(j=i,j=j*i;j<N;j+=i)
{
arr[j]=1;
}
}
}
}*/
/*int gcd(int m, int n) {
while (true) {
if ((m = m % n) == 0) return n;
if ((n = n % m) == 0) return m;
}
}*/

inline void file()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
}
struct stu
{
	int one,two;
}pi[1005];
bool cmp(stu a,stu b)
{
	if(a.one==b.one)return a.two>b.two;
	return a.one<b.one;
}
bool cmp1(stu a,stu b)
{
	if(a.two==b.two)return a.one>b.one;
	return a.two<b.two;
}
int rec[1005][1005];
bool ans,flag[1005];
int n;
void dfs(int a)
{
	if(flag[a]==1)ans=1;
	else
		flag[a]=1;
	if(ans==1)return;
	int i;
	for(i=1;i<=rec[a][0];i++)
	{
		if(ans==1)return ;
		dfs(rec[a][i]);
	}
}
int main()
{
	file();
	int T,cas;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		int i,n,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&rec[i][0]);
			for(j=1;j<=rec[i][0];j++)
			{
				scanf("%d",&rec[i][j]);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			memset(flag,0,sizeof(flag));
			dfs(i);
			if(ans==1)break;
		}
		if(ans==0)printf("Case #%d: No\n",cas);
		else printf("Case #%d: Yes\n",cas);
	}
	return 0;
}

