#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define For(i, n) for (int i = 0; i < n; i ++)
#define Ford(i, n) for (int i = n - 1; i >= 0; i --)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

template<typename T> void checkmax(T &a, T b) { if (b > a) a = b; }
template<typename T> void checkmin(T &a, T b) { if (b < a) a = b; }

typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int N = 2012;
int n;
int a[N], b[N];
int state[N];
void solve(int cid)
{
	if (cid == 6)
		int asdf = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &a[i], &b[i]);

	memset(state, 0, sizeof(state));
	int v = 0, cnt = 0;
	while (v != n + n)
	{
		try
		{
			for (int i = 1; i <= n; i ++)
				if (v >= b[i] && state[i] == 0)
				{
					cnt ++;
					state[i] = 2;
					v += 2;
					throw 2;
				}

			
			int v_0 = -1, id_0 = -1, id_1 = -1;
			for (int i = 1; i <= n; i ++)
			{
				if (state[i] == 0 && v >= a[i])
					if (b[i] >= v_0)
						v_0 = b[i], id_0 = i;
				if (state[i] == 1 && v >= b[i])
					id_1 = i;
			}
			if (id_1 != -1)
			{
				cnt ++;
				state[id_1] = 2;
				v ++;
				throw 1;
			}
			if (id_0 != -1)
			{
				cnt ++;
				state[id_0] = 1;
				v ++;
				throw 1;
			}
		} catch (...) 
		{
			continue;
		}
		printf("Too Bad\n");
		return;
	}
	assert(cnt >= n);
	printf("%d\n", cnt);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int id = 1; id <= ncase; id ++)
	{
		printf("Case #%d: ", id);
		solve(id);
	}
	return 0;
}

