#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

vector<int> isp;

void findPrimes() {
	for (int i = 2; i < 1000; ++i) {
		bool ok = true;
		for (int j = 2; j*j <= i; ++j) {
			if (i % j == 0) { ok = false; break;}
		}
		if (ok) isp.push_back(i);
	}
}


bool divide(const string& s, int b, int d) {
	int md = 0;
	int curb = b;
	for (int i = 0; i < s.size(); ++i) {
		md = (md * b) % d;
		if (s[i] == '1') md = (md+1) % d;
	}
	return md == 0;
}

int main()
{
	findPrimes();
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n, j;
		ifs >> n >> j;
		ofs << "Case #" << test+1 << ":" << endl;
		int res  =0;
		set<string> st;
		while (res < j) {
			string s = "1";
			for (int i = 0; i < n-2; ++i) {
				s += '0' + rand() % 2;
			}
			s += "1";
			if (st.count(s) == 0) {
				vector<int> d(11);
				int lres = 0;
				for (int i = 0; i < isp.size(); ++i) {
					int p = isp[i];
					for (int j = 2; j <= 10; ++j) {
						if (d[j] == 0 && divide(s, j, p)) {
							d[j] = p;
							++lres;
						}
					}
					if (lres == 9) break;
				}
				if (lres == 9) {
					++res;
					ofs << s;
					for (int i = 2; i <= 10; ++i) {
						ofs << ' ' << d[i];
					}
					ofs << endl;
				}
			}
		}

	}
	return 0;
}
