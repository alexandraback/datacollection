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
const int MAXN = 100 + 20;

int gp[MAXN];

int solve(int A, int n){
	int ans = n, tmp = 0;
	FOR(i, n){
		// cout << i << ", " << A << " : " << gp[i] << endl;
		while(A <= gp[i]){
			A += A - 1;
			if(A == 1) return ans;
			tmp ++;
			// cout << A << ", " << tmp << endl;
		}
		ans = min(ans, tmp + n - i - 1);
		A += gp[i];
	}
	return ans;
}

int main(){

	int T; cin >> T;
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		int A, n;
		cin >> A >> n;
		FOR(i, n){
			cin >> gp[i];
		}
		sort(gp, gp + n);
		cout << solve(A, n) << endl;
	}
}