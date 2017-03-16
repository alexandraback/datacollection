#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int E, R, N;
vector<int> v;

int f(int e, int i) {
	if (i >= N) return 0;

	int b = 0;
	int ee = min(e + R, E);
	for (int s = 0; s <= ee; s++) {
		b = max(s * v[i] + f(ee - s, i + 1), b);
	}
	return b;
}

int main() {
	//ifstream in("B-large.in");
	ifstream in("B-small.in");
	//ifstream in("B.in");
	ofstream out("B-small.out");

	int T; in >> T;
	for (int x = 1; x <= T; x++) {
		in >> E >> R >> N;
		v = vector<int>(N);
		for (int i = 0; i < N; i++) {
			in >> v[i];
		}
		int res = f(E, 0);
		out << "Case #" << x << ": " << res << endl;
	}

	return 0;
}
