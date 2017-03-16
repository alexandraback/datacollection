#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

static const int MAXN = 12;
static const double EPS = 1e-13;

int n, m;
struct Guy {
	double start;
	double speed;
	bool pl;
};
Guy guys[MAXN];

void PrintOrder(const deque<Guy> &order) {
	for (int i = 0; i < order.size(); i++) {
		const auto &g = order[i];
		if (g.pl) Ef(" [XXXXX] ");
		else Ef(" [%0.3lf; %0.3lf] ", g.start, g.speed);
	}
	Ef("\n");
}

int ans;
void SolveRec(int k, double ct, deque<Guy> order) {
	if (k >= ans)
		return;

	Ef("Score = %d, Time = %0.3lf\n", k, ct);
	PrintOrder(order);

	if (order.back().pl) {
		ans = min(ans, k);
		return;
	}

	int bestI = -1, bestNI = -1;
	double minT = 1e+100;

	for (int i = 0; i < order.size(); i++) if (!order[i].pl) {
		int ni = i + 1;
		if (ni == order.size()) continue;
		bool interm = order[ni].pl;
		if (interm) ni++;
		if (ni == order.size()) continue;

		const auto &a = order[i];
		const auto &b = order[ni];
		if (a.speed <= b.speed + EPS)
			continue;
		double crt = (b.start - a.start) / (a.speed - b.speed);
		Eo(crt);
		if (minT > crt) {
			minT = crt;
			bestI = i;
			bestNI = ni;
		}
	}

	double goesOff = (1.0 - order.back().start) / order.back().speed;
	Eo(goesOff);

	double dt = min(minT, goesOff);
	ct += dt;
	for (int i = 0; i < order.size(); i++) {
		if (order[i].pl) continue;
		order[i].start += order[i].speed * dt;
	}

	if (goesOff < minT - EPS) {
		auto q = order.back();
		order.pop_back();
		q.start -= 1.0;
		order.push_front(q);
		SolveRec(k, ct, order);
		return;
	}

   	std::swap(order[bestI], order[bestNI]);
    if (bestNI == bestI + 1) {
    	SolveRec(k, ct, order);
    	return;
    }

	int pl = bestI + 1;
	std::swap(order[bestI], order[pl]);
	SolveRec(k+1, ct, order);
	std::swap(order[bestI], order[pl]);
	std::swap(order[bestNI], order[pl]);
	SolveRec(k+1, ct, order);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d", &m);
		n = 0;

		for (int i = 0; i < m; i++) {
			int deg0, gs, per0;
			scanf("%d%d%d", &deg0, &gs, &per0);

			Guy g;
			g.start = deg0 / 360.0;
			g.pl = false;
			for (int j = 0; j < gs; j++) {
				g.speed = 1.0 / (per0 + j);
				guys[n++] = g;
			}
		}
		stable_sort(guys, guys + n, [](const Guy &a, const Guy &b) -> bool { return a.start < b.start; });

		deque<Guy> order;
		Guy pl;
		pl.pl = true;
		order.push_back(pl);
		for (int i = 0; i < n; i++)
			order.push_back(guys[i]);

		ans = n + 1;
		SolveRec(0, 0.0, order);

		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
