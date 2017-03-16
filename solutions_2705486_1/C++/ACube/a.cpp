#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef unsigned long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

const int P1 = 313;
const int P2 = 1023;
const int M2 = 1000000007;

set < string > d[11];

int dp[5000][10];
int f[5000][20][12][12];
int ok[20][5000];
string S;

int doit(int u, int l, int last, int st) {
 	if (f[u][l][last][st]!=-1) return f[u][l][last][st];
 	int &res = f[u][l][last][st];
 	res = 1<<20;

 	string s="", t;
 	for (int i = 0; i < l; i++)
 		s += S[u+i];
 	last--;
 	t = s;
 	for (int i = 0; i < (1<<l); i++) {
 	 	if (__builtin_popcount(i) >= res || !ok[l][i] || (last!=-1 && !((i>>last)&1))) continue;
 	 	bool bad=0;
 	 	for (int j = 0; j < st; j++) if ((i>>j)&1) bad = 1;
 	 	for (int j = last+1; j < l; j++) if ((i>>j)&1) bad = 1;
 	 	if (bad) continue;
 	 	s = t;
 	 	for (int j = 0; j < l; j++) {
			if ((i>>j)&1)
				s[j] = 'z'+1;
 	 	}
 	 	if (d[l-1].find(s)==d[l-1].end()) res = __builtin_popcount(i);
 	}

 	return res;
}

int solve(int u, int st) {
	if (u == SIZE(S)) return 0;
 	if (dp[u][st]!=-1) return dp[u][st];
 	dp[u][st] = 1<<20;

 	for (int i = 1; i <= 10 && u+i<=SIZE(S); i++)
 		for (int k = -1; k < i; k++) {
 			if (k == -1)
	 		 	dp[u][st] = min(dp[u][st], doit(u, i, k+1, st)+solve(u+i, max(0, st-i)));
			else
	 		 	dp[u][st] = min(dp[u][st], doit(u, i, k+1, st)+solve(u+i, max(0, 5-i+k)));
	 	}

 	return dp[u][st];
}

void main2(string s)
{
	S = s;
	memset(dp, -1, sizeof(dp)); memset(f, -1, sizeof(f));
	cerr << s << endl;//TODO
	gout << solve(0, 0) << endl;
}

char ch[5000];

string str[5000];

int main()
{
	string s, t;

	scanf("%d", &test_num);

	for (int i = 1; i <= 10; i++) {
	 	for (int j = 0; j < (1<<i); j++) {
	 		ok[i][j] = 1;
	 		for (int k = 0; k < i; k++) if ((j>>k)&1)
	 			for (int q = k+1; q < i; q++) if ((j>>q)&1)
	 				ok[i][j] &= ((q-k)>4);
	 	}
	}

	for (int it = 0; it < test_num; it++) {
		scanf("%s", ch);
		str[it] = string(ch);
		for (int i = 0; i < SIZE(str[it]); i++) {
			t = "";
			for (int j = 0; j < 10 && i+j<SIZE(str[it]); j++) {
				t += ch[i+j];
				for (int mask = 0; mask < (1<<(j+1)); mask++) {
					if (!ok[j+1][mask]) continue;
					s = t;
					for (int k = 0; k <= j; k++) {
						if ((mask>>k)&1)
							s[k] = 'z'+1;
					}
					d[j].insert(s);
				}
			}
		}
	}

	fclose(stdin);

	cerr << "Here\n";

	freopen("garbled_email_dictionary.txt", "r", stdin);
	while (scanf("%s", ch)!=EOF) {
		s = string(ch);
		t = s;
		for (int i = 0; i < (1<<SIZE(s)); i++) {
			if (!ok[SIZE(s)][i]) continue;
			s = t;
			for (int j = 0; j < SIZE(s); j++)
				if ((i>>j)&1)
					s[j] = 'z'+1;
			if (d[SIZE(s)-1].find(s)!=d[SIZE(s)-1].end()) d[SIZE(s)-1].erase(d[SIZE(s)-1].find(s));
		}
	}

	freopen("output", "w", stdout);
	for (int i = 0; i < test_num; i++) main2(str[i]);

	return 0;
}
