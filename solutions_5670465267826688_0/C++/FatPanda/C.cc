#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


pair<int, char> mult(const pair<int, char>& A, const pair<int, char>& B) {
  pair<int, char> ret;
  char a = A.second;
  char b = B.second;
  if (a == b) {
    return make_pair(A.first ^ B.first ^ (a != '1'), '1');
  } 
  if (a == '1' || b == '1') {
    return make_pair(A.first ^ B.first, A.second ^ B.second ^ '1');
  } 
  if (1 == (b - a + 3) % 3) {
    return make_pair(A.first ^ B.first, 'i' ^ 'j' ^ 'k' ^ A.second ^ B.second);
  }
  return make_pair(A.first ^ B.first ^ 1, 'i' ^ 'j' ^ 'k' ^ A.second ^ B.second);
}


int cut(const int& p, const char& target, const int& l, const int& L, const char* r) {
  pair<int, char> result = make_pair(0, '1');
  for (int i = p; i < l; ++i) {
    result = mult(result, make_pair(0, r[i % L]));
    if (0 == result.first && target == result.second) {
      return (i + 1);
    }
  }
  return -1;
}


int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int N = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int L = 0;
    long long X = 0;
    char r[10001];
    int l = 0;
    int p = 0;
    bool flag = true;
    pair<int, char> result = make_pair(0, '1');
    scanf("%d %I64d", &L, &X);
    scanf("%s", r);
    if (X > 100) {
      X = 100 + (X % 4);
    }
    l = L * X;
    for (int j = 0; j < 2; ++j) {
      p = cut(p, 'i' + j, l, L, r);
      if (-1 == p) {
        flag = false;
        break;
      } 
    }
    if (flag) {
      for (int j = p; j < l; ++j) {
        result = mult(result, make_pair(0, r[j % L]));
      }
    }
    flag = flag && (0 == result.first && 'k' == result.second);

    printf("Case #%d: %s\n", i + 1, flag ? "YES" : "NO");
  }
  return 0;
}
