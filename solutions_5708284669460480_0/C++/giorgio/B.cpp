#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)(x.size())
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define FORIT(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define position first
#define speed second
using namespace std;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

char str_template[] = "Case #%d:";
char str_answer[sizeof(str_template)];
const int MAX = 1010;
const double EPS = 10e-12;

double prob[MAX];
int K, L, S;
string keyboard, target;
double max_bring, expected_bring;

vector<pair<char, double> > dfs_stack;
vector<pair<char, double> > prob_vec;

void dfs(int depth) {
	if (depth == S) {
		string str = "";
		double prob = 1;
		double get = 0;

		for (int i = 0; i < S; ++i) {
			str.push_back(dfs_stack[i].first);
			prob *= dfs_stack[i].second;
		}
		for (int i = L - 1; i < S; ++i) {
			if (str.substr(i - (L - 1), L) == target) {
				get += 1.0;
			}
		}
		//cout << str << " " << L << " " << S << " " << get << " " << prob << endl;
		max_bring = max(max_bring, get);
		expected_bring += prob * get;
		return;
	}
	for (pair<char, double> p : prob_vec) {
		dfs_stack.push_back(p);
		dfs(depth + 1);
		dfs_stack.pop_back();
	}
}

double brute_force() {
	dfs_stack.clear();
	prob_vec.clear();

	for (int i = 0; i < 128; ++i) {
		if (prob[i] > 0) {
			prob_vec.push_back(make_pair(i, prob[i]));
		}
	}
//	for (pair<char, double> p : prob_vec) {
//		cout << p.first << " " << p.second << endl;
//	}
	dfs(0);
	return 0;
}

double calc_max_bring() {
	return 0;
}

double calc_expected_bring() {
	return 0;
}

void __main() {
	memset(prob, 0, sizeof(prob));
	max_bring = expected_bring = 0;

	cin >> K >> L >> S;
	cin >> keyboard >> target;
	for (char c : keyboard) {
		prob[int(c)] += 1.0 / K;
	}

	if (K <= 7 && L <= 7 && S <= 7) {
		brute_force();
	} else {
		max_bring = calc_max_bring();
		expected_bring = calc_expected_bring();
	}
	cout << setprecision(15) << " " << max_bring - expected_bring << endl;
}

int main() {
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		sprintf(str_answer, str_template, i);
		cout << str_answer;
		__main();
	}
	return 0;
}
