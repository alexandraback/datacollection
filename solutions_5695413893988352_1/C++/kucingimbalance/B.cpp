#include <bits/stdc++.h>

using namespace std;

int o(char d) {
	return d-'0';
}

void print(vector<int> a, vector<int> b) {
	for (int i = 0; i < (int)a.size(); ++i) {
		printf("%d", a[i]);
	}
	printf(" ");
	for (int i = 0; i < (int)b.size(); ++i) {
		printf("%d", b[i]);
	}
	printf("\n");
}

int n;
string c, j;

#define INF 1000000000000000001LL

int vis[20][2];
long long mem[20][2];
pair<int, int> nxt[20][2], pick[20][2];

long long dp(int p, int more) {
	if (p >= n) return 0;
	long long &ret = mem[p][more];
	if (vis[p][more]) return ret;
	vis[p][more] = 1;
	ret = INF;
	long long ten = 1;
	for (int i = p+1; i < n; ++i) {
		ten *= 10;
	}
	for (int i = 0; i < 10; ++i)
		for (int k = 0; k < 10; ++k) {
			long long dc = (c[p] == '?') ? i : o(c[p]);
			long long dj = (j[p] == '?') ? k : o(j[p]);
			if (dc < dj && !more) continue;
			long long tret = dp(p+1, more | (dc > dj)) + (dc-dj) * ten;
			if (tret < ret) {
				nxt[p][more] = make_pair(p+1, more | (dc > dj));
				pick[p][more] = make_pair(i, k);
				ret = tret;
			}
		}

	return ret;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		cin >> c >> j;
		n = c.size();

		memset(vis, 0, sizeof(vis));
		long long f_ans = dp(0, 0);
		long long ff = 0, fs = 0;
		vector<int> ffa, fsa;
		int p = 0, more = 0;
		if (f_ans != INF) {
			while (p < n) {
				ff = ff*10+((c[p] == '?') ? pick[p][more].first : o(c[p]));
				ffa.push_back(((c[p] == '?') ? pick[p][more].first : o(c[p])));
				fs = fs*10+((j[p] == '?') ? pick[p][more].second : o(j[p]));
				fsa.push_back(((j[p] == '?') ? pick[p][more].second : o(j[p])));
				int np = nxt[p][more].first;
				int nmore = nxt[p][more].second;
				p = np, more = nmore;
			}
		}
		string tmp;
		tmp = c;
		c = j;
		j = tmp;

		memset(vis, 0, sizeof(vis));
		long long s_ans = dp(0, 0);
		long long sf = 0, ss = 0;
		vector<int> sfa, ssa;
		p = 0, more = 0;
		if (s_ans != INF) {
			while (p < n) {
				sf = sf*10+((c[p] == '?') ? pick[p][more].first : o(c[p]));
				sfa.push_back(((c[p] == '?') ? pick[p][more].first : o(c[p])));
				ss = ss*10+((j[p] == '?') ? pick[p][more].second : o(j[p]));
				ssa.push_back(((j[p] == '?') ? pick[p][more].second : o(j[p])));
				int np = nxt[p][more].first;
				int nmore = nxt[p][more].second;
				p = np, more = nmore;
			}
		}

		printf("Case #%d: ", itc);
		if (f_ans < s_ans) {
			print(ffa, fsa);
		}
		else if (f_ans > s_ans){
			print(ssa, sfa);
		}
		else {
			if (ff == ss) {
				if (fs < sf) {
					print(ffa, fsa);
				}
				else {
					print(ffa, sfa);
				}
			}
			else if (ff < ss) {
				print(ffa, fsa);
			}
			else {
				print(ssa, sfa);
			}
		}
	}
	return 0;
}
