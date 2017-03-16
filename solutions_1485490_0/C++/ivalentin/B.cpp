#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

/*
inline int bestScoreWithoutSurprise(int total)
{
	return (total + 2) / 3;
}

inline int bestScoreWithSurprise(int total)
{
	return (total + 4) / 3;
}
*/

struct bi
{
	unsigned long long int nb;
	int type;
};

int n, m;

unsigned long long int travel(int cn, int cm, unsigned long long int res, bi N[], bi M[])
{
	while (true)
	{
		if ((cn >= n) || (cm >= m))
		{
			return res;
		}

		if (N[cn].type == M[cm].type)
		{
			unsigned long long int  delta = min(N[cn].nb, M[cm].nb);
			res += delta;
			N[cn].nb -= delta;
			M[cm].nb -= delta;

			if (N[cn].nb == 0)
			{
				cn++;
			}
				
			if (M[cm].nb == 0)
			{
				cm++;
			}
		}
		else
		{
			//printf("#");
			
			//Copier N et M
			bi* Nf1 = new bi[n];
			bi* Mf1 = new bi[m];
			bi* Nf2 = new bi[n];
			bi* Mf2 = new bi[m];

			for (int i = cn; i < n; i++)
			{
				Nf1[i].nb = N[i].nb;
				Nf1[i].type = N[i].type;
				Nf2[i].nb = N[i].nb;
				Nf2[i].type = N[i].type;
			}
			for (int i = cm; i < m; i++)
			{
				Mf1[i].nb = M[i].nb;
				Mf1[i].type = M[i].type;
				Mf2[i].nb = M[i].nb;
				Mf2[i].type = M[i].type;
			}

			unsigned long long int res1 = travel(cn + 1, cm, res, Nf1, Mf1);
			unsigned long long int res2 = travel(cn, cm + 1, res, Nf2, Mf2);

			delete(Nf1);
			delete(Nf2);
			delete(Mf1);
			delete(Mf2);

			return  max(res1, res2);
		}
	}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		printf("Case #%d: ",case_id);
		scanf("%d %d",&n,&m);
		
		bi N[100];
		bi M[100];

		for (int i = 0; i < n; i++)
		{
			unsigned long long int nb, type;
			scanf("%lld %d", &nb, &type);
			N[i].nb = nb;
			N[i].type = type;
		}

		for (int i = 0; i < m; i++)
		{
			unsigned long long int nb, type;
			scanf("%lld %d", &nb, &type);
			M[i].nb = nb;
			M[i].type = type;
		}

		unsigned long long int res = travel(0,0,0,N,M);

		printf("%lld\n", res);
		
		fflush(stdout);
	}
	return 0;
}