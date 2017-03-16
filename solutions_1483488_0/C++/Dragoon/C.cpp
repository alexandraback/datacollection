#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

typedef __int64 LL;
#define I64d "%I64d"

vector<PII> V;
int sz;

void gen()
{
	int i, j, z, len, t;
	int p10[20];

	p10[0] = 1;
	for(i=1;i<=9;i++)
		p10[i] = p10[i-1]*10;

	for(i=1;i<=2000000;i++)
	{
		len = 0;
		t = i;
		while(t) t/=10, len++;
		t = i;

		for(j=1;j<len;j++)
		{
			z = (t%p10[j])*p10[len-j] + (t/p10[j]);
			if(t<z)
				V.push_back( PII(t,z) );
		}
	}
/*
	for(i=1;i<50;i++)
		printf("%d %d\n",V[i-1].first,V[i-1].second);
	printf("%d\n",V.size());
*/

	sort(V.begin(),V.end());
	sz = V.size();
	int now = 1;
	for(i=1;i<sz;i++)
		if(V[i]==V[i-1]) continue;
		else V[now++] = V[i];
	sz = now;
//	printf("%d\n",sz);
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);

//	freopen("B-large.in","r",stdin);
//	freopen("B-large.out","w",stdout);

	int T, ks,a,b,cnt,i;

	gen();

	scanf("%d",&T);
	for(ks=1;ks<=T;ks++)
	{
		printf("Case #%d: ",ks);

		scanf("%d%d",&a,&b);

		cnt = 0;
		for(i=0;i<sz;i++)
			if(V[i].first>b) break;
			else if(a<=V[i].first && V[i].first<=b && a<=V[i].second && V[i].second<=b) cnt++;

		printf("%d\n",cnt);



	}

	return 0;
}