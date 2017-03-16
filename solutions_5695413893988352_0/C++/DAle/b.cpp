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

long long strtoi(const string& s) {
	long long res = 0;
	for (char ch : s) {
		res *= 10;
		res += ch-'0';
	}
	return res;
}

void Go(int step, string& num, vector<long long>& v) {
	if (step > num.size()) {
		v.push_back(strtoi(num));
		return;
	}
	if (num[step] == '?') {
		for (char ch = '0'; ch <= '9'; ++ch) {
			num[step] = ch;
			Go(step + 1, num, v);
		}
		num[step] = '?';
	} else {
		Go(step + 1, num, v);
	}
}

int main()
{
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		string s, t;
		ifs >> s >> t;
		vector<long long> vs, vt;
		Go(0, s, vs);
		Go(0, t, vt);

		long long bestdiff = numeric_limits<long long>::max();
		long long bests, bestt;
		for (auto i : vs) 
			for (auto j : vt) {
				auto d = abs(i-j);
				if (d < bestdiff || d == bestdiff && bests > i || d == bestdiff && bests == i && bestt > j) {
					bestdiff = d;
					bests = i;
					bestt = j;
				}
			}
		ofs << "Case #" << test+1 << ": " << setw(s.size()) << setfill('0') << bests << ' ' << setw(s.size()) << setfill('0') << bestt << endl;
	}
	return 0;
}
