#include<cstdio>
#define LL long long
int A[18];
int main()
{
	LL L;
	int i,j,k,x,cnt;
	freopen("c.out","w",stdout);
	printf("Case #1:\n");
	cnt=0;
	for (i=32769;i<=65535;i+=2)
	{
		x=i;
		for (j=15;j>=0;j--)
		{
			A[j]=x%2; x/=2;
		}
		for (j=0;j<=15;j++) printf("%d",A[j]);
		for (j=0;j<=15;j++) printf("%d",A[j]);
		for (j=2;j<=10;j++)
		{
			L=0;
			for (k=0;k<=15;k++) L=L*j+A[k];
			printf(" %I64d",L);
		}
		printf("\n");
		cnt++;
		if (cnt>=500) return 0;
	}
}
