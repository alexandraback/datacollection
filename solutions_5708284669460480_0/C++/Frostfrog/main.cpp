#include <iostream>
#include <string>
#include <vector>
#include <map>

#define INPUT "B-small-attempt1.in"
#define OUTPUT "output.txt"

using namespace std;

vector<double> r;
std::map<char, int> char_count;


double exact_match(string &ks, string &ls)
{
	double p = 1;
	char_count.clear();
	for(int i = 0; i < ks.size() ; i++) {
		char c = ks[i];
		if (char_count.count(c)) {
			char_count[c]++;
		} else {
			char_count[c] = 1;
		}
	}

	for(int i = 0; i < ls.size() ; i++) {
		char c = ls[i];
		cerr << c << ": "<< char_count[c] << endl;
		if (char_count.count(c)) {
			p *= double(char_count[c]) /  ks.size();

		} else {
			return 0.0;
		}
	}
	cerr << p << endl;

	return p;
}

double solve_dp(int l, int s, double exact) {
	if (s == l) {
		return exact;
	} else if (s < l) {
		return 0.0;
	}

	if (r[s]  < 0.0) {
		r[s] =  exact * (1.0 + solve_dp(l, s - l, exact)) + (1.0 - exact) * solve_dp(l, s - 1, exact);
	}

	return r[s];
}

///
void solve()
{
	int K, L, S;

	string ks, ls;

	cin >> K >> L >> S;
	cin >> ks >> ls;

	r.clear();
	r.resize(S + 1, -1.0);

	cout.precision(7);
	cout << std::fixed <<solve_dp(L, S, exact_match(ks, ls));

}

int main()
{
	int T, cases = 0;

	freopen("C:\\Users\\Frog\\Downloads\\"INPUT, "r", stdin);
	freopen("C:\\Users\\Frog\\Downloads\\"OUTPUT, "w", stdout);

	cin >> T;

	while (T--) {
		cout << "Case #" << ++cases << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

