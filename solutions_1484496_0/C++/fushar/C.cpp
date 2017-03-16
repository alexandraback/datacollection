/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

typedef long long ll;

#define pb push_back
#define mp make_pair

int T, N, s[100];


int main()
{
	scanf("%d\n", &T);
	REP(tc, T)
	{
		scanf("%d", &N);
		REP(i, N)
			scanf("%d", &s[i]);
		
		map<int, vector<int> > sum;
		REP(k, 1<<N)
		{
			int c = 0;
			REP(i, N) if (k & (1<<i))
				c += s[i];
			sum[c].pb(k);
		}
		
		printf("Case #%d:\n", tc+1);
		bool found = false;
		FOREACH(i, sum) if (i->second.size() >= 2)
		{
			int A = (i->second)[0];
			int B = (i->second)[1];
			
			bool any;
			
			any = false;
			REP(i, N) if (A & (1<<i))
			{
				if (any) printf(" ");
				any = true;
				printf("%d", s[i]);
			}
			printf("\n");
			
			any = false;
			REP(i, N) if (B & (1<<i))
			{
				if (any) printf(" ");
				any = true;
				printf("%d", s[i]);
			}
			printf("\n");
			
			found= true;
			break;
		}
		if (!found)
			puts("Impossible");
	}
}
