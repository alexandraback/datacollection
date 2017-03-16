#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pI;
typedef pair<string, int> pSI;
typedef pair<int, string> pIS;
typedef pair<string, string> pSS;

#define FOR(i,n) for(int i=0, upTo##i=n; i<upTo##i; ++i)
#define REVFOR(i,n) for(int i=(n)-1; i>=0; --i)
#define FOR2(i,b,n) for(int i=b; i<(n); ++i)
#define REVFOR2(i,b,n) for(int i=(n)-1; i>=b; --i)
#define SC(i) scanf("%d", i)
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define MIN(C) *min_element(ALL(C))
#define MAX(C) *max_element(ALL(C))
#define A first
#define B second

int64 val(string &s) {
	return _atoi64(s.c_str());
}

int64 diff(int64 x, int64 y) {
	int64 res = x - y;
	return res < 0 ? -res : res;
}

pair<pSS, int64> test(string &c, string &j, int pos) {

	if (pos == c.size()) {
		return pair<pSS, int64>(pSS(c, j), diff(val(c), val(j)));
	}

	FOR2(i, pos, c.size()) {
		if (c[i] == '?' && j[i] == '?') {
			c[i] = j[i] = '0';
			pair<pSS, int64> res = test(c, j, i + 1);

			c[i] = '0'; j[i] = '1';
			pair<pSS, int64> res2 = test(c, j, i + 1);
			if (res2.second < res.second) {
				res = res2;
			}

			c[i] = '0'; j[i] = '9';
			res2 = test(c, j, i + 1);
			if (res2.second < res.second) {
				res = res2;
			}

			c[i] = '1'; j[i] = '0';
			res2 = test(c, j, i + 1);
			if (res2.second < res.second) {
				res = res2;
			}

			c[i] = '9'; j[i] = '0';
			res2 = test(c, j, i + 1);
			if (res2.second < res.second) {
				res = res2;
			}

			c[i] = j[i] = '?';

			return res;
		}
		else if (c[i] == '?') {
			c[i] = j[i];
			pair<pSS, int64> res = test(c, j, i + 1);

			pair<pSS, int64> res2;
			if (j[i] > '0') {
				c[i] = j[i] - 1;
				res2 = test(c, j, i + 1);
				if (res2.second <= res.second) {
					res = res2;
				}
			}

			c[i] = '0';
			res2 = test(c, j, i + 1);
			if (res2.second <= res.second) {
				res = res2;
			}

			if (j[i] < '9') {
				c[i] = j[i] + 1;
				res2 = test(c, j, i + 1);
				if (res2.second < res.second) {
					res = res2;
				}
			}

			c[i] = '9';
			res2 = test(c, j, i + 1);
			if (res2.second < res.second) {
				res = res2;
			}

			c[i] = '?';
			return res;
		}
		else if (j[i] == '?') {
			j[i] = c[i];
			pair<pSS, int64> res = test(c, j, i + 1);

			pair<pSS, int64> res2;
			if (c[i] > '0') {
				j[i] = c[i] - 1;
				res2 = test(c, j, i + 1);
				if (res2.second <= res.second) {
					res = res2;
				}
			}

			j[i] = '0';
			res2 = test(c, j, i + 1);
			if (res2.second <= res.second) {
				res = res2;
			}

			if (c[i] < '9') {
				j[i] = c[i] + 1;
				res2 = test(c, j, i + 1);
				if (res2.second < res.second) {
					res = res2;
				}
			}

			j[i] = '9';
			res2 = test(c, j, i + 1);
			if (res2.second < res.second) {
				res = res2;
			}

			j[i] = '?';
			return res;
		}
		else {
			continue;
		}

		break;
	}

	return pair<pSS, int64>(pSS(c, j), diff(val(c), val(j)));
}

pair<pSS, int64> test2(string &c, string &j) {
	pair<pSS, int64> resOK = pair<pSS, int64>(pSS(c, j), INT64_MAX);

	bool cOK = true;
	FOR(i, c.size()) {
		int64 diff = INT64_MAX;
		if (c[i] == '?') {
			cOK = false;
			FOR2(k, '0', '9' + 1) {
				c[i] = k;
				pair<pSS, int64> res = test2(c, j);
				if (res.second < diff) {
					diff = res.second;
					resOK = res;
				}
			}
			c[i] = '?';
			break;
		}
	}


	bool jOK = true;
	if (cOK) {
		FOR(i, j.size()) {
			int64 diff = INT64_MAX;
			if (j[i] == '?') {
				jOK = false;
				FOR2(k, '0', '9' + 1) {
					j[i] = k;
					pair<pSS, int64> res = test2(c, j);
					if (res.second < diff) {
						diff = res.second;
						resOK = res;
					}
				}
				j[i] = '?';
				break;
			}
		}
	}

	if (jOK && cOK) {
		resOK = pair<pSS, int64>(pSS(c, j), diff(val(c), val(j)));
	}

	return resOK;
}


void start() {
	int n; cin >> n;
	FOR(_i, n) {

		string c, j;
		cin >> c >> j;

	//	pair<pSS, int64> v1 = test(c, j, 0);
//		pair<pSS, int64> v2 = test2(c, j);

		//if (v1 != v2) {
			//pSS p1 = test(c, j, 0).first;
			//pSS p2 = test2(c, j).first;
			//cout << p1.first << " " << p2.first;
		//}

		pSS res = test(c, j, 0).first;
		printf("Case #%d: %s %s\n", _i + 1, res.first.c_str(), res.second.c_str());
	}
}

int main(void) {
	start();

	return 0;
}
