#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

/*

   _022
   _022
-------
   _044
  _044
 _044

*/

string mul(const string& s, int n)
{
	int cf = 0;
	size_t ilen = s.length();
	string res(ilen, '\0');
	for (size_t i = 0; i < ilen; ++i) {
		int a = s[i] * n + cf;
		res[i] = a % 10;
		cf = a / 10;
	}
	if (cf) {
		res.push_back(cf);
	}
	return res;
}

string sum(const string& a, const string& b)
{
	int cf = 0;
	size_t n = max(a.length(), b.length());
	string res(n, 0);
	for (size_t i = 0; i < n; ++i) {
		int u = (i < a.length() ? a[i] : 0) + (i < b.length() ? b[i] : 0) + cf;
		res[i] = u % 10;
		cf = u / 10;
	}
	if (cf) {
		res.push_back(cf);
	}
	return res;
}

string sqr(const string& s)
{
	size_t n = s.length();
	string acc;
	for (size_t i = 0; i < n; ++i) {
		acc = sum(acc, string(i, 0) + mul(s, s[i]));
	}
	return acc;
}

bool is_pali(const string& s)
{
	for (size_t i = 0, j = s.length() - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

string rev(const string& s)
{
	string result = s;
	reverse(result.begin(), result.end());
	return result;
}

string unvis(const string& s)
{
	string result = s;
	for (size_t i = 0, ilen = result.length(); i < ilen; ++i) result[i] -= '0';
	return result;
}

string vis(const string& s)
{
	string result = s;
	for (size_t i = 0, ilen = result.length(); i < ilen; ++i) result[i] += '0';
	return result;
}

int result = 0;
int result2 = 0;
set<string> fair;

void dfs(int len, int j, string& s)
{
	if (j > (len - 1) / 2) {
		//cout << "Done: " << vis(s) << endl;
		string s2 = vis(sqr(s));
		if (is_pali(s) && is_pali(s2) && s2.length() <= 100) {
			++result2;
			fair.insert(s2);
		}
		++result;
		return;
	}
	for (int k = (j == 0); k <= 3; ++k) {
		s[j] = s[len - 1 - j] = k;
		bool can = true;
		for (int l = 0; l < len * 2 - 1; ++l) {
			int d = 0;
			for (int m = 0; m <= min(len - 1, l); ++m) if (l - m < len) {
				d += s[m] * s[l - m];
			}
			if (d > 9) {
				can = false;
				break;
			}
		}
		//cout << "try " << vis(s) << ": " << boolalpha << can << endl;
		if (can) {
			//cout << vis(s) << endl;
			dfs(len, j + 1, s);
		}
		s[j] = s[len - 1 - j] = 0;
	}
}

bool cmplte(const string& s1, const string& s2) {
	return (s1.length() < s2.length() || s1.length() == s2.length() && s1 <= s2);
}

int main()
{
	for (int len = 1; len <= 50; ++len) {
		string s(len, 0);
		dfs(len, 0, s);
	}
	cerr << fair.size() << endl;

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		string a, b;
		cin >> a >> b;
		int result = 0;
		for (auto i = fair.begin(), iend = fair.end(); i != iend; ++i) {
			if (cmplte(a, *i) && cmplte(*i, b)) {
				++result;
			}
		}
		cout << "Case #" << test + 1 << ": " << result << endl;
	}

}
