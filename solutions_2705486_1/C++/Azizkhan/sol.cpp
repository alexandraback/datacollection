#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std; 

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
#ifdef WIN32
	#define I64d "%I64d"
#else
	#define I64d "%lld"
#endif

typedef pair <int, int> pi;

const int inf = int(1e9);
char s[11111];
set <string> S;
int n;
int dp[5555][6];

int calc(int p, int r) {
	if (p == n) return 0;
	if (r > 5) r = 5;
	int &res = dp[p][r];
	if (res != -1) return res;

	res = inf;
	string t = "";
	for (int i = p; i < p + 10 && i < n; ++i) {
		t += s[i];		
		int len = t.size();

		if (S.find(t) != S.end()) {
			res = min(res, calc(i + 1, len + r));
		}

		for (int j = 5 - r; j < len; ++j) {
			char c1 = t[j];
			t[j] = '?';	
			if (S.find(t) != S.end()) {
				res = min(res, calc(i + 1, len - j) + 1);
			}

			for (int k = j + 5; k < len; ++k) {
				char c2 = t[k];
				t[k] = '?';
				if (S.find(t) != S.end()) {
					res = min(res, calc(i + 1, len - k) + 2);
				}
				t[k] = c2;
			}				

			t[j] = c1;
		}
	}
	return res;
}

int main() {
	freopen("dict.txt", "r", stdin);	
	int mx = 0, mn = 100;
	int iter = 0;
	while (gets(s)) {
		//int n = strlen(s);
		//mx = max(mx, n);
		string t = s;
		int len = t.size();
		S.insert(t);
		mn = min(mn, len);
		for (int i = 0; i < len; ++i) {
			char c1 = t[i];
			t[i] = '?';
			S.insert(t);
			for (int j = i + 5; j < len; ++j) {
				char c2 = t[j];
				t[j] = '?';
				S.insert(t);
				t[j] = c2;
			}
			t[i] = c1;
		}
		++iter;
	}	
	//cerr << iter << endl;
	//printf("%d\n", mx);
	//printf("%d\n", mn);
	freopen("01", "r", stdin);

	int tests;
	scanf("%d", &tests);
	//printf("%d\n", tests);
	for (int casenum = 1; casenum <= tests; ++casenum) {
		scanf("%s", &s);	
		memset(dp, -1, sizeof(dp));
		n = strlen(s);
		int res = calc(0, 5);
		printf("Case #%d: %d\n", casenum, res);	
	}
	return 0;		
}
