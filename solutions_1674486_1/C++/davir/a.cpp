#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <limits.h>
#include <cstdlib>
#define PI 3.14159265358979323846264338327950288419716939937510
#define MIN(i,j) (i<j?i:j)
#define MIN3(i,j,k) (i<j?MIN(i,k):MIN(j,k))
#define MAX(i,j) (i>j?i:j)
#define MAX3(i,j,k) (i>j?MAX(i,k):MAX(j,k))
#define REP(x) for(int i=0;i<x;i++)
using namespace std;
inline double comb(int n, int k);

typedef struct node_
{
	struct node_ *neig[1024];
	int nn;	
	bool visited;
}node;
node *C[1024];
node *next[1024+1000];
int nsize;
bool bfs(node *ni)
{
	for(int i=0;i<ni->nn;i++)
	{
		if(ni->neig[i]->visited)
			return true;
		next[nsize++] = ni->neig[i];
		ni->neig[i]->visited = true;
	}
	ni->visited = true;
	while(nsize > 0)
	{
		bool ret = bfs(next[--nsize]);
		if(ret) return true;
	}
	return false;
}
void solve_problem()
{
	int n,nn, i, j;
	nsize = 0;
	scanf("%d",&n);
	REP(n) C[i] = (node*)malloc(sizeof(node));
	REP(n) 
		C[i]->nn = 0;
	REP(n)
	{
		scanf("%d",&nn);
		for(int j=0;j<nn;j++) 
		{
			int nnn;
			scanf("%d",&nnn);
			C[i]->neig[C[i]->nn++] = C[nnn-1];
		}
	}
	bool ans = false;
	REP(n) 
	{
		for(int j=0;j<n;j++) 
			C[j]->visited = false;
		if(bfs(C[i]))
		{
			ans = true;
			break;
		}
	}
	printf("%s\n",(ans?"Yes":"No"));
	REP(n) free(C[i]);
}

int main(void)
{
	int ct, tc;
	scanf("%d",&tc);	
	for(ct=1;ct<=tc;ct++)			
	{
		printf("Case #%d: ", ct);	
		solve_problem();
	}
	return 0;
}

inline double comb(int n, int k)
{
	int nk = n-k, i, j; double num = 1.0, den = 1.0;
	if(k==0) return 1; if(n==0&&k!=0) return 0;
	for(i=n;i>nk;i--) num*=i;
	for(j=2;j<=k;j++) den*=j;
	return num/den;
}
