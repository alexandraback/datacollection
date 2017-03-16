#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vit vi::iterator
#define vpi vector<pii >
#define sq(x) (x)*(x)

int mas[200];

int canDo(int S, int p)
{
	if(S>28)
		return 0;
	if(S==0)
		return (p!=0)*1000;
	int d = S/3;
	int r = S%3;
	d+=r>0;
	if(d>=p)
		return 0;
	d+=r!=1;
	if(d>=p)
		return 1;
	return 1000;
}

int main()
{
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	int n,s,p;
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; ++i)
	{
		scanf("%d%d%d",&n,&s,&p);
		for(int j=0; j<n; ++j)
			scanf("%d",mas+j);
		sort(mas,mas+n);
		int answ = 0;
		for(int j=n-1; j>=0; --j)
		{
			int m = canDo(mas[j], p);
			if(m > s)
				break;
			s-=m;
			++answ;
		}
		printf("Case #%d: %d\n",i+1,answ);
	}
	return 0;
}