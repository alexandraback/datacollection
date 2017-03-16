#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int graph[1001][1001];
int ndesc[1001];
int isdesc[1001];
int checked[1001];

int main() {
  int T, N, num=1;
  int i,j,k,n;
  for (cin >> T; T--;) {
    cin >> N;
    memset(graph,0,sizeof(graph));
    memset(ndesc,0,sizeof(ndesc));
    for (i = 0; i < N; i++) {
      cin >> ndesc[i];
      for (j = 0; j < ndesc[i]; j++) {
        cin >> k;
        graph[i][j] = k-1;
      }
    }

    memset(checked,0,sizeof(checked));

    for (i = 0; i < N; i++) {
      if (checked[i]) continue;

      vector<int> stack;
      stack.push_back(i);
      memset(isdesc,0,sizeof(isdesc));

      while (!stack.empty()) {
        j = stack.back();
        stack.pop_back();
        checked[j] = 1;

        for (n = 0; n < ndesc[j]; n++) {
          k = graph[j][n];
          if (isdesc[k]) goto found;
          isdesc[k] = 1;
          stack.push_back(k);
        }

      }
    }

    printf("Case #%d: No\n", num++);
    continue;

found:
    printf("Case #%d: Yes\n", num++);
  }
}
