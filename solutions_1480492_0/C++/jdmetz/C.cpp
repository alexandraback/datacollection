#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;
string readLine();
int readIntLine();
vector<int> readVI(int n);
vector<string> readVS(int n);
vector<int> itokens(string s, string sep);
vector<string> stokens(string s, string sep);

double solveIt(vector<char> &l, vector<int> &s, vector<int> &p) {
	int N = l.size();
	vector<vector<double> > ots(N, vector<double>(N, -1)), ote = ots, ops = ots, ope = ots;
	vector<vector<double> > olapt;
	vector<vector<double> > event;
	for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
		double st = -3, et = -1;
		if (abs(p[i]-p[j]) < 5) {
			st = -1;
			if (s[i] < s[j]) {
				et = (5-(p[j]-p[i]))/(double)(s[j]-s[i]);
			} else if (s[i] > s[j]) {
				et = (5-(p[i]-p[j]))/(double)(s[i]-s[j]);
			} else {
				et = 1e100;
			}
		} else if (s[i] > s[j] && p[i] < p[j]) {
			st = (p[j]-p[i]-5)/(double)(s[i]-s[j]);
			et = (p[j]-p[i]+5)/(double)(s[i]-s[j]);
		} else if (s[i] < s[j] && p[i] > p[j]) {
			st = (p[i]-p[j]-5)/(double)(s[j]-s[i]);
			et = (p[i]-p[j]+5)/(double)(s[j]-s[i]);
		}
		if (st >= -2) {
			ots[i][j] = ots[j][i] = st;
			ote[i][j] = ote[j][i] = et;
			vector<double> olt(4);
			olt[0] = st;
			olt[1] = et;
			olt[2] = i;
			olt[3] = j;
			olapt.push_back(olt);
			olt[1] = j;
			olt[3] = 1;
			event.push_back(olt);
			olt[0] = et;
			olt[3] = -1;
			event.push_back(olt);
//printf("Event %d, %d from %g to %g\n", i, j, st, et);
		}
	}
	sort(olapt.begin(), olapt.end());
	sort(event.begin(), event.end());
	vector<int> ct(N, 0), oln(N), ln;
	for (int i = 0; i < N; i++) oln[i] = l[i] == 'L';
	int ct0 = 0;
	{
		int i = 0;
		while (i < event.size()) {
			int oi = i;
//printf("Time %g\n", event[i][0]);
			while (i < event.size() && event[i][0] == event[oi][0]) {
				int x = event[i][1], y = event[i][2];
				if (event[i][0] >= 0 && !ct[x] && !ct[y]) ct0++;
				ct[x] += event[i][3];
				ct[y] += event[i][3];
//printf("ct[%d] -> %d\n", x, ct[x]);
//printf("ct[%d] -> %d\n", y, ct[y]);
				i++;
			}
		}
	}

	double mntm = -1;
	for (int j = 0; j < (1<<ct0); j++) {
		ln = oln;
		int wct = 0;
		int i = 0;
		bool collide = false;
//		printf("j %d\n", j);
		while (i < event.size()) {
			double t = event[i][0];
//			printf(" Time %g\n", t);
			int oi = i;
			while (i < event.size() && event[i][0] == t) {
				int x = event[i][1], y = event[i][2], w = event[i][3];
				if (w > 0) {
//					printf("%d ct %d ln %d, %d ct %d ln %d\n", x, ct[x], ln[x], y, ct[y], ln[y]);
					if (t >= 0 && !ct[x] && !ct[y]) {
						if (ln[x] == ln[y]) {
							if ((j>>wct++)&1) ln[x] ^= 1;
							else ln[y] ^= 1;
						} else {
							if ((j>>wct++)&1) {
								ln[x] ^= 1;
								ln[y] ^= 1;
							}
						}
					} else if (ct[x] && ct[y]) {
						if (ln[x] == ln[y]) {
							collide = true;
//		printf("  collide %d, %d at %g\n", x, y, t);
							break;
						}
					} else if (ct[y]) {
						ln[x] = ln[y]^1;
					} else {
						ln[y] = ln[x]^1;
					}
				}
				ct[x] += w;
				ct[y] += w;
//		printf("  ct[%d] -> %d (ln %d), ct[%d] -> %d (ln %d)\n", x, ct[x], ln[x], y, ct[y], ln[y]);
				i++;
			}
			if (collide) {
				if (event[i][0] > mntm) mntm = t;
				break;
			}
		}
		if (!collide) return -1;
	}
	return mntm;
}

int main(int argc, char ** /*argv*/) {
	dbg = argc;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		int N;
		scanf("%d ", &N);
		vector<char> l(N);
		vector<int> s(N), p(N);
		for (int i = 0; i < N; i++) {
			scanf("%c %d %d ", &l[i], &s[i], &p[i]);
		}

		double res = solveIt(l, s, p);
		if (res < 0)
			printf("Case #%d: Possible\n", cn);
		else
			printf("Case #%d: %.10lf\n", cn, res);
	}
	return 0;
}








string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}
int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}
vector<int> readVI(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}
vector<string> readVS(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<string> v(n);
	for (int i = 0; i < n; i++) v[i] = readLine();
	return v;
}
vector<string> stokens(string s, string sep = " \n\r\t") {
	vector<string> res;
	int start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}
vector<int> itokens(string s, string sep = " \n\r\t") {
	vector<int> res;
	int start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}

