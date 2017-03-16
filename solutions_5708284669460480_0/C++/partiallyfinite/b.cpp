#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, k, l, s;
string a, b;

vector<string> f (int i)
{
	if (i == s) {
		vector<string> v;
		v.push_back("");
		return v;
	}
	vector<string> v = f(i + 1), u;
	for (int i = 0; i < a.size(); ++i) for (int j = 0; j < v.size(); ++j) u.push_back(v[j] + a[i]);
	return u;
}

int main ()
{
	cin >> t;
	cout.precision(7);
	for (int i = 0; i ++< t;) {
		cin >> k >> l >> s;
		cin >> a >> b;
		vector<string> v = f(0);
		long long t = 0, mm = 0;
		for (int j = 0; j < v.size(); ++j) {
			long long m = 0;
			for (int k = 0; k <= s - l; ++k) {
				if (!v[j].compare(k, l, b)) ++m;
			}
			mm = max(mm, m);
			t += m;
		}
		long double r = (long double)mm - (long double)t / (long double)v.size();
		cout << "Case #" << i << ": " << r << '\n';
	}
}

