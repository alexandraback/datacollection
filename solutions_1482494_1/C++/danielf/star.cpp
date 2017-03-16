#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;

#define all(x) (x).begin(), (x).end()
#define _foreach(i, a, b) for (typeof(a) i = a; i != b; ++i)
#define foreach(x...) _foreach(x)
#define fu(i, n) foreach(i, 0, n)
#define forall(i, V) foreach(i, all(V))
#define MSET(V, x) memset(V, x, sizeof(V))

int N;
vector<pair<int, int> > V;

int solve() {
	int ans = 0;
	int stars = 0;
	while (V.size()) {
		// Try to find 2 stars
		int i = -1;
		forall(it, V) if (it->second <= stars) {
			i = it - V.begin();
			break;
		}
		if (i != -1) {
			if (V[i].first == INF)
				stars++;
			else
				stars += 2;
			ans++;
			swap(V[i], V[V.size()-1]);
			V.pop_back();
			continue;
		}
		// Try to find 1 star
		i = -1;
		forall(it, V) if (it->first <= stars) {
			if (i == -1 || V[i].second < it->second)
				i = it - V.begin();
		}
		if (i == -1) return INF;
		ans++;
		stars++;
		V[i].first = INF;
	}
	return ans;
}

int main() {
	int _42;
	scanf("%d", &_42);
	fu (_, _42) {
		printf("Case #%d: ", _+1);
		scanf("%d", &N);
		V.clear();
		fu(i, N) {
			int a,b;
			scanf("%d %d", &a, &b);
			V.push_back(make_pair(a,b));
		}
		int ans = solve();
		if (ans == INF)
			printf("Too Bad\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
