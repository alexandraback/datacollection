#include<stdio.h>
#include<memory.h>
#include<algorithm>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
int A[101],N,M;
int D[101][301];
int T;
int main()
{
	int t;
	fscanf(in,"%d",&T);
	int i,j;
	int x,y;
	for(t=1;t<=T;t++)
	{
		fscanf(in,"%d %d",&M,&N);
		for(i=1;i<=N;i++) fscanf(in,"%d",&A[i]);
		std::sort(A+1,A+1+N);
		memset(D,0,sizeof(D));
		D[0][0]=M;
		for(i=1;i<=N;i++)
		{
			for(j=0;j<=300;j++)
			{
				if(D[i-1][j])
				{
					if(A[i]<D[i-1][j])
					{
						if(D[i][j]<D[i-1][j]+A[i]) D[i][j]=D[i-1][j]+A[i];
					}
					else
					{
						x=D[i-1][j]; y=0;
						while(A[i]>=x&&j+y<=N)
						{
							x=x*2-1;
							y++;
						}
						if(A[i]<x)
						{
							if(D[i][j+y]<x+A[i]) D[i][j+y]=x+A[i];
						}
					}
					if(D[i][j+1]<D[i-1][j]) D[i][j+1]=D[i-1][j];
				}
			}
		}
		for(i=0;i<=300;i++) if(D[N][i]) break;
		fprintf(out,"Case #%d: %d\n",t,i);
	}
}