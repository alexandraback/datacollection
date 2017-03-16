#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

char in[N+2];

int main(){
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++){
    int Smax;
    scanf("%d%s", &Smax, in);
    int acc = 0;
    int total = 0;
    for(int i = Smax; i >= 0; i--){
      acc += in[i] - '0';
      total = max(total, acc + i);
    }
    printf("Case #%d: %d\n", t, total - acc);
  }
}
