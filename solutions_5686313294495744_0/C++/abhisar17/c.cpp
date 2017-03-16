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
#include <iomanip>
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



int main() {
	std::ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int tc = 0;
	while (t--) {
		tc++;
		int n;
		cin >> n;
		vector<vector<string>> wds(n);
		REP (i, n) {
			string s1, s2;
			cin >> s1 >> s2;
			wds[i].push_back(s1);
			wds[i].push_back(s2);
		}
		int best = 0;
		FOR (i, 1, 1 << n) {
			int orig = __builtin_popcount(i);
			int mark = i;
			bool done;
			do {
				done = false;
				for (int j = 0; !done && j < n; j++) {
					if (!(mark & (1 << j))) {
						for (int k = 0; !done && k < n; k++) {
							if (mark & (1 << k)) {
								for (int l = 0; !done && l < n; l++) {
									if (k != l && (mark & (1 << l))) {
										if (wds[j][0] == wds[k][0] && wds[j][1] == wds[l][1]) {
											done = true;
											mark |= (1 << j);
										}
									}
								}
							}
						}
					}
				}
			} while (done == true);
			if (mark == (1 << n) - 1) {
				best = max(best, n - orig);
			}
		}
		cout << "Case #" << tc << ": " << best << endl;
	}
	return 0;
}
