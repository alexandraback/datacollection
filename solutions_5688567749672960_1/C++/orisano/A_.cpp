// {{{ include
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
// }}}

using namespace std;

typedef long long ll;
inline int in(){int x;scanf("%d",&x);return x;}

ll pow10[18];
ll dcost[18];

void bulid(){
  pow10[0] = 1;
  for (int i = 1; i < 18; i++) pow10[i] = pow10[i - 1] * 10;
  for (int i = 1; i < 18; i++){
    dcost[i] = dcost[i - 1];
    dcost[i] += pow10[i / 2] * 2 - 1;
    if (i % 2 == 1) dcost[i] += 9 * pow10[(i - 1) / 2];
  }
}

int main()
{
  bulid();
  int T = in();
  for (int t = 1; t <= T; t++){
    printf("Case #%d: ", t);
    char S[16];
    scanf("%s", S);
    ll N = strtoll(S, NULL, 10);
    ll mini = 1ll << 60;
    ll ans = dcost[strlen(S)];
    string sc = S;
    reverse(sc.begin(), sc.end());
    int sl = sc.size();
    for (int i = 0; i < sl; i++){
      ll low = 0;
      for (int j = 0; j < i; j++){
        low = low * 10 + (sc[j] - '0');
      }
      ll high = 0;
      for (int j = 0; j < sl; j++)
        high = high * 10 + (S[j] - '0');
      mini = min(mini, ans + high + low);
    }
    printf("%lld\n", mini);
  }
  return 0;
}
