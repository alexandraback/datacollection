#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
  int v;
  Node *next;
};

int N;
int deg[1001];
Node *out[1001];
bool m[1001];

bool dfs(int k) {
  if (m[k]) return false;
  m[k] = true;
  Node *cur = out[k];
  while (cur != NULL) {
    bool r = dfs(cur->v);
    if (!r) return false;
    cur = cur->next;
  }
  return true;
}

bool test(int k) {
  for (int i = 1; i <= N; ++i) m[i] = false;
  return dfs(k);
}

int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int ni = 1; ni <= ncase; ++ni) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
      deg[i] = 0;
      out[i] = NULL;
    }
    for (int i = 1; i <= N; ++i) {
      int nn;
      scanf("%d", &nn);
      Node *cur = NULL;
      while (nn--) {
        int x;
        scanf("%d", &x);
        deg[x]++;
        if (cur == NULL) {
          cur = new Node;
          cur->v = x;
          cur->next = NULL;
          out[i] = cur;
        } else {
          cur->next = new Node;
          cur = cur->next;
          cur->v = x;
          cur->next = NULL;
        }
      }
    }
    bool res = true;
    for (int i = 1; i <= N; ++i)
      if (deg[i] == 0) {
        if (!test(i)) {
          res = false;
          break;
        }
      }
    printf("Case #%d: %s\n", ni, res ? "No" : "Yes");

    for (int i = 1; i <= N; ++i) {
      Node *cur = out[i];
      while (cur != NULL) {
        Node *prev = cur;
        cur = cur->next;
        delete prev;
      }
    }
  }

  return 0;
}
