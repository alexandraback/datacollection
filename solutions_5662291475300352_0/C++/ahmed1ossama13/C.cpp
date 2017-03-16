#include<bits/stdc++.h>
using namespace std;

int d[15], h[15], m[15];
int D[2], M[2];
double eps = 1e-5;
int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed_ossama/Desktop/Code jam/C/Small/C-small-1-attempt1.in", "r", stdin);
	freopen("/home/ahmed_ossama/Desktop/Code jam/C/Small/C-small-1-attempt1.out", "w", stdout);
	int t;
	cin >> t;
	int id = 1;
	while (t--) {
		//cerr << t << endl;
		int n;
		cin >> n;
		int ind = 0;
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> h[i] >> m[i];
			for (int j = 0; j < h[i]; j++) {
				D[ind] = d[i];
				M[ind++] = m[i];
			}
		}
		int ans;
		if (ind == 1) {
			ans = 0;
		}
		else {

			double start = 0;
			double end = 1e10;
			while (fabs(end - start) > eps) {
				double mid = (end + start) / 2;
				double t1 = 360 / mid;
				double hisPos = D[0] + M[0] * t1;
				if (hisPos > 360 + eps)
					start = mid;
				else
					end = mid;
			}
			double maxSpeed1 = start;

			start = 0;
			end = 1e10;
			while (fabs(end - start) > eps) {
				double mid = (end + start) / 2;
				double t1 = 360 / mid;
				double displacement = M[0] * t1;
				if (displacement - 360 > D[0])
					start = mid;
				else
					end = mid;
			}
			double minSpeed1 = end;

			start = 0;
			end = 1e10;
			while (fabs(end - start) > eps) {
				double mid = (end + start) / 2;
				double t1 = 360 / mid;
				double hisPos = D[1] + M[1] * t1;
				if (hisPos > 360 + eps)
					start = mid;
				else
					end = mid;
			}
			double maxSpeed2 = start;

			start = 0;
			end = 1e10;
			while (fabs(end - start) > eps) {
				double mid = (end + start) / 2;
				double t1 = 360 / mid;
				double displacement = M[1] * t1;
				if (displacement - 360 > D[1])
					start = mid;
				else
					end = mid;
			}
			double minSpeed2 = end;


			double minSpeed = max(minSpeed1, minSpeed2);
			double maxSpeed = min(maxSpeed1, maxSpeed2);


			if (maxSpeed - minSpeed >= -eps)
				ans = 0;
			else
				ans = 1;

		}
		cout << "Case #" << id++ << ": " << ans << endl;
	}

	return 0;
}


