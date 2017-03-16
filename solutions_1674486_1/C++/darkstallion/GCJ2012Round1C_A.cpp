//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
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
using namespace std;

int t,n,m,x;
bool ada;

int main()
{
	scanf("%d",&t);
	FORN(i,t)
	{
		scanf("%d",&n);
		vector<int> data[n+1];
		FORN(j,n)
		{
			scanf("%d",&m);
			FORN(k,m)
			{
				scanf("%d",&x);
				data[j+1].pb(x);
			}
		}
		printf("Case #%d:",i+1);
		ada = false;
		bool udah[n+1];
		FORS(j,1,n)
		{
			RES(udah,false);
			queue<int> q;
			q.push(j);
			while (q.sz())
			{
				x = q.front();
				q.pop();
				if (!udah[x])
				{
					udah[x] = true;
					FORN(k,data[x].sz())
						q.push(data[x][k]);
				}
				else
				{
					ada = true;
					break;
				}
			}
		}
		if (ada)
			printf(" Yes\n");
		else
			printf(" No\n");
	}
}
