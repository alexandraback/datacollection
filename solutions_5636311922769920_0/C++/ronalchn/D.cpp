#include <iostream>

using namespace std;

int main() {
  int K, C, S, T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    cin >> K >> C >> S;

    if (S*C < K) {
      printf("Case #%d: IMPOSSIBLE\n",t);
      continue;
    }
    printf("Case #%d:",t);

    long long k=0;
    for (int i=0;i<S;i++) {
      long long location = 0;
      for (int j=0;j<C;j++) {
        location *= K;
        location += k;
        k++;
        if (k >= K) break;
      }
      cout << " " << (location+1);
      if (k >= K) break;
    }

    printf("\n");
  }

}
