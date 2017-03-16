#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > a;
	for (int i = 0; i < n; i++){
		int d, h, m;
		cin >> d >> h >> m;
		for (int i = 0; i < h; i++){
			a.push_back({d, - m - i});
		}
	}
	sort(all(a));
	for (auto &x : a)
		x.second *= -1;
	long long ans = a.size();
	for (int i = 0; i < a.size(); i++){
		long long cur = i;
		for (auto x : a){
			if (x.second == a[i].second)
				continue;
			long long q = 1ll * (360 - x.first) * x.second;
			long long w = 1ll * 360 * x.second;
			long long t = 1ll * (360 - a[i].first) * a[i].second;
			if (x.second > a[i].second){
				if (x.first > a[i].first && q > t)
					cur++;
				continue;
			}
			if (t <= q){
				// cur++;
				continue;
			}
			cur += (t - q) / w;
			// if (x.first >= a[i].first)
			// 	cur--;

			// q + k * w <= t < q + (k + 1) * w
			// k * w <= (t - q) < (k + 1) * w
			// k <= (t - q) / w < k + 1
			// k = [(t - q) / w]
		}
		ans = min(ans, cur);
	}
	cout << ans << "\n";
}

int main(){

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "Test #" << i + 1 << " completed\n";
	}

	return 0;
}