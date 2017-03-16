#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define LL __int64
 LL a[110],b[110],A[110],B[110];
 LL n,m,x[110];
 LL sum[110][110];

 LL min( LL a, LL b)
{
	return a>b?b:a;
}
 LL max( LL a, LL b)
{
	return a>b?a:b;
}

 LL cal()
{
	 LL i,j,tem,t1,t2,t3;
    if(n==1)
	{
		return min(a[1],sum[m][A[1]]);
	}
	if(n==2)
	{
		tem=0;
		for(i=0;i<=m;i++)
		{
			t1=min(a[1],sum[i][A[1]]);
			t2=min(a[2],sum[m][A[2]]-sum[i][A[2]]);
			tem=max(tem,t1+t2);
		}
		return tem;
	}
	if(n==3)
	{
		tem=0;
		for(i=0;i<=m;i++)
		{
			for(j=i;j<=m;j++)
			{
				t1=min(a[1],sum[i][A[1]]);
				t2=min(a[2],sum[j][A[2]]-sum[i][A[2]]);
				t3=min(a[3],sum[m][A[3]]-sum[j][A[3]]);
				tem=max(tem,t1+t2+t3);
			//	printf("i=%I64d  j=%I64d  t1=%I64d  t2=%I64d  t3=%I64d\n",i,j,t1,t2,t3);
			}
		}
		return tem;
	}
}

 int main()
{
	 LL ca,i,j,t,test=0,ans;

	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

	scanf("%I64d",&ca);
	while(ca--)
	{
		scanf("%I64d%I64d",&n,&m);
		
		for(i=1;i<=n;i++)
		{
			scanf("%I64d%I64d",&a[i],&A[i]);
		}


		memset(sum,0,sizeof(sum));
		for(i=1;i<=m;i++)
		{
			scanf("%I64d%I64d",&b[i],&B[i]);
			for(j=1;j<=100;j++) sum[i][j]=sum[i-1][j];

			sum[i][B[i]]+=b[i];
		}

		ans=cal();

		printf("Case #%I64d: %I64d\n",++test,ans);
	}

	return 0;
}
