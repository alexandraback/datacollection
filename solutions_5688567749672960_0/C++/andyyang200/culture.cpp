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
ll reverse(ll n)
{
	string s = to_string(n);
	reverse(s.begin(), s.end());
	n = 0;
	ll pow = 1;
	RFOR(i, s.length() - 1, -1)
	{
		n += (ll)(s[i] - '0') * pow;
		pow *= (ll)10;
	}
	return n;
}
bool visited[2000005];
int main()
{
	freopen("culture.in", "r", stdin);
	freopen("culture.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 1, sets + 1)
	{
		ll n;
		scanf("%lld", &n);
		FOR(i, 1, n + 1)
		{
			visited[i] = false;
		}
		queue<pii> q;
		q.push({1, 1});
		visited[1] = true;
		while (q.size())
		{
			pii p = q.front();
			q.pop();
			if (p.first > 2 * n)
			{
				continue;
			}
			if (p.first == n)
			{
				cout << "Case #" << set << ": " << p.second << endl;
				break;
			}
			int r = reverse(p.first);
			if (!visited[p.first + 1])
			{
				visited[p.first + 1] = true;
				q.push({ p.first + 1, p.second + 1 });
			}
			if (!visited[r])
			{
				visited[r] = true;
				q.push({ r, p.second + 1 });
			}
		}
	}
}