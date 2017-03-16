#include<stdio.h>
#include<string.h>
#define maxn 110
int n,s,p;
int t[maxn];
int main()
{
	int cases,i,j,cnt;
	freopen("test.txt","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&cases);
	for(j=1;j<=cases;j++)
	{
		printf("Case #%d: ",j);
		scanf("%d%d%d",&n,&s,&p);
		for(i=0;i<n;i++)scanf("%d",&t[i]);
		for(i=0,cnt=0;i<n;i++)
		{
			if (t[i]>=3*p-2)cnt++;
			else if (t[i]>=2 && t[i]>=3*p-4 && t[i]<3*p-2 && s)
				s--,cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
