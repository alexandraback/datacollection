#include <stdio.h>

__int64 a[5],A[5];
__int64 b[102],B[102];
__int64 re;
int n,m;

int goback(int p,int x,__int64 amnt,__int64 sum)//b위치,a위치,a양,합
{
	int i,j;

	if(x==n)
	{
		if(sum>re)
			re=sum;
		return 0;
	}
	for(i=p;i<m;i++)
	{
		if(A[x]==B[i])
		{
			if(amnt>b[i])
			{
				//버릴지 쓸지
				goback(i+1,x,amnt-b[i],sum+b[i]);
				for(j=x+1;j<=n;j++)
					goback(i+1,j,a[j],sum+b[i]);
			}
			else
			{
				b[i]-=amnt;
				for(j=x+1;j<=n;j++)
					goback(i,j,a[j],sum+amnt);
				b[i]+=amnt;
			}
			break;
		}
	}
	return 0;
}

int main()
{
	int t,tcase;
	int i,j;

	FILE *in,*out;
	in=fopen("C-small-attempt0.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		re=0;
		fscanf(in,"%d%d",&n,&m);
		for(i=0;i<102;i++)
			b[i]=B[i]=0;
		for(i=0;i<5;i++)
			a[i]=A[i]=0;
		for(i=0;i<n;i++)
			fscanf(in,"%I64d%I64d",&a[i],&A[i]);
		for(i=0;i<m;i++)
			fscanf(in,"%I64d%I64d",&b[i],&B[i]);
		//쓸지 버릴지
		for(i=0;i<n;i++)
			goback(0,i,a[i],0);
		fprintf(out,"Case #%d: %I64d\n",t+1,re);
	}


	return 0;
}