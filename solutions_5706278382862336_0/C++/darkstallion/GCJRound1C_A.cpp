//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI acos(-1)
#define eps 1e-9
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		LL p,q;
		scanf("%lld/%lld",&p,&q);
		LL gcd = __gcd(p,q);
		p /= gcd;
		q /= gcd;
		bool benar = false;
		FORS(j,1,40)
			if (q == (1LL << j))
			{
				benar = true;
				break;
			}
		printf("Case #%d: ",i+1);
		if (benar)
		{
			int ans = 0;
			while (p < q)
			{
				p *= 2;
				ans++;
			}
			if (ans > 40)
				printf("impossible\n");
			else
				printf("%d\n",ans);
		}
		else
			printf("impossible\n");
	}
}
