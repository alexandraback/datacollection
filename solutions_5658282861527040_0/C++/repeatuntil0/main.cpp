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
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int A, B, K, ans = 0;
		scanf("%d %d %d", &A, &B, &K);
		for (int j = 0; j < A; ++j)
			for (int k = 0; k < B; ++k)
				if((j & k) < K) ans++;
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}