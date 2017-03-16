// Author : Abhisar Singhal
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string>    
#include <sstream>
#include <utility>   
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;

#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
inline void inp( int &n ) {
        n=0; int ch = getcx(); int sign = 1;
        while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getcx(); }
        while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getcx(); }
		n = n * sign;
}

int TF[200][200];

int getNextState(string &pat, int M, int state, int x)
{
    if (state < M && char('A' + x) == pat[state])
        return state + 1;
 
    int ns, i; 
 
    for (ns = state; ns > 0; ns--) {
        if(pat[ns-1] == char('A' + x)) {
            for(i = 0; i < ns-1; i++) {
                if (pat[i] != pat[state-ns+1+i])
                    break;
            }
            if (i == ns-1) return ns;
        }
    }
    return 0;
}
 
void computeTF(string &pat, int M) {
    int state, x;
    for (state = 0; state <= M; state++)
        for (x = 0; x < 26; x++)
           TF[state][x] = getNextState(pat, M,  state, x);
}
 
VI build_jump_table(string target) {
    VI table(LEN(target) + 1);
	
	table[0] = -1; /* unused by the matcher, just used here */
    
	for(int i = 0; i < LEN(target); i++) {
        table[i+1] = table[i] + 1;
        while(table[i+1] > 0 && target[i] != target[table[i+1] - 1]) {
            table[i + 1] = table[table[i + 1] - 1] + 1;
        }
    }
    return table;
}

double dp[200];
double temp[200];
int myHash[26];
int main() {
	std::ios_base::sync_with_stdio(false);
	int t, tc = 0;
	cin >> t;
	while (t--) {
		tc ++;
		int keySize, len, rounds;
		cin >> keySize >> len >> rounds;
		string key, str;
		cin >> key >> str;
		double ans = 0;
		bool ok = 1;
		if (rounds < len) ok = 0;
		REP (i, len) {
			if (find(ALL(key), str[i]) == key.end()) ok = 0;
		}
		if (!ok) {
			printf("Case #%d: %.9lf\n", tc, ans);
			continue;
		}

		VI table = build_jump_table(str);
		int match = table[LEN(str)];
		int req = len - match;
		int maxBananas = 1 + (rounds - len) / req;
		double expBananas = 0;

		computeTF(str, len);
		MS(myHash);
		REP (i, keySize) myHash[key[i] - 'A'] ++;
		REP (i, 109) dp[i] = 0;
		dp[0] = 1;
		FOR (i, 1, rounds + 1) {
			REP (i, 109) temp[i] = dp[i];
			REP (i, 109) dp[i] = 0;
			REP (j, len + 1) {
				REP (k, 26) {
					int ns = TF[j][k];
					dp[ns] += (temp[j] * double(myHash[k]) / keySize);
				}
			}
			ans += dp[len];
		}
		printf("Case #%d: %.9lf\n", tc, maxBananas - ans);
	}
	return 0;
}


