#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

#define sz(x) ((int)(x.size()))
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl
#define forn(i, x) for (int i = 0; i < (int)(x); ++i)
#define all(x) x.begin(), x.end()
#define PATH "C:\\Users\\Malkav\\Desktop\\"
#define mn(x, y) x = min(x, y)

typedef long long ll;

const int N = 4000;
const int INF = 1000000;

char s[N + 1];

vector<string> dic;

int first_diff;
int last_diff;
int total_diff;
bool valid;

inline void fill_diff(const string& cur, const int idx) {
	first_diff = -1;
	last_diff = -1;
	total_diff = 0;
	valid = true;
	
	for (int i = 0; i < sz(cur); ++i) {
		if (cur[i] != s[idx + i]) {
			if (last_diff != -1 && i - last_diff < 5) {
				valid = false;
				return;
			}
			last_diff = i;
			total_diff++;
			if (first_diff == -1) {
				first_diff = i;
			}
		}
	}
	
	last_diff = sz(cur) - last_diff - 1;
} 

int solve() {
	int len = strlen(s);
	vector<vector<int> > dp(len + 1, vector<int> (5, INF));
	dp[0][4] = 0;
	for (int i = 0; i < len; ++i) {
		for (int w = 0; w < sz(dic); ++w) {
			if (i + sz(dic[w]) > len) continue;
			fill_diff(dic[w], i);			
			if (!valid) continue;
			
			if (total_diff == 0) {
				for (int j = 0; j < 5; ++j) {
					int new_j = min(4, j + sz(dic[w]));
					mn(dp[i + sz(dic[w])][new_j], dp[i][j]);					
				}
			}
			else {
				for (int j = max(0, 4 - first_diff); j < 5; ++j) {
					mn(dp[i + sz(dic[w])][last_diff], dp[i][j] + total_diff);
				}			
			}			
		}
	}
	
	int ans = INF;
	for (int i = 0; i < 5; ++i) {
		ans = min(ans, dp[len][i]);
	}
	
	return ans;
}



void init() {
	freopen(PATH"garbled_email_dictionary.txt", "r", stdin);
	string str;
	while (cin >> str) {
		dic.push_back(str);
	}
}

int main() {
	init();

	freopen(PATH"c.in", "r", stdin);
	//freopen(PATH"in.txt", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	
	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; ++t) {
		gets(s);
		printf("Case #%d: %d\n", t, solve());
	}
	fflush(stdout);
	fclose(stdout);
	return 0;
}