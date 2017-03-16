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
#include <ctime> 

using namespace std;
int a[201];
double ax[201];
int main()
{
	freopen("c-small-practice.in","r",stdin);
	freopen("c-small-attempt0.out","w",stdout);
	int t,n;
	int i,j;
	double sum=0,sum2,count;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		printf("Case #%d: ", i);
		sum=0.0;sum2=0.0;count=n;
		for(j=1;j<=n;j++)
		{	cin>>a[j];
			sum+=a[j];
		}	
		for(j=1;j<=n;j++)
		{
			ax[j]=(2.0*sum/n-a[j])/sum*100.0;
			if(ax[j]<0)
			{
				sum2-=ax[j];
				ax[j]=0;
				count--;
			}
		}
		for(j=1;j<=n;j++)
		{
		if(ax[j]==0)
			printf("%.7f ",ax[j] );
		else
			printf("%.7f ",ax[j]-sum2/count );
		}
		printf("\n");
	}
	
	
	return 0;
	
}









