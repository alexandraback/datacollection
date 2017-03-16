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

int solveIt(vector<int> &a, vector<int> &b) {
	int res = 0, N = a.size();
	vector<pair<int, int> > ba(N);
	for (int i = 0; i < N; i++) ba[i] = make_pair(b[i], a[i]);
	sort(ba.begin(), ba.end());

	vector<int> d(N, 0);
	int st = 0, n2 = 0, x2 = N-1;
	while (st < N*2) {
		while (n2+1 < N && d[n2] == 2) n2++;
		while (x2 >= 0 && d[x2] == 1) x2--;
		if (ba[n2].first <= st) {
			res++;
			st += 2-d[n2];
//			printf("Do second of %d, %d\n", ba[n2].second, ba[n2].first);
			d[n2] = 2;
			n2++;
			continue;
		}
		int i = x2;
		while (i >= n2) {
			if (!d[i] && ba[i].second <= st) {
				res++;
				st++;
				d[i] = 1;
//				printf("Do first of %d, %d\n", ba[i].second, ba[i].first);
				break;
			}
			i--;
		}
		if (i < n2) return -1;
	}
	return res;
}

int main(int argc, char ** /*argv*/) {
	dbg = argc;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		int N;
		scanf("%d ", &N);
		vector<int> a(N), b(N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &a[i], &b[i]);
		}

		long long res = solveIt(a, b);
		if (res >= N)
			printf("Case #%d: %lld\n", cn, res);
		else
			printf("Case #%d: Too Bad\n", cn);
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

