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
#define PI 3.1415926535897932384626433832795
#define eps 1e-9
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		int r,n,m,k;
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d:\n",i+1);
		FORN(j,r)
		{
			int arr[k],memo[m+1],memo2[m+1];
			FORN(l,k)
				scanf("%d",&arr[l]);
			RES(memo,0);
			RES(memo2,0);
			FORN(l,k)
			{
				int tmp[m+1];
				RES(tmp,0);
				int x = arr[l];
				int z = m;
				while ((x > 1) && (z > 1))
				{
					if (x % z == 0)
					{
						tmp[z]++;
						x /= z;
					}
					else
						z--;
				}
				FORS(a,2,m)
				{
					memo[a] = max(memo[a],tmp[a]);
					memo2[a] += tmp[a];
				}
			}
			int tot = 0;
			int tot2 = 0;
			FORS(l,2,m)
				tot += memo[l];
			FORS(l,2,m)
				tot2 += memo2[l];
			if (tot <= n)
			{
				if (tot2 <= n)
				{
					FORN(a,n-tot)
						printf("2");
					FORS(a,2,m)
						FORN(b,memo2[a])
							printf("%d",a);
				}
				else
				{
					int z = n;
					FORS(a,2,m)
						FORN(b,memo[a]+(tot2-tot)/n)
							if (z > 0)
							{
								printf("%d",a);
								z--;
							}
							else
								break;
				}
			}
			else
			{
				int z = n;
				FORS(a,2,m)
					FORN(b,memo[a])
						if (z > 0)
						{
							printf("%d",a);
							z--;
						}
						else
							break;
			}
			printf("\n");
		}
	}
}
