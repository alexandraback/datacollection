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
int main()
{
	file();
	int T,cas;
	int n,i;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&pi[i].one,&pi[i].two);
		}
		int ans=0,allstar=0;
		sort(pi,pi+n,cmp);
		
		for(i=0;i<n;i++)
		{
			if(allstar>=pi[i].one)
			{
				ans++;
				allstar++;
			}
			else break;
		}
		if(i!=n)ans=N;
		else
		{
			allstar++;
			sort(pi,pi+n,cmp1);
			for(i=0;i<n;i++)
			{
				if(allstar>=pi[i].two)
				{
					ans++;
					allstar++;
				}
				else break;
			}
			if(i!=n)ans=N;
		}
		ans=N;
		int lever=0,nans=0,all=0;
		allstar=0;
		while(lever<n)
		{
			sort(pi,pi+n,cmp1);
			if(pi[0].two<=allstar)
			{
				if(pi[0].one!=N)
				{
					allstar+=2;
				}
				else allstar++;
				lever++;
				all++;
				nans++;
				pi[0].two=N;
				continue;
			}
			sort(pi,pi+n,cmp);
			if(pi[0].one<=allstar)
			{
				allstar++;
				nans++;
				pi[0].one=N;
				if(all==0&&(n==1 || pi[1].one==N))allstar++;
				continue;
			}
			break;
		}
		ans=min(ans,nans);
		if(lever==n)
		{
			printf("Case #%d: %d\n",cas,ans);
		}
		else printf("Case #%d: Too Bad\n",cas);
	}
	return 0;
}

