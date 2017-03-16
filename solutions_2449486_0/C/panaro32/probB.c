#include <stdio.h>
#include <stdlib.h>

typedef struct{ int x,y,v; } seg;

int** scan(int*,int*);
int segcmp(const void*,const void*);
int solve(int**,int,int);

int main()
{
	int T,N,M,i,**a;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		a=scan(&N,&M);
		printf("Case #%d: %s\n",i+1,solve(a,N,M)?"YES":"NO");
	}
	return 0;
}

int** scan(int *N,int *M)
{
	int i,j;
	scanf("%d%d",N,M);
	int **a=(int**)malloc(*N*sizeof(int*));
	for(i=0;i<*N;i++) a[i]=(int*)malloc(*M*sizeof(int));
	for(i=0;i<*N;i++) for(j=0;j<*M;j++) scanf("%d",&a[i][j]);
	return a;
}

int segcmp(const void *a,const void *b)
{
	return ((seg*)a)->v-((seg*)b)->v;
}

int solve(int **a,int N,int M)
{
	int i,j,X,Y,size=N*M,pos=1;
	int **f=(int**)malloc(N*sizeof(int));
	for(i=0;i<N;i++) f[i]=(int*)malloc(M*sizeof(int));
	seg *s=(seg*)malloc(size*sizeof(seg));
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
		{
			f[i][j]=1;
			s[i*M+j].x=i;
			s[i*M+j].y=j;
			s[i*M+j].v=a[i][j];
		}
	qsort(s,size,sizeof(seg),&segcmp);
	for(j=0;j<size && pos;j++)
	{
		if(f[s[j].x][s[j].y])
		{
			for(X=1,i=0;i<N;i++) if(a[i][s[j].y]>s[j].v) X=0;
			for(Y=1,i=0;i<M;i++) if(a[s[j].x][i]>s[j].v) Y=0;
			if(!X && !Y) pos=0;
			if(X) for(i=0;i<N;i++) f[i][s[j].y]=0;
			if(Y) for(i=0;i<M;i++) f[s[j].x][i]=0;
		}
	}
	free(s);
	for(i=0;i<N;i++) free(f[i]);
	for(i=0;i<N;i++) free(a[i]);
	free(f); free(a);
	return pos;
}
