#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

struct tribes{
 int di, n, w, e, si, delta_d, delta_p, delta_s, i;
 };

tribes tribe[1010];
multimap<int,tribes> q;
int wall[1000000];
vector<pair<int,int> > order;


bool sucess(tribes cur)
{
	bool retv = false;
	for(int i = cur.w; i < cur.e; i++)
	{
		if(wall[i] < cur.si)
		{
			retv = true;
			order.push_back(pair<int,int> (i, cur.si));
		}
	}
	return retv;
}

void rebuild()
{
	for(int i = 0; i < order.size(); i++)
		wall[order[i].first] = max(wall[order[i].first], order[i].second);
	order.clear();
	return;	
}

int
main(void)
{
	int T, test = 1, n, i, j;
	scanf("%d", &T);
	while(test <= T)
	{
		memset(wall, 0, sizeof(wall));
		order.clear();
		q.clear();
		int prev = -1, ans = 0;
		scanf("%d", &n);
		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d %d %d %d %d %d", &tribe[i].di, &tribe[i].n, &tribe[i].w, &tribe[i].e, &tribe[i].si, &tribe[i].delta_d, &tribe[i].delta_p, &tribe[i].delta_s);
			tribe[i].w += 100000;
			tribe[i].e += 100000; tribe[i].i = i+1; tribe[i].n--;
			q.insert(pair<int,tribes> (tribe[i].di, tribe[i]));
		}
		while(!q.empty())
		{
			tribes cur = q.begin()->second;
//			printf("n %d i %d d %d %d %d %d\n", cur.n, cur.i,cur.di, cur.w-10000, cur.e - 10000, cur.si);
			q.erase(q.begin());
			if(cur.di != prev)
			{
				rebuild();
				prev = cur.di;
			}
			if(sucess(cur))
				ans++;
			if(cur.n > 0)
			{
//				printf("S\n");
				cur.n--; cur.di += cur.delta_d; cur.w += cur.delta_p; cur.e += cur.delta_p; cur.si += cur.delta_s;
				q.insert(pair<int,tribes> (cur.di, cur));
			}
		}
		printf("Case #%d: %d\n", test++, ans);
	}
	return 0;
}
