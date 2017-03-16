#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct attack {
	int day;
	int x1, x2;
	int s;
};

struct wall {
	int x1, x2;
	int s;
};

int n;
map<int, vector<attack> > data;
vector<wall> w, q;

int chk(int x1, int x2, int s) {
	set<int> p;
	for (int i = 0; i < (int)w.size(); ++i) {
		if (w[i].s < s) continue;

		if (w[i].x1 <= x1 && w[i].x2 >= x2) return 1;
		if (w[i].x1 >= x1 && w[i].x1 <= x2) p.insert(w[i].x1);
		if (w[i].x2 >= x1 && w[i].x2 <= x2) p.insert(w[i].x2);
	}
	p.insert(x1); p.insert(x2);

	vector<int> pp;
	for (set<int>::iterator it = p.begin(); it != p.end(); ++it) {
		pp.push_back(*it);	
	}

	int m = (int)pp.size();
	int no = 0;
	for (int i = 1; i < m; ++i) {
		int flag = 0;
		for (int j = 0; j < (int)w.size(); ++j) {
			if (w[j].x1 <= pp[i - 1] && w[j].x2 >= pp[i] && w[j].s >= s) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			no = 1;
			break;
		}
	}
	if (!no) return 1;
	
	wall tmp;
	tmp.x1 = x1; tmp.x2 = x2; tmp.s = s;
	q.push_back(tmp);
	return 0;
}

int solve() {
	map<int, vector<attack> >::iterator it;

	w.clear();
	int ret = 0;
	for (it = data.begin(); it != data.end(); ++it) {
		vector<attack>& v = (it->second);
		q.clear();
		for (int i = 0; i < (int)v.size(); ++i) {
			if (!chk(v[i].x1, v[i].x2, v[i].s)) {
				ret++;
			}
		}

		for (int i = 0; i < (int)q.size(); ++i) {
			w.push_back(q[i]);
		}
	}
	return ret;
}

int main() {
	int r;
	scanf("%d", &r);
	for (int cs = 1; cs <= r; ++cs) {
		printf("Case #%d: ", cs);
		scanf("%d", &n);
		data.clear();
		for (int i = 0; i < n; ++i) {
			int di, ni, wi, ei, si, d_di, d_pi, d_si;
			scanf("%d %d %d %d %d %d %d %d", &di, &ni, &wi, &ei, &si, &d_di, &d_pi, &d_si);
			for (int j = 0; j < ni; ++j) {
				attack tmp;
				tmp.day = di;
				tmp.x1 = wi; tmp.x2 = ei;
				tmp.s = si;

				data[tmp.day].push_back(tmp);

				di += d_di;
				wi += d_pi;
				ei += d_pi;
				si += d_si;
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}
