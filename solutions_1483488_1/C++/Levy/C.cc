#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2000001;

vector<int> lst[MAXN];
char s[100];

void init() {
  for (int i = 1; i < MAXN; ++i) {
    lst[i].clear();
    sprintf(s, "%d", i);
    int l = strlen(s);
    for (int j = 1; j < l; ++j) if (s[j] != '0') {
      int t;
      sscanf(s + j, "%d", &t);
      for (int k = 0; k < j; ++k) t = t * 10 + s[k] - '0';
      if (t < MAXN) lst[i].push_back(t);
    }

    sort(lst[i].begin(), lst[i].end());
    lst[i].resize(unique(lst[i].begin(), lst[i].end()) - lst[i].begin());
  }
}

int main() {
  init();
  int t;
  scanf("%d", &t);
  for (int c = 1; c <= t; ++c) {
    int a, b;
    scanf("%d%d", &a, &b);
    int res = 0;
    for (int i = a; i <= b; ++i) {
      for (vector<int>::iterator it = lst[i].begin(); it != lst[i].end(); ++it) 
	if (*it >= a && *it < i) res++;
    }
    printf("Case #%d: %d\n", c, res);
  }
}
