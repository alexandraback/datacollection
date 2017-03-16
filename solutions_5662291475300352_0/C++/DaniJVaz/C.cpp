#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);
		vector <ll> degs;
		vector <ll> times;

		for (int i=0; i<n; i++) {
			ll d, h, t;
			scanf("%I64d %I64d %I64d", &d, &h, &t);
			for (int i=0; i<h; i++) {
				degs.push_back(d);
				times.push_back(t+i);
			}
		}

		ll c = 0;
		if (degs.size() == 2) {
			if (times[1] < times[0]) {
				swap(degs[0], degs[1]);
				swap(times[0], times[1]);
			}

			// All units are in 1/360s.
			ll myTime = 360LL*times[0] + (360-degs[0])*times[0];
			// The deer will finish just in ahead of the quickest hiker

			// Now we check if we collide with the slowest
			if ((360-degs[1])*times[1] >= myTime)
				c++;
		}
		else {
			c = -1;
		}

		bool allSame = false;
		{
			allSame = true;
			ll t = times[0];
			for (int i=0; i<times.size(); i++)
				if (times[i] != t)
					allSame = false;
		}

		if (allSame)
			c = 0;

		printf("Case #%d: %d\n", iC, c);
	}
	return 0;
}