#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

int people;
vector <double> scores;
vector <pair <double, int> > sco;
double judge;

bool ok(int no, double fra) {
	double score = sco[no].first + judge * fra;
	double left = judge * (1 - fra);
	//cerr << "try " << no << ": " << fra << " (" << score << ", " << left << ")" << endl;
	foreach(i, 0, sco) {
		if(sco[i].first >= score)
			break;
		if(i == no)
			continue;
		double need = score - sco[i].first;
		if(need > left) {
			//cerr << "ok: " << i << ", " << left << ", " << need << endl << endl;
			return true;
		}
		left -= need;
	}
	//cerr << "not ok: " << left << endl << endl;
	return false;
}

vector <double> Solve() {
	sco.clear();
	judge = accumulate(scores.begin(), scores.end(), 0.0);
	foreach(i, 0, scores)
		sco.push_back(make_pair(scores[i], i));
	sort(sco.begin(), sco.end());
	vector <double> res(people);
	foreach(i, 0, sco) {
		double MI = 0, MA = 1;
		for(int j = 0; j < 50; ++j) {
			double MID = (MI + MA) / 2;
			if(ok(i, MID))
				MA = MID;
			else
				MI = MID;
		}
		res[sco[i].second] = MI;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> people;
		scores.resize(people);
		foreach(i, 0, scores)
			cin >> scores[i];
		vector <double> res = Solve();
		printf("Case #%d:", t + 1);
		foreach(i, 0, res)
			printf(" %.20lf", 100 * res[i]);
		printf("\n");
	}
	return 0;
}
