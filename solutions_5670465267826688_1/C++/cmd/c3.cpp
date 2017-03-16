#if 1
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x)// {cerr << #x << " = " << x << endl;}
#define dbgv(x) //{cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

template<class T> string to_str(const T &a) { oss os; os << a; return os.str(); }
template<> string to_str<LD>(const LD& a) { oss os; os.precision(10); os.setf(ios::fixed); os << a; return os.str(); }
template<class T> T from_str(const string &s) { iss is; T val; is >> val; return val; }
string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }
int _test_start = -1, _test_end = -1;
bool need_to_run(int test) { return _test_start == -1 || (_test_start <= test && test <= _test_end); }

const string symb = "1ijk";
const vector< vector<string> > res1x1 {
  {"1", "i", "j", "k"},
	{"i", "-1", "k", "-j"},
	{"j", "-k", "-1", "i"},
	{"k", "j", "-i", "-1"},
};

string mult(const string& a, const string& b) {
	int cnt = count(a.begin(), a.end(), '-');
	cnt += count(b.begin(), b.end(), '-');
	cnt %= 2;
	int p1 = symb.find(a[a.size() - 1]);
	int p2 = symb.find(b[b.size() - 1]);
	string res = res1x1.at(p1).at(p2);
	if (cnt) {
		res = "-" + res;
		if (res.size() == 3) {
			res = res.substr(2);
		}
	}
	return res;
}

string mult(const string& a, const string& b, const string& c) {
	return mult(a, mult(b, c));
}

template <class It>
vector<string> get_pref_sum(It begin, It end) {
	vector<string> res(1, "1");
	for (auto it = begin; it != end; ++it) {
		res.push_back(mult(res.back(), string(1, *it)));
	}
	return res;
}

bool can(LL k, int k1, int k2, int k3, int rp) {
	if (k1 + k2 + k3 > k) {
		return false;
	}
	k -= k1 + k2 + k3;
	return k % rp == 0;
}

bool can(LL k, int k1, int k2, int rp) {
	return can(k, k1, k2, 0, rp);
}

string mult(const string& s, int l, int r) {
	string res = "1";
	for (int i = l; i <= r; ++i) {
		res = mult(res, string(1, s[i]));
	}
	return res;
}

string brute(LL k, LL len,  string s) {
	string t;
	for (int i = 0; i < k; ++i) {
		t += s;
	}
	s = t;
	if (s.size() > 500) {
		return "XXX";
	}
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			string r1 = mult(s, 0, i);
			string r2 = mult(s, i + 1, j - 1);
			string r3 = mult(s, j, s.size() - 1);
			if (r1 != "i" || r2 != "j" || r3 != "k") {
				continue;
			}
			return "YES";
		}
	}
	return "NO";
}

void solve(int test) {
	// read
	LL k, len;
	cin >> len >> k;
	string s;
	cin >> s;

	if (!need_to_run(test)) return;
	// solve
	bool res = false;
//	res = brute(k, len, s) == "YES";
	struct out_ {
		out_(const bool& res, int test) : res(res), test(test) {}
		~out_() {
			cout << T(test) << " " << (res ? "YES" : "NO") << endl;
		}
		const bool& res;
		const int test;
	} out(res, test);
//	return;
	vector<string> pref = get_pref_sum(s.begin(), s.end());
	vector<string> suf(s.size() + 1);
	suf.back() = "1";
	for (int i = suf.size() - 2; i >= 0; --i) {
		suf[i] = mult(string(1, s[i]), suf[i + 1]);
	}
	
//	reverse(suf.begin(), suf.end());
	set<pair<string, string>> vars;
	for (int i = 0; i < pref.size(); ++i) {
		vars.insert({pref[i], suf[i]});
	}
	map<string, int> first_pref, last_suf;
	for (int i = 0; i < pref.size(); ++i) {
		first_pref.emplace(pref[i], i);
	}
	for (int i = suf.size() - 1; i >= 0; --i) {
		last_suf.emplace(suf[i], i);
	}
	vector<string> rep(1, "1");
	set<string> was({rep[0]});
	for (int i = 1; i < 100; ++i) {
		auto cur = mult(rep.back(), pref.back());
		if (was.count(cur)) {
			assert(cur == rep[0]);
			break;
		}
		was.insert(cur);
		rep.emplace_back(cur);
	}

	dbgv(rep);
	dbg(mult("-k", "j"));
	LL pos1 = -1;
	int block1 = -1, pref1 = -1;
	for (int i = 0; i < rep.size(); ++i) {
		bool found = false;
		for (int j = 0; j < pref.size(); ++j) {
			if (mult(rep[i], pref[j]) == "i") {
				found = true;
				pref1 = j;
				block1 = i;
				break;
			}
		}

		if (found) {
			pos1 = block1 * len + pref1;
			break;
		}
	}
	if (pos1 == -1) {
		dbg("no i");
		return;
	}

	LL pos2 = -1;
	int block2 = -1, suf2 = -1;
	for (int i = 0; i < rep.size(); ++i) {
		bool found = false;
		for (int j = suf.size() - 1; j >= 0; --j) {
			if (mult(suf[j], rep[i]) == "k") {
				found = true;
				suf2 = j;//suf.size() - j - 1;
				block2 = i;
				dbg(j);
				dbg(suf[j]);
				dbg(rep[i]);
				
				break;
			}
		}

		if (found) {
			pos2 = block2 * len + (suf.size() - suf2 - 1);
			break;
		}
	}
	if (pos2 == -1) {
		dbg("no k");
		return;
	}

	dbgv(suf);
	dbg(block1);
	dbg(pref1);
	dbg(block2);
	dbg(suf2);

	pos2 = k * len - pos2 - 1;
	if (pos1 > pos2) {
		dbg(pos1);
		dbg(pos2);
		dbg("overlap");
		return;
	}
	int pf = pref1;
	int sf = suf2;
	if (block1 + block2 > k) { 
		dbg("over");
		return;
	}

	LL rem = k - block1 - block2;
	
	if (rem == 0) {
		dbg("no blocks");
		return;
	}

	if (rem == 1) {
		auto mid = mult(s, pf, sf - 1);
		res = mid == "j";
		return;
	}

	if (rem >= 2) {
		dbg(suf[pf]);
		dbg(pref[sf]);
		dbg(rep[(rem - 2) % rep.size()]);
		auto mid = suf[pf];
		mid = mult(mid, rep[(rem - 2) % rep.size()]);
		mid = mult(mid, pref[sf]);
		dbg(mid);
		res = mid == "j";
		return;
	}
	dbg(rem);
	dbg("no way");
	
	// write
	
	 
}

int main(int argc, char *argv[]) {
	dbg(mult("-i", "j"));
	
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin); freopen(NAME ".out","w",stdout);
	if (argc == 2) { _test_start = _test_end = from_str<int>(argv[1]); }
	if (argc == 3) { _test_start = from_str<int>(argv[1]); _test_end = from_str<int>(argv[2]); }

	clock_t tstart = clock();
	
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; ++test) {
		clock_t tprev = clock();
		solve(test);
		if (need_to_run(test)) {
		//	dbg("elapsed for #" << test << ": " << (clock() - tprev) / LD(CLOCKS_PER_SEC));
		}
	}

	dbg("elapsed: " << (clock() - tstart) / LD(CLOCKS_PER_SEC));
	return 0;
}
/*************************
*************************/
#endif
