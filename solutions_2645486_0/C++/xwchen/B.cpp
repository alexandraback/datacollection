#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x)) 
using namespace std;
const double eps = 1e-8 ;


typedef long long LL ;
int E,R,N,V[11];
void read()
{
	scanf("%d%d%d",&E,&R,&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",V+i);
	}
}
int res;
void gao(int cur,int gain,int enegy)
{
	if(cur==N)
	{
		res = max(res,gain);
		return ;
	}
	for(int i=0;i<=enegy;++i)
	{
		gao(cur+1,gain+i*V[cur],min(E,enegy-i+R));
	}
}
int main(int argc, char const *argv[])
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		read();
		res=0;
		gao(0,0,E);
		printf("Case #%d: %d\n",t,res);
	}
	return 0;
}