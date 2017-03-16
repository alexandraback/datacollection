#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct Attack {
	int day;
	int s;
	int w, e;

	Attack(int _day, int _s, int _w, int _e):
		day(_day), s(_s), w(_w), e(_e) {}

	bool operator <(const Attack &t) const {
		return day < t.day;
	}
};

vector<int> a(2000000), b(2000000);

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {
		for (int i = 0; i < 2000000; i++)
			a[i] = b[i] = 0;
		vector<Attack> att;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;

			for (int j = 0; j < ni; j++)
				att.push_back(Attack(di + j * delta_di, si + j * delta_si,
					wi + j * delta_pi + 1000000, ei + j * delta_pi + 1000000));
		}

		sort(att.begin(), att.end());

		int res = 0;
		for (int i = 0; i < att.size(); i++) {
/*			cout << "$ " << att[i].day << " " << att[i].s << " " <<
				att[i].w - 1000000 << " " << att[i].e - 1000000;*/
			int tmp = 1000000000;
			for (int j = att[i].w; j < att[i].e; j++)
				if (tmp > a[j])
					tmp = a[j];
			if (tmp < att[i].s)
				res++;
/*			if (tmp < att[i].s)
			 	cout << " + $" << endl;
			else cout << " $" << endl;*/

			for (int j = att[i].w; j < att[i].e; j++)
				b[j] = max(b[j], att[i].s);

			if (i < att.size() - 1 && att[i].day < att[i + 1].day)
				for (int j = 0; j < 2000000; j++)
					a[j] = b[j];
		}

		cout << "Case #" << q + 1 << ": " << res << endl;
	}
}