#include <iostream>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

#define INF 1000000

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

int solve(int R, int C, int W)
{
	int q1 = (R - 1) * (C / W);
	int q2;
	if (W == C) {
		q2 = W;
	}
	else if (C % W == 0) {
		q2 = W + (C - W) / W;
	}
	else {
		q2 = 1 + (W + (C - W) / W);
	}
	return q1 + q2;
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		int R,C,W; cin >> R >> C >> W;
		cout << "Case #" << t << ": " << solve(R,C,W) << endl;
	}
	return 0;
}
