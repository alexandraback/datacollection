#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long



int main()
{
	//ios_base::sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	for(int qwe=1; qwe<=t; qwe++)
	{
		LL p, q, pot=1;
		int p2=0, q2=0;
		char c;
		scanf("%lld%c%lld", &p, &c, &q);
		while(p%2==0)
		{
			p/=2;
			p2++;
		}
		while(q%2==0)
		{
			q/=2;
			q2++;
		}
		if(p%q!=0 || p2>q2)
		{
			printf("Case #%d: impossible\n", qwe);
			continue;
		}
		p/=q;
		q2-=p2;
		while(q2>0)
		{
			pot*=2;
			q2--;
		}
		int w=1;
		while(p*2<pot)
		{
			w++;
			p*=2;
		}
		printf("Case #%d: %d\n", qwe, w);
	}
	return 0;
}
