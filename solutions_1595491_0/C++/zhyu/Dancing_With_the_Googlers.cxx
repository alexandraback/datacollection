#include <cstdio>
#include <algorithm>
using namespace std;

int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main(void)
{
	int t,n,s,p;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%d%d%d",&n,&s,&p);
		int res=0;
		for(int i=0;i<n;i++)	scanf("%d",a+i);
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(a[i]>=p && a[i]>=3*p-2)	res++;
			else	if(s && a[i]>=p && a[i]>=3*p-4)
			{
				res++;
				s--;
			}
		}
		printf("Case #%d: %d\n",cas,res);
	}
	return 0;
}
