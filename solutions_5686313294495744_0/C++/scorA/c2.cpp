#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<string, string> P;

int main() {
	//cout << (1<<16) << endl;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		map<string, int> fmp, smp;
		string fir, sec;
		int cc = 0;
		vector<P> d;
		for (int j = 0; j < n; j++) {
			cin >> fir >> sec;
			fmp[fir]++;
			smp[sec]++;
			d.push_back(P(fir, sec));
			//cout << d[j].first << ' ' << d[j].second << endl;
		}
		int l = 1 << n;
		for (int j = 0; j < l; j++) {
			bool h = true;
			int dd = 0;
			map<string, int> kfmp, ksmp;
			kfmp = fmp;
			ksmp = smp;
			for (int k = 0; k < n; k++) {
				//cout << j << ' ' << (1<<k) << endl;
				if ((j & (1<<k)) != 0) {
				} else {
					//cout << j << ' ' << k << endl;
					dd++;
					//cout << d[k].first << ' ' << d[k].second << endl;
					if (kfmp[d[k].first] > 1 && ksmp[d[k].second] > 1) {
						kfmp[d[k].first]--;
						ksmp[d[k].second]--;
					} else {
						h = false;
						break;
					}
				}
			}
			if (h) {
				cc = max(cc, dd);
			}
		}
		printf("Case #%d: %d\n", i+1, cc);
	}
	return 0;
}