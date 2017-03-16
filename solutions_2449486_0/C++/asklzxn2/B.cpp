#include<cstdio>
int Case,T,flag,N,M,i,j,tmp;
int A[105][105],B[105],C[105];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	for(scanf("%d",&T);T--;)
	{
		++Case;
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;++i) B[i]=0;
		for(i=1;i<=M;++i) C[i]=0;
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
			{
				scanf("%d",&A[i][j]);
				if(A[i][j]>B[i]) B[i]=A[i][j];
				if(A[i][j]>C[j]) C[j]=A[i][j];
			}
		flag=1;
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
			{
				if(B[i]<C[j]) tmp=B[i];
				else tmp=C[j];
				if(A[i][j]!=tmp) flag=0;
			}
		if(flag) printf("Case #%d: YES\n",Case);
		else printf("Case #%d: NO\n",Case);
	}
	return 0;
}
