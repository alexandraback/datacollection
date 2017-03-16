#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1001;

int N;
struct Kid {
	int bff, sCircle, dest, distToDest, visitedTime, maxTail;
	bool ok;
	vector<int> eList;
}kid[MAXN];
int maxCircle, a[MAXN];

void findCircles(int x) {
	int t = 0, flag;
	while (true) {
		if (kid[x].ok) break;
		kid[x].ok = true;
		kid[x].visitedTime = t;
		a[t++] = x;
		x = kid[x].bff;
	}
	if (kid[x].dest >= 0) { // We have done x before
		for (int i = 0; i < t; ++i) {
			kid[a[i]].sCircle = 0; // Not a circle; will go into a previous circle
			kid[a[i]].dest = kid[x].dest;
			kid[a[i]].distToDest = kid[x].distToDest + t - i;
			kid[a[i]].ok = true;
		}
	}
	else {
		for (int i = kid[x].visitedTime; i < t; ++i) {
			kid[a[i]].sCircle = t - kid[x].visitedTime;
			kid[a[i]].dest = a[i];
			kid[a[i]].distToDest = 0;
			kid[a[i]].ok = true;
		}
		for (int i = 0; i < kid[x].visitedTime; ++i) {
			kid[a[i]].sCircle = 0; // Not in circle
			kid[a[i]].dest = x;
			kid[a[i]].distToDest = kid[x].visitedTime - i;
			kid[a[i]].ok = true;
		}
		maxCircle = max(maxCircle, t - kid[x].visitedTime);
	}
}

int arrange() {
	for (int i = 1; i <= N; ++i)
		kid[i].maxTail = 0;
	for (int i = 1; i <= N; ++i)
		kid[kid[i].dest].maxTail = max(kid[kid[i].dest].maxTail, kid[i].distToDest);
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		if (2 == kid[i].sCircle)
			ans += kid[i].maxTail + 1;
	return ans;
}

int solve() {
	for (int i = 1; i <= N; ++i)
		kid[i].eList.clear(), kid[i].ok = false,
		kid[i].dest = kid[i].distToDest = kid[i].visitedTime = -1;
	maxCircle = 0;
	for (int i = 1; i <= N; ++i)
		if (!kid[i].ok)
			findCircles(i);
	return max(maxCircle, arrange());
}

int main() {
	int T;
	FILE *ifp = fopen("C.in", "r");
	FILE *ofp = fopen("C.out", "w");
	fscanf(ifp, "%d", &T);
	for (int t = 1; t <= T; ++t) {
		fscanf(ifp, "%d", &N);
		for (int i = 1; i <= N; ++i)
			fscanf(ifp, "%d", &kid[i].bff);
		fprintf(ofp, "Case #%d: %d\n", t, solve());
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
