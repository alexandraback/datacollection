#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 200;
const int Q = 1e9 + 7;


int dp[M][M], go[M][M];
ld f1[M][M], f2[M][M];

int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tq = 1; tq <= t; tq++){
		int k, l, s;
		string s1, s2;
		cin >> k >> l >> s >> s1 >> s2;
		for (int cc = 0; cc <= l; cc++){
			for (char c = 'A'; c <= 'Z'; c++){
				go[cc][c - 'A'] = 0;
				string cur;
				for (int i = 0; i < cc; i++)
					cur += s2[i];
				cur += c;
				for (int i = 0; i < cc + 1; i++){
					bool ok = true;
					if (i == 0 && cc == l)
						continue;
					for (int j = 0; j < l; j++){
						if (i + j >= cc + 1)
							break;
						if (cur[i + j] != s2[j])
							ok = false;	
					}
					if (ok){
						go[cc][c - 'A'] = min(cc + 1 - i, l);
						break;
					}
					
				}
			}
		}

		for (int i = 0; i<= s; i++)
			for (int j = 0; j <= l; j++)
				dp[i][j] = -Q;
		dp[0][0] = 0;
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= l; j++){
				for (int si = 0; si < k; si++){
					int c1 = go[j][s1[si] - 'A'];
					int q =  (c1 == l);
					dp[i + 1][c1] = max(dp[i + 1][c1], q + dp[i][j]);
				}
			}
		int ma = 0;	
		for (int i = 0; i <= l; i++)
			ma = max(ma, dp[s][i]);
	   	for (int j = 1; j <= s; j++)
			for (int i =0; i<=l; i++)
				f1[j][i] = f2[j][i] = 0.;
	
		f1[0][0] = ma;
		f2[0][0] = 1;
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= l; j++){
				//cout << i << " " << j << " "<< (db)f1[i][j] << " " << (db)f2[i][j] << endl;
				for (int si = 0; si < k; si++){
					int c1 = go[j][s1[si] - 'A'];
					if (c1 == l)
						f1[i + 1][c1] += (f1[i][j] - f2[i][j]) / k;
					else
						f1[i + 1][c1] += f1[i][j] / k;
					f2[i + 1][c1] += f2[i][j] / k;
				}
			}
		ld ans = 0.;
		for (int i = 0; i <= l; i++)
			ans += f1[s][i];
		printf("Case #%d: %.15f\n", tq, (db)ans);
		cerr << tq << endl;
	}

	return 0;
}