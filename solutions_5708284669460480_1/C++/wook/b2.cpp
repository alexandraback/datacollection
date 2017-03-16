#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

int K, L, S, T;
string alphabet;
string target;

vector<int> compute_pi(string &P) {
	vector<int> pi(P.size());
	int k = pi[0] = -1;
	for(size_t i = 1; i < P.size(); ++ i) {
		while(k >= 0 && P[i] != P[k+1]) k = pi[k];
		if(P[i] == P[k+1]) ++k;
		pi[i] = k;
	}
	return pi;
}

vector<int> pi;

pair<double, int> cache[101][102][101];
bool _cached[101][102][101];

pair<double, int> f(int current_length, int matched_state, int found)
{
	if(current_length >= S) {
		// done
		return {(double)found, (int)found};
	}
//	printf("> %d %d %d\n", current_length, matched_state, found);

	pair<double, int> & ret = cache[current_length][matched_state + 1][found];
	if(_cached[current_length][matched_state + 1][found]) return ret;
	_cached[current_length][matched_state + 1][found] = true;

	double &s = ret.first;
	int &mx   = ret.second;

	s = 0;
	mx = 0;
	// generate next alphabet
	for(char a : alphabet) {
		int next_state = matched_state;
		while(next_state >= 0 && target[next_state + 1] != a)
			next_state = pi[next_state];
		if(target[next_state + 1] == a) next_state ++;

		int next_found = found;
		if(next_state == T - 1) { // found!
			next_found ++;
			next_state = pi[next_state];
		}

		auto res2 = f(current_length + 1, next_state, next_found);
		s += res2.first;
		mx = max(mx, res2.second);
	}
	return ret; // {s, mx}
}

double go()
{
	pi = compute_pi(target);
	T = (int) target.length();

	memset(_cached, 0, sizeof _cached);
	double sum;
	int mx;
	tie(sum, mx) = f(0, -1, 0);
	double cnt = pow(K, S);

//	printf("mx = %d, cnt = %.0f, sum = %.9f\n", mx, cnt, sum);
//	return (mx * cnt - sum) / cnt;
	return mx - sum / cnt;
}

int main() {
	int T;
	cin >> T;

	for(int t=1; t<=T; ++t) {
		cin >> K >> L >> S;
		cin >> alphabet >> target;
		printf("Case #%d: %.9f\n", t, go());
	}
	return 0;
}

