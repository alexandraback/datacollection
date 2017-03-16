//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
bool used[20];
int main()
{
	freopen("ship.in", "r", stdin);
	freopen("ship.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 1, sets + 1)
	{
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		int ans = 0;
		for (int i = w - 1; i < c; i += w)
		{
			ans++;
		}
		if (c % w != 0)
		{
			ans++;
		}
		ans += w - 1;
		ans *= r;
		cout << "Case #" << set << ": " << ans << endl;
	}
}