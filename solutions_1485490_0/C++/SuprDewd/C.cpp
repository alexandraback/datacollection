#include <vector>
#include <map>
#include <set>
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
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<long long , int> li;
template <class T> int size(T x) { return x.size(); }

li* boxes;
li* toys;
int n, m;

long long cnt(int b, long long bd, int t, long long td)
{
	if (b >= n || t >= m) return 0;
	if (bd >= boxes[b].first) b++, bd = 0;
	if (td >= toys[t].first) t++, td = 0;
	if (b >= n || t >= m) return 0;

	if (boxes[b].second == toys[t].second)
	{
		long long m = min(boxes[b].first - bd, toys[t].first - td);
		return m + cnt(b, m + bd, t, m + td);
	}
	else
	{
		return max(cnt(b + 1, 0, t, td), cnt(b, bd, t + 1, 0));
	}
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		scanf("%d %d\n", &n, &m);
		boxes = new li[n];
		toys = new li[m];

		for (int i = 0; i < n; i++)
			cin >> boxes[i].first >> boxes[i].second;
		
		for (int i = 0; i < m; i++)
			cin >> toys[i].first >> toys[i].second;

		cout << "Case #" << t + 1 << ": " << cnt(0, 0, 0, 0) << endl;
	}

	return 0;
}