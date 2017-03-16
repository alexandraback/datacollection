#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <queue>

using namespace std;
vector<int> c;
string u;
vector<int> uc;
string k, l;
int kn, ln;
int s;
string t;
map<string, double> me;
int noi(string &t) {
	int r = 0;
	for (int i = 0; i < (int)t.size() - ln + 1; i++) {
		if (t.substr(i, ln) == l) {
			r++;
		}
	}
	return r;
}
double go() {
	if (t.size() == s) {
		return 0;
	}
	if (me.find(t) != me.end()) {
		return me[t];
	}
	int o = noi(t);
	double r = 0;
	for (int i = 0; i < u.size(); i++) {
		t.push_back(u[i]);
		int no = noi(t);
		r += (go() + no - o) * uc[i] / kn;
		t.pop_back();
	}
	return me[t] = r;
}
void gcj_solve(int caseno, ifstream &in, ofstream &out) {
	me.clear();
	in >> kn >> ln >> s >> k >> l;
	c = vector<int>('Z' + 1);
	t = "";
	u.clear();
	uc.clear();
	for (int i = 0; i < kn; i++) {
		c[k[i]]++;
	}
	for (int i = 0; i < c.size(); i++) {
		if (c[i] > 0) {
			u.push_back(i);
			uc.push_back(c[i]);
		}
	}
	double ex = go();
	string a;
	for (int i = 0; i < l.size(); i++) {
		if (u.find(l[i]) != string::npos) {
			a += l[i];
		}
	}
	double ans = 0;
	if (a.size() != 0) {
		string b;
		for (int i = 0; i < s; i++) {
			b += a[i % a.size()];
		}
		int ma = noi(b);
		ans = ma - ex;
	}
	cout << "Case #" << caseno << ": " <<std::setprecision (7)<< ans << endl;
	out << "Case #" << caseno << ": " <<std::setprecision (7)<< ans << endl;
}
int google_code_jam() {
	ifstream in("B-small-attempt0.in");
	ofstream out("output.out");
	if (!in.is_open() || in.eof() || !out.is_open()) {
		cout << "error" << endl;
		return -1;
	}
	int nc;
	in >> nc;
	for (int i = 1; i <= nc; i++) {
		if (in.eof()) {
			cout << "error 2" << endl;
			return -1;
		}
		gcj_solve(i, in, out);
	}
	in.close();
	out.close();
	return 0;
}

int main() {
	google_code_jam();
}