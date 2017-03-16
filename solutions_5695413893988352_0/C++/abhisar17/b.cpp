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

int bestDiff = 10000, minA = -1, minB = -1;
string minAS, minBS;

void solve(string s1, string s2, int i, int j) {
	if (i == LEN(s1) && j == LEN(s2)) {
		stringstream ss1, ss2;
		int num1, num2;
		ss1 << s1;
		ss1 >> num1;
		ss2 << s2;
		ss2 >> num2;
		if (abs(num1 - num2) < bestDiff) {
			bestDiff = abs(num1 - num2);
			minA = num1;
			minB = num2;
			minAS = s1;
			minBS = s2;
		} else if (abs(num1 - num2) == bestDiff) {
			if (num1 < minA) {
				minA = num1;
				minB = num2;
				minAS = s1;
				minBS = s2;
			} else if (num1 == minA && num2 < minB) {
				minB = num2;
				minBS = s2;
			}
		}
		return;
	}
	if (i < LEN(s1)) {
		if (s1[i] != '?') solve(s1, s2, i + 1, j);
		else {
		for (int k = 0; k < 10; k++) {
			s1[i] = char('0' + k);
			solve(s1, s2, i + 1, j);
		}
		}
	} else {
		if (s2[j] != '?') solve(s1, s2, i, j + 1);
		else {
		for (int k = 0; k < 10; k++) {
			s2[j] = char('0' + k);
			solve(s1, s2, i, j + 1);
		}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int tc = 0;
	while (t--) {
		tc++;
		string s1, s2;
		cin >> s1 >> s2;
		bestDiff = 10000, minA = -1, minB = -1;
		solve(s1, s2, 0, 0);
		cout << "Case #" << tc << ": " << minAS << " " << minBS << endl;
	}
	return 0;
}
