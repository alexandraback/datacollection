#include <cstdio>
#include <algorithm>
using namespace std;
int t,z,i;
int per,n,a[110],sur,p;

int main ()
{
	//freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		per=0;
		scanf("%d%d%d",&n,&sur,&p);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=n-1;i>=0;i--)
		{
			if(a[i]>=3*p-2)per++;
			else if(3*p-4>0) if(a[i]>=3*p-4) if(sur>0){sur--;per++;}
		}
		printf("Case #%d: %d\n",z,per);
	}
	
	return 0;
}
