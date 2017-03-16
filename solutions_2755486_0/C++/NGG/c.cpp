#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct attack {
	int d;
	int w;
	int e;
	int s;

	attack(int d, int w, int e, int s) : d(d), w(w), e(e), s(s) {}

	bool operator<(const attack& other) const {
		return d < other.d;
	}
};

int main(void)
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ti++) {
		int n;
		cin >> n;
		std::vector<attack> attacks;
		
		for (int i = 0; i < n; i++) {
			int d, x, w, e, s, dd, dp, ds;
			cin >> d >> x >> w >> e >> s >> dd >> dp >> ds;
			for (int j = 0; j < x; j++) {
				attacks.emplace_back(d, w, e, s);
				d += dd;
				w += dp;
				e += dp;
				s += ds;
			}
		}
		sort(attacks.begin(), attacks.end());
		int an = attacks.size();
		int done = 0;
		int ret = 0;
		int ofs = 1000000;
		std::vector<int> height(2000000, 0);
		for (int i = 0; i < an; i++) {
			if (i == 0 || attacks[i].d > attacks[i-1].d) {
				for (int j = done; j < i; j++) {
					for (int k = attacks[j].w; k < attacks[j].e; k++) {
						if (attacks[j].s > height[ofs+k]) {
							height[ofs+k] = attacks[j].s;
//cout << "add " << k << " " << attacks[j].s << endl;
						}
					}
				}
				done = i;
			}
			bool succ = false;
			for (int j = attacks[i].w; j < attacks[i].e; j++) {
				if (height[ofs+j] < attacks[i].s) {
//cout << "succ " << i << " " << j << " " << attacks[i].s << endl;
					succ = true;
					break;
				}
			}
			if (succ) ret++;
		}
		cout << "Case #" << ti << ": " << ret << endl;
	}
	return 0;
}
