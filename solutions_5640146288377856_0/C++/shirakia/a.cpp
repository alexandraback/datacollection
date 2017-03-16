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
    int r, c, w;
    cin >> r >> c >> w;

    int ans = 0;
    ans = w + (c - 1) / w;

    printf("Case #%d: %d\n", pn+1, ans);
  }

  return 0;
}
