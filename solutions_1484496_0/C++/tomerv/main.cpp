#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<double, int> di;
typedef vector<double> vd;
typedef vector<di> vdi;
typedef multiset<double> sd;


bool is_good(const vi& S, const vi& coeff)
{
	int tot = 0;
	bool all_zeroes = true;
	for (int i = 0; i < S.size(); ++i) {
		if (coeff[i] != 0) {
			all_zeroes = false;
			tot += coeff[i] * S[i];
		}
	}
	return (!all_zeroes && tot == 0);
}

void print_solution(const vi& S, const vi& coeff)
{
	bool first = true;
	for (int i = 0; i < S.size(); ++i) {
		if (coeff[i] == -1) {
			if (!first) cout << ' ';
			cout << S[i];
			first = false;
		}
	}
	cout << endl;
	first = true;
	for (int i = 0; i < S.size(); ++i) {
		if (coeff[i] == 1) {
			if (!first) cout << ' ';
			cout << S[i];
			first = false;
		}
	}
	cout << endl;
}

bool solve1(const vi& S, vi& coeff, int curr, int N)
{
	if (curr == N) {
		if (is_good(S, coeff)) {
			print_solution(S, coeff);
			return true;
		}
		return false;
	}
	coeff[curr] = 0;
	if (solve1(S, coeff, curr+1, N)) {
		return true;
	}
	coeff[curr] = -1;
	if (solve1(S, coeff, curr+1, N)) {
		return true;
	}
	coeff[curr] = 1;
	if (solve1(S, coeff, curr+1, N)) {
		return true;
	}
	return false;
}


void solve(const vi& S)
{
	int N = S.size();
	vi coeff(N, 0);
	if (!solve1(S, coeff, 0, N)) {
		cout << "Impossible" << endl;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vi S(N, 0);
		for (int i = 0; i < N; ++i) {
			cin >> S[i];
		}
		cout << "Case #" << t+1 << ":\n";
		solve(S);
	}
	return 0;
}
