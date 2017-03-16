#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

FILE *f = fopen("diamonds.in","r");
FILE *g = fopen("diamonds.out","w");

typedef vector<int>::iterator it;

#define MaxN 1010

int N,T,M,viz[MaxN];
vector<int> A[MaxN];

void citire(void)
{
	int a;
	
	fscanf(f,"%d",&N);
	for(int i=1;i<=N;i++)
	{
		A[i].clear();
		fscanf(f,"%d",&M);
		for(int j=1;j<=M;j++)
		{
			fscanf(f,"%d",&a);
			A[i].push_back(a);
		}
	}
}

inline void Sterge(int C[])
{
	for(int i=1;i<=N;i++)
		C[i] = 0;
}

inline int Lee(int a)
{
	queue<int> Q;
	
	viz[a] = 1;
	
	for(Q.push(a);!Q.empty();Q.pop())
		for(it i=A[Q.front()].begin();i<A[Q.front()].end();i++)
			if(!viz[*i])
			{
				viz[*i] = 1;
				Q.push(*i);
			}
			else
				return 1;
				
	return 0;
}

inline int Rezolvare(void)
{
	for(int i=1;i<=N;i++)
	{
		Sterge(viz);
		if(Lee(i))
			return 1;
	}
	
	return 0;
}

int main()
{
	fscanf(f,"%d",&T);
	for(int i=1;i<=T;i++)
	{
		citire();
		if(Rezolvare())
			fprintf(g,"Case #%d: Yes\n",i);
		else
			fprintf(g,"Case #%d: No\n",i);
	}
}
