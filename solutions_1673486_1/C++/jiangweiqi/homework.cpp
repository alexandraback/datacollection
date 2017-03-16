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
double pi[100000];
int main()
{
	file();
	int T,cas;
	int a,b,i;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d %d",&a,&b);
		for(i=0;i<a;i++)
		{
			scanf("%lf",&pi[i]);
		}
		double ans=b+2.0;
	//	cout<<ans<<endl;
		double npi=1.0;
		for(i=0;i<a;i++)
		{
			npi*=pi[i];
		}
		ans=min(ans,npi*(b-a+1.0)+(1.0-npi)*(b+2.0+b-a));
	//	cout<<ans<<endl;
		for(i=1;i<=a;i++)
		{
			npi/=pi[a-i];
			ans=min(npi*(i+b-a+i+1.0)+(1.0-npi)*(i+b-a+i+1.0+b+1.0),ans);
	//		cout<<ans<<endl;
		}
		printf("Case #%d: %.6lf\n",cas,ans);
	}
	return 0;
}