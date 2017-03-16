#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

void solve_case(void)
{
	int N;
	cin >> N;
	vector<int> s(N);
	vector<double> y(N, 0.0);
	vector < pair<int, int> > spairs(N);
	int X = 0;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		spairs[i] = pair<int, int>(s[i], i);
		X += s[i];
	}
	double per_contestant = 2.0 / N;
	double total = 2.0;
	sort(spairs.begin(), spairs.end());
	for (int i = N - 1; i >= 0 ; i--) {
		double frac = (double)spairs[i].first / X;
		if (frac > per_contestant) {
			total -= frac;
			per_contestant = total / i;
			y[spairs[i].second] = 0;
		} else {
			total -= per_contestant;
			y[spairs[i].second] = per_contestant - frac;
		}
	}
	cout.precision(6);
	cout << fixed;
	for (int i = 0; i < N; i++) {
		cout << y[i] * 100 << " ";
	}
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
