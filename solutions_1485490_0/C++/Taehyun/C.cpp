#include<stdio.h>
#include<memory.h>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
__int64 D[201][201];
struct LIST
{
	__int64 x,y;
};
LIST A2[301],A[301];
LIST B2[301],B[301];
int N,M;
int main()
{
	int t,T;
	fscanf(in,"%d",&T);
	int i,j,k,l;
	int N2,M2;
	__int64 S1,S2,S;
	int x;
	for(t=1;t<=T;t++)
	{
		N=M=0;
		memset(D,0,sizeof(D));
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d %d",&N2,&M2);
		for(i=1;i<=N2;i++) fscanf(in,"%I64d %I64d",&A2[i].x,&A2[i].y);
		for(i=1;i<=M2;i++) fscanf(in,"%I64d %I64d",&B2[i].x,&B2[i].y);
		A[++N].x=A2[1].x; A[N].y=A2[1].y;
		for(i=2;i<=N2;i++)
		{
			if(A[N].y==A2[i].y) A[N].x+=A2[i].x;
			else
			{
				A[++N].x=A2[i].x;
				A[N].y=A2[i].y;
			}
		}
		B[++M].x=B2[1].x; B[M].y=B2[1].y;
		for(i=2;i<=M2;i++)
		{
			if(B[M].y==B2[i].y) B[M].x+=B2[i].x;
			else
			{
				B[++M].x=B2[i].x;
				B[M].y=B2[i].y;
			}
		}
		for(i=1;i<=N+1;i++)
		{
			for(j=1;j<=M+1;j++)
			{
				if(i==N+1&&j==M+1) break;
				if(A[i].y!=B[j].y)
				{
					if(D[i][j+1]<D[i][j]) D[i][j+1]=D[i][j];
					if(D[i+1][j]<D[i][j]) D[i+1][j]=D[i][j];
				}
				else
				{
					k=i; l=j;
					S=0;
					S1=A[i].x; S2=B[j].x;
					x=A[i].y;
					while(k<=N&&l<=M)
					{
						if(S1<S2) 
						{
							S+=S1,S2-=S1,S1=0;
							k++;
							while(k<=N&&x!=A[k].y) 
							{
								if(D[k][l+1]<D[i][j]+S) D[k][l+1]=D[i][j]+S;
								k++;
							}
							if(D[k][l+1]<D[i][j]+S) D[k][l+1]=D[i][j]+S;
							if(A[k].y==x) S1+=A[k].x;
						}
						else 
						{
							S+=S2,S1-=S2,S2=0;
							l++;
							while(l<=M&&x!=B[l].y)
							{
								if(D[k+1][l]<D[i][j]+S) D[k+1][l]=D[i][j]+S;
								l++;
							}
							if(D[k+1][l]<D[i][j]+S) D[k+1][l]=D[i][j]+S;
							if(B[l].y==x) S2+=B[l].x;
						}
					}
				}
			}
		}
		fprintf(out,"%I64d\n",D[N+1][M+1]);
	}
}