#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
int a,b,c;
int d[1009];
void input()
{
	int i, j, k;
	for(i=0;i<1009;i++)
		d[i] = 0;
	scanf("%d %d %d",&a,&b,&c);
}
void process()
{
	int i, j, k;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			d[i&j]++;
	k=0;
	for(i=0;i<c;i++)
		k+=d[i];
	printf("%d",k);
}
int main()
{
	int t, tv;
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small-attempt0.out","wt",stdout);
	scanf("%d",&t);
	tv = 0;
	while(t--)
	{
		tv++;
		input();
		printf("Case #%d: ",tv);
		process();
		printf("\n");
	}
}