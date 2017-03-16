#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int R, N, M, K;
vector<int> p;
vector<int> sol;

bool is_valid(vector<int> d) {
	vector<int> allp;
	for (int i = 0; i < (1 << N); i++) {
		int pp = 1;
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) != 0) {
				pp *= d[j];
			}
		}
		allp.push_back(pp);
	}
	bool is = 1;
	for (int i = 0; i < p.size(); i++) if (find(allp.begin(), allp.end(), p[i]) == allp.end()) { is = 0; break; }
	return is;
}

void f(vector<int> d, int l) {
	if (l == 0) {

		if(is_valid(d)) {
			sol = d;
		}

		return;
	}

	for (int i = 2; i <= M; i++) {
		d.push_back(i);
		f(d, l - 1);
		d.pop_back();
	}
}

int main() {
	//ifstream in("B-large.in");
	ifstream in("C-small.in");
	//ifstream in("C.in");
	ofstream out("C-small.out");

	int T; in >> T;
	for (int x = 1; x <= T; x++) {
		out << "Case #" << x << ":" << endl;
		in >> R >> N >> M >> K;
		for (int xx = 0; xx < R; xx++) {
			p = vector<int>(K);
			for (int i = 0; i < K; i++) in >> p[i];
			f(vector<int>(), N);
			for (int i = 0; i < sol.size(); i++) out << sol[i];
			out << endl;
		}
	}

	return 0;
}
