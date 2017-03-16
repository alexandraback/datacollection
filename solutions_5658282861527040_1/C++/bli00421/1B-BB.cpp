#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
using namespace std;

#define INS insert
#define MP make_pair
#define PB push_back

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define MEM(p, v) memset(p, v, sizeof(p))
#define SCD(i) scanf("%d", &(i))

typedef long long LL;
typedef pair<int, int> PII;

const int MAX_BITS = 30;
LL dp[MAX_BITS + 1][2][2][2]; 
vector<int> dA, dB, dC;
 

/* DUE CREDIT TO BE GIVEN TO THE EDITORIAL FOR TOPCODER SRM 595 DIV II HARD */
vector<int> bin(int D) {
    vector<int> x;
    for (int i = 0; i < MAX_BITS; i++)
        x.PB((D & (1 << i)) != 0);
    return x;
}
 
LL DP(int n, int a, int b, int c) {
    if (dp[n][a][b][c] != -1) return dp[n][a][b][c];

	dp[n][a][b][c] = 0;
	if (n == 0) return dp[n][a][b][c] = 1;

	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			int z = x & y;
			if ((!a || x <= dA[n - 1]) && (!b || y <= dB[n - 1]) && (!c || z <= dC[n - 1]))
				dp[n][a][b][c] += DP(n - 1, a && (x == dA[n - 1]), b && (y == dB[n - 1]), c && (z == dC[n - 1]));
		}
	}
    
	return dp[n][a][b][c];
}
 
LL getNumber(int A, int B, int C)
{
    dA = bin(A), dB = bin(B), dC = bin(C);
	MEM(dp, -1);
    return DP(MAX_BITS, 1,1,1 );
}

int main(void) {
	freopen("B-large.in", "r", stdin);
	freopen("B-out.txt", "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int A, B, C;
		cin >> A >> B >> C;
		MEM(dp, -1);
		dA = bin(A), dB = bin(B), dC = bin(C);
		cout << "Case #" << t << ": " << getNumber(A - 1, B - 1, C - 1) << "\n";
	}
	return 0;
}
