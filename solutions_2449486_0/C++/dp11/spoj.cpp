#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%lld",&x)
#define ul(x) scanf("%lld",&x)
int array[101][101];
int ROW[101],COLUMN[101];
int N,M;
void Solve()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{	
			if((array[i][j]==ROW[j]) || (array[i][j]==COLUMN[i]))
				continue;
			else
			{
				printf("NO\n");
				return;
			}
		}
	printf("YES\n");
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int tes=1;tes<=test;tes++)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				scanf("%d",&array[i][j]);
		for(int i=0;i<N;i++)
		{
			COLUMN[i]=array[i][0];
			for(int j=0;j<M;j++)
				COLUMN[i]=max(COLUMN[i],array[i][j]);
		}
		for(int i=0;i<M;i++)
		{
			ROW[i]=array[0][i];
			for(int j=0;j<N;j++)
				ROW[i]=max(ROW[i],array[j][i]);
		}
		printf("Case #%d: ",tes);
		Solve();
	}
	return 0;
}