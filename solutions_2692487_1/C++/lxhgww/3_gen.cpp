#include<stdio.h>
#include<algorithm>

using namespace std;

int b[101];

int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,p;
	int n,i;
	int a;
	int mm;
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&a,&n);
		for (i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort (b+1,b+n+1);
		if (a==1)
		{
			printf("Case #%d: %d\n",p,n);
			continue;
		}
		mm=n;
		int s=0;
		for (i=1;i<=n;i++)
		{
			if (a>b[i]) a=a+b[i];
			else
			{
				if (s+n-i+1<mm) mm=s+n-i+1;
				s++;
				a=2*a-1;
				i--;
			}
		}
		if (s<mm) mm=s;
		printf("Case #%d: %d\n",p,mm);
	}
	return 0;
}