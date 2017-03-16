/*
#include "template.h"
#include "point.h"
#include "math.h"
#include "line.h"
#include "edge.h"
#include "graph.h"
#include "distance.h"
#include "dsu.h"
#include "mst.h"
#include "convex hull.h"
*/
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;

#define mp make_pair
#define pb push_back
#define det(a, b, c, d) a * d - b * c

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int inf = 1234567890;
#endif

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		string ans;
		vector<string> vs(N);
		vvi g(N);
		for (int i = 0; i < N; ++i) cin >> vs[i];
		for (int i = 0; i < M; ++i)
		{
			int f, t;
			cin >> f >> t;
			--f;
			--t;
			g[f].pb(t);
			g[t].pb(f);
		}
		vi arr(N);
		for (int i = 0; i < N; ++i) arr[i] = i;
		do
		{
			bool can = true;
			vi L(N);
			for (int i = 0; i < N-1; ++i)
			{
				int next = arr[i+1];
				bool lcan = false;
				for (int k = i; k >= 0; --k)
				{
					int now = arr[k];
					if(L[now]) continue;
					for (int j = 0; j < g[now].size(); ++j)
					{
						int t = g[now][j];
						if(t == next)
						{
							lcan = true;
							goto new_way;
						}
					}
					L[now] = 1;
				}
				new_way:;
				can = can && lcan;
			}
			if(can)
			{
				string lans;
				for (int i = 0; i < N; ++i)
				{
					lans += vs[arr[i]];
				}
				if(ans.size() == 0 || ans > lans) ans = lans;
			}
		}
		while(next_permutation(arr.begin(), arr.end()));
		printf("Case #%d: ", t);
		cout << ans << endl;
	}
	return 0;
}