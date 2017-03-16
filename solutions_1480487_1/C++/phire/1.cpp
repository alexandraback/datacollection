#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

bool ok(int j, double v, const VI& a, double b)
{
	double f = v;
	for (int i = 0; i < j; i++) {
		f += max(0.0, v + (a[j] - a[i]) / b);
	}

	for (int i = j + 1; i < a.size(); i++) {
		f += max(0.0, v + (a[j] - a[i]) / b);
	}

	return f > 1.0;
}

double solve(int j, const VI& a, double b)
{
	double mn = 0.0, mx = 1.0;
	while (mx - mn > 1e-9) {
		double mid = (mn + mx)/2;
		if (ok(j, mid, a, b))
			mx = mid;
		else
			mn = mid;
	}

	return (mx + mn) / 2 * 100;
}

int main(int argc, const char* argv[])
{
	int T;
	cout.precision(15);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		int s = 0;
		vector<int> v;

		cin >> N;
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			v.push_back(t);
			s += t;
		}
		cout << "Case #" << i << ": ";
		for (int j = 0; j < N; j++) {
			cout << solve(j, v, s);
			if (j != N-1)
				cout << " ";
			else
				cout << endl;
		}
	}
    return 0;
}
