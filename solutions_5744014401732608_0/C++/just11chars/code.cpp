#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <list>
#include <ctime>

using namespace std;

#define mp make_pair
#define sqr(a) ((a)*(a))

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 30;
const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0);

int n, m;
int B[MAXN];

int ways[MAXN];
int need[MAXN];

int way_count()
{
	queue<int> que;
	que.push(0);
	fill(ways, ways + n, 0);
	ways[0] = 1;


	fill(need, need + n, 0);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (B[i] & (1 << j))
				++need[j];

	while (que.size()) {
		int v = que.front();
		que.pop();

		for (int i = 1; i < n; ++i)
			if (B[v] & (1 << i)) {
				if (--need[i] == 0)
					que.push(i);
				ways[i] += ways[v];
			}
	}

	return ways[n - 1];
}

bool generator(int v)
{
	//if (way_count() > m)
	//	return false;

	if (v == n) {
		if (way_count() == m) {
			printf("POSSIBLE\n");
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j)
					printf("%d", bool(B[i] & (1 << j)));
				printf("\n");
			}
			return true;
		}
		return false;
	}

	for (int i = 0; i < (1 << (n - v - 1)); ++i) {
		B[v] = i << (v + 1);

		if (generator(v + 1))
			return true;
	}
	return false;
}

void print_ans()
{
	if (!generator(0))
		printf("IMPOSSIBLE\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		scanf("%d%d", &n, &m);
		printf("Case #%d: ", i);
		print_ans();	
	}
	
	return 0;
}