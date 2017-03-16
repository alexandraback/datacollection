#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#define MaxLength INT_MAX
#define MaxNode 12
#define MN 10005
using namespace std;

int D,T,N,H,A;
int vis[MN];
int mem[MN];

int dfs(int a, int i)
{
	if(i>=N)
		return 0;
	if(mem[i]<a)
		return dfs(a+mem[i],i+1);
	else
	{
		if(a+a-1>a)
			return min(dfs(a+a-1,i),dfs(a,i+1))+1;
		else
			return dfs(a,i+1)+1;
	}
}
int main(){
	int i,j,k,tt,a,b,res;
	scanf("%d",&T);
	for(tt=1; tt<=T;tt++){

		scanf("%d %d",&A,&N);
		for(i=0; i<N ;i++)
			scanf("%d",&mem[i]);
		sort(mem,mem+N);
		res = dfs(A,0);

		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}
