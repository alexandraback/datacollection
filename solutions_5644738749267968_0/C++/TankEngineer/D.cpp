#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int war(vector<double> a, vector<double> b) {
	sort(b.begin(), b.end());
	int ret = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		double w = a[i];
		if (w > b.back()) {
			b.erase(b.begin());
			++ret;
		} else {
			b.erase(lower_bound(b.begin(), b.end(), w));
		}
	}
	return ret;
}

int dec(vector<double> a, vector<double> b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ret = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		double w = a[i];
		if (b[0] < w) {
			b.erase(b.begin());
			++ret;
		} else {
			b.pop_back();
		}
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<double> naomi, ken;
		for (int i = 0; i < n; ++i) {
			double t;
			scanf("%lf", &t);
			naomi.push_back(t);
		}
		for (int i = 0; i < n; ++i) {
			double t;
			scanf("%lf", &t);
			ken.push_back(t);
		}
		static int id = 0;
		printf("Case #%d: %d %d\n", ++id, dec(naomi, ken), war(naomi, ken));
	}
	return 0;
}
