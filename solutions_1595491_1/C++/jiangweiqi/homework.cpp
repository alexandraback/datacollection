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
/*int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int t,i,cas,a,b,j,ii;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		int ans=0;
		scanf("%d %d",&a,&b);
		for(i=a;i<=b;i++)
		{
			if(i<10)continue;
			int k=1,tx=i,wei=0;
			while(tx)
			{
				wei++;
				k*=10;
				tx/=10;
			}
			k/=10;tx=i;
			vector<int>q;
			q.clear();
			for(j=1;j<wei;j++)
			{
				int ttx=tx;
				tx= ( ttx%10 ) * k +ttx/10;
				if(tx!=i && tx>=a && tx<=b)
				{
					for(ii=0;ii<q.size();ii++)
					{
						if(tx==q[ii])break;
					}
					if(ii==q.size())
					{
						ans++;
						q.push_back(tx);
					}
				}
			}
		}
		printf("Case #%d: %d\n",cas,ans/2);
	}
	return 0;
}*/

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int tx,t,n,s,p,arr[105],ans,cas,i,mod;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		scanf("%d %d %d",&n,&s,&p);
		for(i=0;i<n;i++)scanf("%d",&arr[i]);
		ans=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]<2)
			{
				tx=arr[i];
				if(tx>=p)ans++;
			}
			else
			{
				tx=arr[i]/3;
				mod=arr[i]%3;
				if(mod!=0)tx++;
				if(tx>=p)
				{
					ans++;
					continue;
				}
				if(s>0)
				{
					if(mod!=1)tx++;
					if(tx>=p)
					{
						ans++;
						s--;
					}
				}
			}
		}
		printf("Case #%d: %d\n",cas,ans);
	}
}