// универсальный код!!!!111
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

#define sz size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sqr(x) ((x)*(x))

bool good(vector<double> voc, double sum, double total) {
	double s = 0;
	for(int i = 0; i < voc.sz; i++) {
		s += (total - voc[i]) / sum;
	}
	return (s - 1.0 < 1e-10);
}
void solve(vector<double> voc, double sum) {
	double l = *min_element(all(voc)), r = 1000000, m, ans;
	set<int> s(all(voc));
	set<int>::iterator it = s.begin();
	int cnt = 0;
	for(int i = 0; i < voc.sz; i++) {
		if(voc[i] == *it) cnt++;
	}
	if(cnt == 1) {
		
	}

	for(int i = 0; i < 150; i++) {
		m = (l + r) / 2;
		if(good(voc, sum, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	for(int i = 0; i < voc.sz - 1; i++) {		
		printf("%.7lf ", ((l - voc[i]) / sum * 100));
	}
	printf("%.7lf\n", ((l - voc.back()) / sum * 100));
}
int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, n, it = 1;
	vector<double> voc;
	double sum;
	cin >> t;
	while(t--) {
		cin >> n;
		sum = 0;
		voc.assign(n, 0);
		for(int i = 0; i < n; i++) {
			cin >> voc[i];
			sum += voc[i];
		}
		printf("Case #%d: ", it++);
		solve(voc, sum);
	}
	return 0;
}
 