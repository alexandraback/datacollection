#include<stdio.h>
#include<stdlib.h>
#define sz 111
typedef unsigned u;
u *N[sz],*R[sz],*C[sz],*X,*Y,*Z;
int main()
{
	u t=0,T,n,i,j,k,l;
	for(i=-1;++i<111;)N[i]=(u*)calloc(sz,sizeof(u));
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u",&n);l=(n<<1)-1;
		for(i=-1;++i<n;)R[i]=C[i]=NULL;
		for(i=-1;++i<l;)for(j=-1;++j<n;)scanf("%u",N[i]+j);
		for(k=0;l--;++k)
		{
			for(i=j=-1,X=Y=NULL;++i<=l;)
			{
				if(N[i][k]<j)
				{
					j=N[i][k];
					X=N[i];Y=NULL;
				}
				else if(N[i][k]==j)Y=N[i];
			}
			for(i=-1;++i<k;)if(C[i]!=NULL&&C[i][k]!=X[i])break;
			if(i==k){R[k]=X;C[k]=Y;}
			if(i!=k){R[k]=Y;C[k]=X;}
			if(X)for(i=l+1;i--;)if(N[i]==X)
			{Z=N[l];N[l]=N[i];N[i]=Z;}
			if(Y)for(i=l--;i--;)if(N[i]==Y)
			{Z=N[l];N[l]=N[i];N[i]=Z;}
		}
		printf("Case #%u: ",t);
		for(i=-1;++i<n;)if(R[i]==NULL)break;
		if(i!=n)
		{
			for(j=-1;++j<n;)printf("%u%c",C[j][i],j+1!=n?' ':'\n');
			continue;
		}
		for(i=-1;++i<n;)if(C[i]==NULL)break;
		if(i!=n)
		{
			for(j=-1;++j<n;)printf("%u%c",R[j][i],j+1!=n?' ':'\n');
			continue;
		}
	}
	return 0;
}
