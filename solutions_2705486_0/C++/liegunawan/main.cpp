#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

#define ll long long
#define maxs 4000

typedef struct node {
  ll idx;
  bool isOk;
  struct node * n[26];
} node;

node *root;

typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, pil> piiil;

map <piiil, int> m;

int len;

int track(int i, char *s, int x, node *curr, int in) {
  if (i == len) return (curr->isOk == true ? x : maxs);
  if (m.count(piiil(pii(i, x), pil(in, curr->idx)))) return m[piiil(pii(i, x), pil(in, curr->idx))];
  //  printf("%s %d : %d - %d\n", s, i, x, in);

  if (in > 0) {
    int x1 = maxs, x2 = maxs;
    if (curr->n[s[i] - 'a']) x1 = track(i + 1, s, x, curr->n[s[i] - 'a'], in - 1);
    if (curr->isOk && root->n[s[i] - 'a']) x2 = track(i + 1, s, x, root->n[s[i] - 'a'], in - 1);
    return (m[piiil(pii(i, x), pil(in, curr->idx))] = min(x1, x2));
  }

  int x1 = (curr->n[s[i] - 'a'] ? track(i + 1, s, x, curr->n[s[i] - 'a'], 0) : maxs);
  int x3 = (curr->isOk && root->n[s[i] - 'a'] ? track(i + 1, s, x, root->n[s[i] - 'a'], 0) : maxs);
  int x2 = maxs;
  for (int j = 0; j < 26; j++) {
    x2 = min(x2, (curr->n[j] ? track(i + 1, s, x + 1, curr->n[j], 4) : maxs));
    if (curr->isOk && root->n[j])
      x2 = min(x2, track(i + 1, s, x + 1, root->n[j], 4));
  }

  return (m[piiil(pii(i, x), pil(in, curr->idx))] = min(min(x1, x3), x2));
}

void docase(int icase) {
  char s[maxs + 1];
  scanf("%s", s);
  len = strlen(s);
  m.clear();
  printf("Case #%d: %d\n", icase, track(0, s, 0, root, 0));
}

void push(char *s) {
  node *curr = root;

  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (curr->n[s[i] - 'a'] == NULL) {
      curr->n[s[i] - 'a'] = (node *) malloc(sizeof (node));
      curr->n[s[i] - 'a']->idx = curr->idx * 26 + s[i] - 'a' + 1;
      curr->n[s[i] - 'a']->isOk = false;
    }

    curr = curr->n[s[i] - 'a'];
  }

  curr->isOk = true;
}

int main() {
  root = (node *) malloc(sizeof (node));
  root->isOk = true;
  root->idx = 1;

  FILE *p = fopen("garbled_email_dictionary.txt", "r");
  char s[100];
  while (fscanf(p, "%s", s) != EOF) {
    push(s);
  }

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
    docase(i + 1);

  return 0;
}
