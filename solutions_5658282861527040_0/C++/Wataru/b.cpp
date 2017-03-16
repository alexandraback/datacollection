#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


vector <int> na, nb, nk;


void convert(vector<int> &a, int x)
{
	a.clear();
	while (x > 0) {
		a.push_back(x & 1);
		x >>= 1;
	}
	while (a.size() < 41) a.push_back(0);
}

void Load()
{
	int a, b, k;
	cin >> a >> b >> k;
	convert(na, a);
	convert(nb, b);
	convert(nk, k);
}


long long dp[60][2][2][2];


void Solve()
{
	memset(dp, 0, sizeof(dp));
	long long ans = 0;
	int i, la, lb, lk;
	dp[40][0][0][0] = 1;

	for (i = 40; i > 0; i--) {
		for (la = 0; la < 2; la++) {
			for (lb = 0; lb < 2; lb++) {
				for (lk = 0; lk < 2; lk++) {
					long long t = dp[i][la][lb][lk];
					int aa, bb;	
					for (aa = 0; aa <= 1; aa++) {
						for (bb = 0; bb <= 1; bb++) {
							int nla = la;
							int nlb = lb;
							int nlk = lk;
							int kk = aa & bb;
							if (aa > na[i-1] && la == 0) continue;						
							if (bb > nb[i-1] && lb == 0) continue;
							if (kk > nk[i-1] && lk == 0) continue;																					
							if (aa < na[i-1]) nla = 1;
							if (bb < nb[i-1]) nlb = 1;							
							if (kk < nk[i-1]) nlk = 1;
							dp[i-1][nla][nlb][nlk] += t;
						}
					}
				}
			}
		}
	}

/*	int j, k;
	for (i = 0; i <= 1; i++)
		for (j = 0; j <= 1; j++)
			for (k = 0; k <= 1; k++) {
				ans += dp[0][i][j][k];
			}                         */
	ans = dp[0][1][1][1];
	cout << ans << "\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
