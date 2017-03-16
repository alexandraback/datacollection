#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

long long E, R, N;
vector<long long> v;

void sub(long long ind, long long curr, long long cum, long long &res) {
	if (ind == N) {
		res = max(res, cum);
		return;	
	}
	
	for (long long e = 0; e <= curr; e++) {
		long long cum_next = cum + e * v[ind];
		long long curr_next = curr - e + R;
		curr_next = min(E, curr_next);
		sub(ind+1, curr_next, cum_next, res);	
	}
}

int func() {
	long long res = 0;
	long long cum = 0;
	sub(0, E, cum, res);
	return res;
}

void solve() {
	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-attempt0.out");
	int T = 0;
	in >> T;
	for (int t = 1; t <= T; t++) {
		in >> E;
		in >> R;
		in >> N;
		v.resize(N);
		for (int i = 0; i < N; i++) {
			in >> v[i];	
		}
		
		long long res = func();
		
		out << "Case #" << t << ": " << res << endl;
		//cout << "Case #" << t << ": " << res << endl;
	}
	in.close();
	out.close();
}

int main() {
	solve();	
	return 0;	
}
