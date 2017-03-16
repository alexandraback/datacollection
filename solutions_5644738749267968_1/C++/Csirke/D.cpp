#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    int N;

    scanf("%d", &N);

    vector<double> naomis(N), kens(N);

    for(int i = 0; i < N; ++i) {
      scanf("%lf", &(naomis[i]));
    }
    for(int i = 0; i < N; ++i) {
      scanf("%lf", &(kens[i]));
    }

    sort(naomis.begin(), naomis.end());
    sort(kens.begin(), kens.end());

    int score1 = 0, score2 = 0;
    int keni = N-1;
    for(int i = 0; i < N; ++i) {
      if(naomis[N-i-1] > kens[keni]){
        ++score1;
      } else {
        --keni;
      }
    }

    int naomii = N-1;
    for(int i = 0; i < N; ++i) {
      if(kens[N-i-1] < naomis[naomii]) {
        ++score2;
        --naomii;
      }
    }

    printf("%d %d\n", score2, score1);

  }

  return 0;
}
