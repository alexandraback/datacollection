#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long LL; 
typedef pair<int, int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
//#define L(x) ((x) << 1)
#define R(x) (((x) << 1) + 1)
#define LB(x) ((x)&(-(x)))
#define SL(x) (1 << (x))
#define X first
#define Y second
const int MAXN = 521196, MAXM = 50 + 5;
string dict[MAXN];
int dp[MAXM][5];
string match;
// set<string> dict;

int check(int p1, int p2, string& word, int m, int& p3){
	int ans = 0;
	p3 = 5;
	// cout << p1 << ", " << word << endl;
	FOR(i, m){
		if(match[p1 - 1] != word[i]){

			if(p1 - p2 < 5)return -1;
			else {
				p2 = p1;
				p3 = m - 1 - i;
			}
			ans ++;
		}
		p1 ++;
	}
	return ans;
}

int main(){
	ifstream myfile ("garbled_email_dictionary.txt");
	FOR(i, MAXN) myfile >> dict[i];
	myfile.close();
	// cout << dict[MAXN - 1] << endl;
	int T; cin >> T; getchar();
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		getline(cin, match);
		int n = match.size();
		FOR(i, 5)dp[0][i] = 0;
		REP(i, 1, n){
			FOR(j, 5){
				dp[i][j] = n + 1;
			}
		}
		REP(i, 1, n){
			FOR(j, 5){
				FOR(k, MAXN){
					int m = dict[k].size();
					if(dp[i - 1][j] <= n + 1 && i + m <= n + 1){
						int p3;
						int tmp = check(i, i - j - 1, dict[k], m, p3);
						if(tmp != -1){
							if(p3 > 4)p3 = 4;
							dp[i + m - 1][p3] = min(dp[i + m - 1][p3], dp[i - 1][j] + tmp);
						}	
					}
				}
			}
		}
		int ans = n + 1;
		FOR(i, 5){
			ans = min(ans, dp[n][i]);
		}
		cout << ans << endl;
	}
}