#include <bits/stdc++.h>

char buff[127];
int n;
int p;

bool empty() {
  return p == n;
}

char pop() {
  char c = buff[p];
  while (p < n && buff[p] == c) {
    ++p;
  }
  return c;
}

void put(char c) {
  --p;
  buff[p] = c;
}

int flip() {
  int cnt = 0;
  while (true) {
    char c = pop();
    if (c == '-') {
      put('+');
    } else {
      if (empty())
        return cnt;
      put('-');
    }
    ++cnt;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%s", buff);
    n = strlen(buff);
    p = 0;
    printf("Case #%d: %d\n", i + 1, flip());
  }
}
