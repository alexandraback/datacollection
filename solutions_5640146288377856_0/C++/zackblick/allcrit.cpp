#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for(int i = (s); i <= (e); i++)


int main()
{
freopen("all_critical.txt", "r", stdin);freopen("allsol.txt", "w", stdout);
	
double p, c[22][22], pw[22], pw2[22];
double dp[22];
  c[0][0] = 1.0;
  REP(i, 1, 20)
  {
    c[i][0] = 1.0;
    REP(j, 1, i) c[i][j] = c[i-1][j-1] + c[i-1][j];
  }
  int tc;scanf("%d", &tc);
  REP(_, 1, tc)
  {printf("Case #%d: ", _);
    scanf("%lf", &p);
    pw[0] = 1.0;
    REP(i, 1, 20) pw[i] = p * pw[i-1];
    pw2[0] = 1.0;
    REP(i, 1, 20) pw2[i] = (1-p) * pw2[i-1];
    dp[0] = 0.0;
    REP(i, 1, 20)
    {
      double tmp = 1;
      REP(j, 0, i-1)
        tmp += c[i][i-j] * pw2[j] * pw[i-j] * dp[j];
      dp[i] = tmp / (1-pw2[i]);
    }
    printf("%.5f\n", dp[20]);
  }
}
			
				
