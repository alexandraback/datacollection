#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const long long MAX_SIZE = 1000000000000000000ll;
long long K, C, S;
bool overflow;

long long toIndex(const vector<int>& v) {
	assert((int) v.size() == C);
	__int128_t ret = 0;
	__int128_t pow = 1;
	/*cerr << "  inserting";
	for (int i = 0; i < C; i++) {
		cerr << " " << v[i];
	}
	cerr << endl;*/
	for (int i = C - 1; i >= 0; i--) {
		ret += pow * (v[i] % K);
		overflow = overflow || (v[i] >= K);
		pow *= K;
		assert(pow <= (__int128_t) MAX_SIZE);
		assert(ret >= 0 && ret < pow);
	}
	return (long long) ret + 1;
}

void solve() {
	cin >> K >> C >> S;
	assert(K >= 1 && K <= 100);
	assert(C >= 1 && C <= 100);
	assert(S >= 1 && S <= K);
	__int128_t check = 1;
	for (int i = 0; i < C; i++) {
		check *= K;
		assert(check <= (__int128_t) MAX_SIZE);
	}
	if (C * S < K) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	set<long long> solution;
	vector<int> v;
	overflow = false;
	for (int i = 0; i < C; i++) {
		v.push_back(i);
	}
	assert(solution.insert(toIndex(v)).second);
	while (!overflow) {
		for (int i = 0; i < C; i++) {
			v[i] += C;
		}
		if (!solution.insert(toIndex(v)).second) {
			assert(K % C == 0);
			assert(((int) solution.size()) * C == K);
			assert(v[0] == K);
		}
	}
	// shuffle the solution, just for fun :-)
	vector<long long> shuffledSolution;
	for (set<long long>::iterator it = solution.begin(); it != solution.end(); it++) {
		shuffledSolution.push_back(*it);
	}
	assert((int) shuffledSolution.size() <= S);
	assert((int) shuffledSolution.size() == (K + C - 1) / C);
	random_shuffle(shuffledSolution.begin(), shuffledSolution.end());
	for (vector<long long>::iterator it = shuffledSolution.begin(); it != shuffledSolution.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
}

int main() {
	srand(42); // make sure result is reproducible
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":";
		solve();
	}
	return 0;
}
