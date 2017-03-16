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

long long bestdiff, bests, bestt;

long long strtoi(const string& s) {
	long long res = 0;
	for (char ch : s) {
		res *= 10;
		res += ch-'0';
	}
	return res;
}

void updateRecord(const string& s, const string& t) {
	long long si = strtoi(s);
	long long ti = strtoi(t);
	long long d = abs(si - ti);
	if (bestdiff > d || bestdiff == d && bests > si || bestdiff == d && bests == si && bestt > ti) {
		bestdiff = d;
		bests = si;
		bestt = ti;
	}
}

void fill(string& s, char f, int pos) {
	for (int i = pos; i < s.size(); ++i) {
		if (s[i] == '?') s[i] = f;
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

		bestdiff = numeric_limits<long long>::max();
		int n = s.size();
		int near = n;
		for (int i = 0; i < n; ++i) {
			if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
				near = i;
				break;
			}
		}
		if (near < n) {
			for (int i = 0; i <= near; ++i) {
				if (s[i] == '?' && t[i] == '?') {
					string ns = s, nt = t;
					ns[i] = '1'; nt[i] = '0';
					fill(ns, '0', i+1);
					fill(nt, '9', i+1);
					updateRecord(ns, nt);
					ns = s, nt = t;
					ns[i] = '0'; nt[i] = '1';
					fill(ns, '9', i+1);
					fill(nt, '0', i+1);
					updateRecord(ns, nt);
					s[i] = '0'; t[i] = '0';
				} else if (s[i] == '?') {
					if (t[i] < '9') {
						string ns = s, nt = t;
						ns[i] = nt[i]+1;
						fill(ns, '0', i+1);
						fill(nt, '9', i+1);
						updateRecord(ns, nt);
					}
					if (t[i] > '0') {
						string ns = s, nt = t;
						ns[i] = nt[i]-1;
						fill(ns, '9', i+1);
						fill(nt, '0', i+1);
						updateRecord(ns, nt);
					}
					s[i] = t[i];
				} else if (t[i] == '?') {
					if (s[i] < '9') {
						string ns = s, nt = t;
						nt[i] = ns[i]+1;
						fill(ns, '9', i+1);
						fill(nt, '0', i+1);
						updateRecord(ns, nt);
					}
					if (s[i] > '0') {
						string ns = s, nt = t;
						nt[i] = ns[i]-1;
						fill(ns, '0', i+1);
						fill(nt, '9', i+1);
						updateRecord(ns, nt);
					}
					t[i] = s[i];
				} else {
					if (s[i] > t[i]) {
						string ns = s, nt = t;
						fill(ns, '0', i+1);
						fill(nt, '9', i+1);
						updateRecord(ns, nt);
					}
					if (s[i] < t[i]) {
						string ns = s, nt = t;
						fill(ns, '9', i+1);
						fill(nt, '0', i+1);
						updateRecord(ns, nt);
					}
				}
			}
		} else {
			for (int i = 0; i < n; ++i) {
				if (s[i] == '?' && t[i] == '?') s[i] = t[i] = '0';
				else if (s[i] == '?') s[i] = t[i];
				else t[i] = s[i];
			}
			updateRecord(s, t);
		}

		ofs << "Case #" << test+1 << ": " << setw(s.size()) << setfill('0') << bests << ' ' << setw(s.size()) << setfill('0') << bestt << endl;
	}
	return 0;
}
