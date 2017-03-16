#include<iostream>
#include<algorithm>
using namespace std;
int a[21];
int hash[1000011];
int  cmp(int j)
{
	int sum=0,i, t=19;
	for(i=1<<19;i;i>>=1)
	{
		if(j&i)
		{
			sum+=a[t];
		}
		t--;
	}
	return sum;
}

int  output(int  tmp, int  j)
{
		int i,t=19, flag=0;
		for(i=1<<19;i;i>>=1)
		{
			if(j&i)
			{
				if(flag)printf(" ");
				else flag=1;
				printf("%d",a[t]);
				
			}
			t--;
		}
		printf("\n");
		t=19; 
		flag=0;
		for(i=1<<19;i;i>>=1)
		{
			if(tmp&i)
			{
				if(flag)printf(" ");
				else flag=1;
				printf("%d",a[t]);
				
			}
			t--;
		}
		printf("\n");
		return 0;
}
int main()
{
    int i,j,T,N;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d",&T);
	for(i=1;i<=T;++i)
	{
		printf("Case #%d:\n",i);
		scanf("%d",&N);
		for(j=0;j<1000010;++j) hash[j]=0;
		for(j=0;j<N;++j) scanf("%d",&a[j]);
		N=1<<20;
		int ok=0;
		for(j=1;j<N-1;++j)
		{
		     int tmp=cmp(j);
			 if(hash[tmp]!=0)
			 {
				// printf("%d %d\n", cmp(hash[tmp]), tmp);
				 output(hash[tmp],j);
				 ok=1;
			 }
			 else 
			 {
				  hash[tmp]=j;
				  continue;
			 }
			 if(ok==1) break;
		}
		if(ok==0) printf("Impossible\n");


	}
    return 0;
}