#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[110],b[110],memo[110][110];
int A[110],B[110],N,M;
long long find(int i1,int i2)
{
	if (memo[i1][i2]!=-1)
		return memo[i1][i2];
		
	if (i1==N || i2==M)
		return memo[i1][i2]=0;
	
	if (A[i1]!=B[i2])
	{
		return memo[i1][i2]=\
			max(find(i1+1,i2),find(i1,i2+1));
	}
	else
	{
		if (a[i1]==b[i2])
			return memo[i1][i2]=a[i1]+find(i1+1,i2+1);
		
		long long curb=0,cura=0;
		memo[i1][i2]=0;
		for (int i=i1;i<N;i++)
		{
			curb=0;
			if (A[i]==A[i1])
				cura+=a[i];
			for (int j=i2;j<M;j++)
			{
				if (B[j]==B[i2])
				{
					//assert(B[j]==A[i1]);
					curb+=b[j];
					memo[i1][i2]=max(memo[i1][i2],find(i+1,j+1)+min(cura,curb));
				}
			}
		}
		return memo[i1][i2];
	}
}
int main()
{
    freopen("C-large.in","r",stdin);
	//freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++) scanf("%lld%d",&a[i],&A[i]);
		for(int i=0;i<M;i++) scanf("%lld%d",&b[i],&B[i]);
		for(int i=0;i<N+1;i++)
		for(int j=0;j<M+1;j++) memo[i][j]=-1;
		printf("Case #%d: %lld\n",t,find(0,0));
    }
    return 0;
}

