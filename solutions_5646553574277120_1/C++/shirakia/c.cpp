#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define dd(x)  cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back

using namespace std;

int main() {
  int ans = 0;
  int problem_num;

  cin >> problem_num;

  FOR(pn,0,problem_num) {
    LL c, d, v;
    cin >> c >> d >> v;

    vector<LL> diff;
    FOR(i,0,d) {
      LL a;
      cin >> a;
      diff.PB(a);
    }
    SORT(diff);

    int ans = 0;
    int current = 0;
    VI coins;
    while(true) {
      LL sum = 0;
      FOR(i,0,coins.size()) sum += coins[i] * c;
      if (v <= sum) break;

      // dd(current);
      // dd(diff[current]);
      if (current < diff.size() && diff[current] <= sum + 1) {
        coins.PB(diff[current]);
        current++;

        //printf("%d %d\n", sum+1, ans);
      } else { // no diff to use
        coins.PB(sum+1);
        ans++;

        //printf("%d %d added\n", sum+1, ans);
      }
    }

    printf("Case #%d: %d\n", pn+1, ans);
  }
  return 0;
}
