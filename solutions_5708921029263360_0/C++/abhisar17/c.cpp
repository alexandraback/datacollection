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

int combAB[4][4];
int combBC[4][4];
int combAC[4][4];

int c1[1009];
int c2[1009];
int c3[1009];
int sz;

int main() {
	std::ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int tc = 0;
	while (t--) {
		tc++;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int best = 0, besti = 0;
		sz = 0;
		MS(combAB);
		MS(combBC);
		MS(combAC);
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j<= b; j++) {
				for (int k = 1; k <= c; k++) {
					c1[sz] = i;
					c2[sz] = j;
					c3[sz++] = k;
				}
			}
		}
		if (a == 3 && b == 3 && c == 3) {
			if (d >= 3) {
				best = 27;
				besti = 134217727;
			} else if (d == 2) {
				best = 18;
				besti = 62580637;
			} else if (d == 1) {
				best = 9;
				besti = 22102794; 
			}
			printf("Case #%d: %d\n", tc, best);
			REP (i, sz) {
				if (besti & (1 << i)) {
					printf("%d %d %d\n", c1[i], c2[i], c3[i]);
				}
			}
			continue;
		}
		for (int i = 0; i < (1 << sz); i++) {
			bool ok = true;
			MS(combAB);
			MS(combBC);
			MS(combAC);
			for (int j = 0; j < sz && ok; j++) {
				if (i & (1 << j)) {
					combAB[c1[j]][c2[j]]++;
					if (combAB[c1[j]][c2[j]] > d) {
						ok = false;
						break;
					}
					combBC[c2[j]][c3[j]]++;
					if (combBC[c2[j]][c3[j]] > d) {
						ok = false;
						break;
					}
					combAC[c1[j]][c3[j]]++;
					if (combAC[c1[j]][c3[j]] > d) {
						ok = false;
						break;
					}

				}
			}
			if (ok && __builtin_popcount(i) > best) {
				best = __builtin_popcount(i);
				besti = i;
			}
		}
		printf("Case #%d: %d\n", tc, best);
		REP (i, sz) {
			if (besti & (1 << i)) {
				printf("%d %d %d\n", c1[i], c2[i], c3[i]);
			}
		}

	}
	return 0;
}
