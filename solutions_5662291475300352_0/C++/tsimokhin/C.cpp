#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> pii;
vector <pii> h;

void swp(pii a, pii b) {
	int c = a.first; a.first = b.first; b.first = c;
	c = a.second; a.second = b.second; b.second = c;
}

long long f() {
	if (h.size() <= 1)
		return 0;
	if (h.size() == 2) {
		pii a1 = h[0];
		pii a2 = h[1];
		/*double time2ToFinish = - (360 + 360 - a2.first) * a2.second;
		double time1ToFinish = - (360 - a1.first) * a1.second;
		cout <<a1.first<<" "<<a1.second<<" "<<time1ToFinish<<endl;
		cout <<a2.first<<" "<<a2.second<<" "<<time2ToFinish<<endl;
		if (time2ToFinish <= time1ToFinish)
			return 1;*/
		double time1ToFinish = - (360 - a1.first) * a1.second;
		double circle2Made = -time1ToFinish / a2.second;
		//cout <<"Time 1 to Finish: "<<time1ToFinish<<endl;
		//cout <<"2 made circles: "<< circle2Made<<endl;
		if (circle2Made > (360 + 360 - a2.first))
			return 1;
		return 0;
	}
}

int main() {
	freopen("C-small-1-attempt2.in", "r", stdin);
	freopen("C-small-12.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++) {
		//Input
		h.clear();
		int n;
		cin >> n;
		while (n > 0) {
			int pos, num, antispeed;
			cin >> pos >> num >> antispeed;
			while (num > 0) {
				h.push_back(make_pair(pos, -antispeed));
				antispeed++;
				num--;
			}
			n--;
		}
		sort(h.begin(), h.end());
		cout <<"Case #"<<q<<": "<<f()<<endl;
	}
}