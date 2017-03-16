// C++ 11
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int ti = 0; ti < T; ++ti) {
    static char S[1001]; scanf(" %1000s", S);
    int N = strlen(S);
    static char T[1001];
    for(int i = 0; i < N; ++i) {
      T[i] = i == 0 ? S[i] : max(T[i-1], S[i]);
    }
    printf("Case #%d: ", ti+1);
    for(int i = N-1; i >= 0; --i) {
      if(T[i] == S[i]) printf("%c", S[i]);
    }
    for(int i = 0; i < N; ++i) {
      if(T[i] != S[i]) printf("%c", S[i]);
    }
    printf("\n");
  }
  return 0;
}
