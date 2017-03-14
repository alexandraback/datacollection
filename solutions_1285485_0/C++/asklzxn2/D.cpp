#include<cstdio>
#include<cstring>
int T,i,j,i1,j1,N,M,d,Stn,Stm,XX,YY,f1,f2,Ans,p,test,u;
char A[40][40],B[40][40],C[40][40],D[40][40],line[40];
char Map[200][200];
bool f[200][200][5],g[5];
int abs(int a)
{
	if(a<0) return -a;
	return a;
}
int dis(int x,int y)
{
	return x*x+y*y;
}
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
} 
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	for(test=1;test<=T;++test)
	{
		scanf("%d%d%d",&N,&M,&d);
		gets(line);
		for(i=0;i<N;++i) gets(A[i]);
		for(i=1;i<N-1;++i)
			for(j=1;j<M-1;++j)
				B[i][j]=A[i][M-j-1];
		for(i=1;i<N-1;++i)
			for(j=1;j<M-1;++j)
				C[i][j]=A[N-i-1][j];
		for(i=1;i<N-1;++i)
			for(j=1;j<M-1;++j)
				D[i][j]=B[N-i-1][j];
		N-=2,M-=2;
		Stn=d/N+2,Stm=d/M+2;
		for(i=1;i<=2*d/N+3;++i)
			for(j=1;j<=2*d/M+3;++j)
			{
				f1=abs(Stn-i)&1;
				f2=abs(Stm-j)&1;
				if(!f1&&!f2)
				{
					for(i1=1;i1<=N;++i1)
						for(j1=1;j1<=M;++j1)
							Map[(i-1)*N+i1][(j-1)*M+j1]=A[i1][j1];
				}
				if(!f1&&f2)
				{
					for(i1=1;i1<=N;++i1)
						for(j1=1;j1<=M;++j1)
							Map[(i-1)*N+i1][(j-1)*M+j1]=B[i1][j1];
				}
				if(f1&&!f2)
				{
					for(i1=1;i1<=N;++i1)
						for(j1=1;j1<=M;++j1)
							Map[(i-1)*N+i1][(j-1)*M+j1]=C[i1][j1];
				}
				if(f1&&f2)
				{
					for(i1=1;i1<=N;++i1)
						for(j1=1;j1<=M;++j1)
							Map[(i-1)*N+i1][(j-1)*M+j1]=D[i1][j1];
				}
			}
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
				if(A[i][j]=='X')
				{
					Stn=(Stn-1)*N+i;
					Stm=(Stm-1)*M+j;
				}
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		Ans=0;
		for(i=1;i<=(2*d/N+3)*N;++i)
			for(j=1;j<=(2*d/M+3)*M;++j)
				if(Map[i][j]=='X')
				{
					XX=abs(i-Stn),YY=abs(j-Stm);
					if(XX==0&&YY==0) continue;
					if(XX==0)
					{
						if(YY>d) continue;
						if(j<Stm)
						{
							if(!g[1]) ++Ans,g[1]=1;
						}
						else
						{
							if(!g[2]) ++Ans,g[2]=1;
						}
						continue;
					}
					if(YY==0)
					{
						if(XX>d) continue;
						if(i<Stn)
						{
							if(!g[3]) ++Ans,g[3]=1;
						}
						else
						{
							if(!g[4]) ++Ans,g[4]=1;
						}
						continue;
					}
					if(i<Stn&&j<Stm) u=1;
					if(i<Stn&&j>Stm) u=2;
					if(i>Stn&&j<Stm) u=3;
					if(i>Stn&&j>Stm) u=4;
					if(dis(XX,YY)<=d*d)
					{
						p=gcd(XX,YY);
						XX/=p,YY/=p;
						if(!f[XX][YY][u]) ++Ans,f[XX][YY][u]=1;
					}
				}
		printf("Case #%d: %d\n",test,Ans);
	}
	return 0;
}
