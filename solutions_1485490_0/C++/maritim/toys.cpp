#include<stdio.h>

FILE *f = fopen("toys.in","r");
FILE *g = fopen("toys.out","w");

#define MaxN 10000
#define MaxP 3
#define ll long long

int N,T,M;
ll Box[MaxN][MaxP],Toy[MaxN][MaxP];
ll Best[MaxN][MaxN];

void citire(void)
{
	fscanf(f,"%d %d",&N,&M);
	for(int i=1;i<=N;i++)
		fscanf(f,"%lld %lld",&Box[i][0],&Box[i][1]);
	for(int i=1;i<=M;i++)
		fscanf(f,"%lld %lld",&Toy[i][0],&Toy[i][1]);
}

inline ll min(ll a,ll b)
{
	return a < b ? a : b;
}

inline ll max(ll a,ll b)
{
	return a > b ? a : b;
}

inline void Sterge(void)
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			Best[i][j] = 0;
}

inline ll Max(void)
{
	ll Sol = 0;
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			Sol = max(Sol,Best[i][j]);
			
	return Sol;
}

inline void AlunecareLaDreapta(int N,int P,ll A[][MaxP])
{
	for(int i=N;i>=P;i--)
		A[i][0] = A[i-1][0],A[i][1] = A[i-1][1];
}

inline void Spargere(void)
{
	if(Box[1][1] != Box[2][1] != Box[3][1])
		return ;
	
	for(int i=1;i<=100;i++)
	{
		ll Min = 1LL*100*1000*1000*1000*1000*1000;
		for(int j=1;j<=N;j++)
			if(Box[j][1] == i)
				Min = min(Min,Box[j][0]);
		if(Min == 1LL*100*1000*1000*1000*1000*1000)
			continue;
		
		for(int j=1;j<=N;j++)
			if(Box[j][1] == i && Box[j][0] > Min)
			{
				AlunecareLaDreapta(++N,j,Box);
				Box[j][0] =  Min;
				Box[j][1] = i;
				Box[j+1][0] -= Min;
			}
		for(int j=1;j<=M;j++)
			if(Toy[j][1] == i && Toy[j][0] > Min)
			{
				AlunecareLaDreapta(++M,j,Toy);
				Toy[j][0] = Min;
				Toy[j][1] = i;
				Toy[j+1][0] -= Min;
			}
	}
}

inline ll Rezolvare(void)
{
	Sterge();
	
	Spargere();
	
	/*for(int i=1;i<=N;i++)
		printf("%lld %lld \n",Box[i][0],Box[i][1]);
		
	printf("\n");*/
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(Box[i][1] == Toy[j][1])
				Best[i][j] = max(Best[i-1][j-1]+min(Box[i][0],Toy[j][0]),Best[i][j-1]);
			else
				Best[i][j] = max(Best[i-1][j],Best[i][j-1]);
				
	/*for(int i=1;i<=N;i++,printf("\n"))
		for(int j=1;j<=M;j++)
			printf("%lld ",Best[i][j]);*/
					
	return Best[N][M];
}

int main()
{
	fscanf(f,"%d",&T);
	for(int i=1;i<=T;i++)
	{
		citire();
		
		printf("Case #%d: %I64d\n",i,Rezolvare());
		fprintf(g,"Case #%d: %I64d\n",i,Rezolvare());
	}
}

