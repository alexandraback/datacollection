#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>

using namespace std;

#define SZ 2005

typedef struct{
	int d, n, w, e, s;
	int deld, delp, dels;
}tribe;

typedef struct{
	int d, w, e, s;
}attack;

tribe tbs[15];
vector<attack> vack;

int wal[SZ];
int len;

bool comp(attack a, attack b)
{
	return(a.d < b.d);
}

bool canb(attack aa)
{
	int i;
	for(i = 2 * aa.w; i <= 2 * aa.e; i++)
	{
		if(wal[i + 1000] < aa.s)
			return true;
	}
	return false;
}

void upd(attack aa)
{
	int i;
	for(i = 2 * aa.w; i <= 2 * aa.e; i++)
	{
		if(wal[i + 1000] < aa.s)
			wal[i + 1000] = aa.s;
	}
	
}

int main()
{
	freopen("C-small-attempt1.in", "rt", stdin);
	freopen("C-small.out", "wt", stdout);

	//freopen("C-large-1.in", "rt", stdin);
	//freopen("C-large-1.out", "wt", stdout);

	int i, j, k, kase, inp, n;
	
	scanf("%d", &inp);
	
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d", &n);
		vack.clear();
		memset(wal, 0, sizeof(wal));
		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d %d %d", &tbs[i].d, &tbs[i].n, &tbs[i].w, &tbs[i].e, &tbs[i].s);
			scanf("%d %d %d", &tbs[i].deld, &tbs[i].delp, &tbs[i].dels);

			attack atk;
			atk.d = tbs[i].d;
			atk.w = tbs[i].w;
			atk.e = tbs[i].e;
			atk.s = tbs[i].s;
			vack.push_back(atk);
			for(j = 1; j < tbs[i].n; j++)
			{
				atk.d += tbs[i].deld;
				atk.w += tbs[i].delp;
				atk.e += tbs[i].delp;
				atk.s += tbs[i].dels;
				vack.push_back(atk);
			}
		}
		sort(vack.begin(), vack.end(), comp);
		int tot = vack.size();
		i = 0;
		int res = 0;
		while(i < tot)
		{
			j = i;
			while(j < tot && (vack[j].d == vack[i].d))
				j++;
			for(k = i; k < j; k++)
			{
				if(canb(vack[k]))
					res++;
			}
			for(k = i; k < j; k++)
			{
				upd(vack[k]);
			}
			i = j;
		}
		printf("Case #%d: %d\n", kase, res);
	}

	return 0;
}

