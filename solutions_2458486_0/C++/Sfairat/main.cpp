#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;

void test(int testNum);

void init()
{

}

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	clock_t cl = clock();

	init();

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
	{
		test(i+1);
		DebugPrint("%d\n", i+1)
	}

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

struct chest
{
	int neededKey;
	vector<int> keysInside;
} chests[220];

const int MAXLEN = 1 << 20;

int prevs[MAXLEN];

int chestsCount;

vector<int> initialKeys;

int oneCount(int num)
{
	int res = 0;
	rep(i, 0, chestsCount)
	{
		if (num & (1 << i))
			res++;
	}
	return res;
}

void bfs()
{
	memset(prevs, -1, sizeof(prevs));
	
	queue<int> bfsQueue;
	bfsQueue.push(0);

	while (!bfsQueue.empty())
	{
		int cur = bfsQueue.front();
		bfsQueue.pop();

		int keys[20];

		rep(i, 0, initialKeys.size())
		{
			keys[i] = initialKeys[i];
		}

		rep(i, 0, chestsCount)
		{
			if (cur & (1 << i))
			{
				keys[chests[i].neededKey]--;
				rep(j, 0, initialKeys.size())
					keys[j] += chests[i].keysInside[j];
			}
		}

		rep(i, 0, chestsCount)
		{
			if (!(cur & (1 << i)))
			{
				if (keys[chests[i].neededKey] > 0)
				{
					int next = cur | (1 << i);
					if (prevs[next] == -1)
					{
						prevs[next] = i;
						bfsQueue.push(next);
					}
				}
			}
		}
	}
}

vector<int> buildAns()
{
	int endVal = (1 << chestsCount) - 1;
	if (prevs[endVal] == -1)
		return vector<int>();

	vector<int> result;

	int cur = endVal;
	while (cur != 0)
	{
		int move = prevs[cur];
		result.push_back(move);
		cur = cur ^ (1 << move);
	}

	reverse(all(result));

	return result;
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);

	map<int, int> neededKeys;

	initialKeys.clear();

	int K, N;
	scanf("%d%d", &K, &N);

	vector<int> tk;

	rep(i, 0, K)
	{
		int cur;
		scanf("%d", &cur);
		tk.push_back(cur);
	}

	chestsCount = N;

	rep(i, 0, N)
	{
		int nk;
		chests[i].keysInside.clear();
		scanf("%d", &nk);
		if (neededKeys.find(nk) == neededKeys.end())
			neededKeys.insert(pii(nk, neededKeys.size()));

		int ki;
		scanf("%d", &ki);

		chests[i].neededKey = neededKeys[nk];

		rep(j, 0, ki)
		{
			int ck;
			scanf("%d", &ck);
			chests[i].keysInside.push_back(ck);
		}
	}

	initialKeys.resize(neededKeys.size(), 0);

	rep(i, 0, K)
	{
		if (neededKeys.find(tk[i]) == neededKeys.end())
			continue;
		initialKeys[neededKeys[tk[i]]]++;
	}

	rep(i, 0, N)
	{
		vector<int> newKeysInside(neededKeys.size(), 0);
		chest &curChest = chests[i];

		rep(j, 0, curChest.keysInside.size())
		{
			if (neededKeys.find(curChest.keysInside[j]) == neededKeys.end())
				continue;
			int mappedKey = neededKeys[curChest.keysInside[j]];
			newKeysInside[mappedKey]++;
		}
		curChest.keysInside = newKeysInside;
	}

	bfs();

	vector<int> result = buildAns();

	if (result.size() == 0)
	{
		printf("IMPOSSIBLE");
	}
	else
	{
		rep (i, 0, result.size())
		{
			printf("%d ", result[i] + 1);
		}
	}

	printf("\n");
}