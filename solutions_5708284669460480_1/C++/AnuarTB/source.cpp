#include <bits/stdc++.h>

#define pii pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<int> big;

const double EPS = 1e-9;
const double PI = acos(-1);

const int MAXN = (int) 2e2 + 7;
const int INF = (int) 1e9 + 7;

int t, n, L, S;
int KMP[MAXN];

string keys, target, s;

double dp[MAXN][MAXN][MAXN];
int coef[MAXN];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    printf("Case #%d: ", cases);
    scanf("%d%d%d", &n, &L, &S);
    for (int i = 0; i <= 100; i++)
      for (int j = 0; j <= 100; j++)
        for (int k = 0; k <= 100; k++)
          dp[i][j][k] = 0, coef[k] = 0;

    cin >> keys >> target;
    for (auto it : keys)
      coef[it]++;

    target.pb('#');
    for (int i = 1; i < target.size(); i++) {
      int j = KMP[i - 1];
      while (j > 0 && target[i] != target[j])
        j = KMP[j - 1];
      
      if (target[i] == target[j]) 
        j++;
      
      KMP[i] = j;
    }
    int maxCnt = (S - L) / (L - KMP[target.size() - 2]) + 1;
    for (auto it : target)
      if (it != '#' && !coef[it]) maxCnt = 0;
    
    dp[0][0][0] = 1;
    for (int len = 0; len < S; len++) {
      for (int cnt = 0; cnt < S; cnt++) {
        for (int pref = 0; pref <= L; pref++) {
          double prob = dp[len][cnt][pref] / double(keys.size());
          for (char put = 'A'; put <= 'Z'; put++) {
            if (!coef[put])continue;
            
            int new_pref = pref;
            while (new_pref > 0 && put != target[new_pref])
              new_pref = KMP[new_pref - 1];
            
            int ncnt = cnt;
            if (put == target[new_pref]) new_pref++;
            if (new_pref == L) ncnt++;
            dp[len + 1][ncnt][new_pref] += prob * double(coef[put]);
          }  
        }  
      }
    }
    double ans = 0;
    for (int pref = 0; pref <= L; pref++)
      for (int cnt = 0; cnt <= S; cnt++)
        ans += dp[S][cnt][pref] * double(maxCnt - cnt);
                                        
    cout << fixed << setprecision(10) << ans << "\n";
    cerr << cases << "+\n";
  }
  return 0;
}
