#include <stdio.h>
#include <cassert>
#define FOR(i, n) for(int i=0; i<n; i++)

#define I 2
#define J 3
#define K 4

int reduce(int a, int b) {
  assert(a);
  assert(b);
  if (a < 0) return -reduce(-a, b);
  if (b < 0) return -reduce(a, -b);

  int table[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I,-1, K,-J},
    {0, J,-K,-1, I},
    {0, K, J,-I,-1},
  };

  return table[a][b];
}

int convert(char c) {
  if (c == 'i') return I;
  if (c == 'j') return J;
  if (c == 'k') return K;
  assert(false);
}

#define MAXL 10000000
int prefix[MAXL];
int postfix[MAXL];
char data[MAXL];


int power(int x, long long n) {
//  printf("power %d %lld\n", x, n);
  assert(x);
  assert(n >= 0);
  if (n < 5) {
    int res = 1;
    FOR(i, n) res = reduce(res, x);
    return res;
  }
  int tmp = power(reduce(x, x), n / 2);
  if (n % 2) tmp = reduce(tmp, x);
  return tmp;
}


int solve() {
  prefix[0] = 1;
  postfix[0] = 1;

  long long l, rep;
  scanf("%lld %lld\n", &l, &rep);
  assert(l < MAXL - 10);
  scanf("%s", &data[0]);
//  printf("%lld %lld %s\n", l, rep, data);

  FOR(i, l) prefix[i+1] = reduce(prefix[i], convert(data[i]));
//  printf("--\n");
  FOR(i, l) postfix[i+1] = reduce(convert(data[l - 1 - i]), postfix[i]);
//  printf("--\n");
  
  if (power(prefix[l], rep) != reduce(I, reduce(J, K))) return false; // no way

//  printf("power check ok\n");

  int find_i = -1;
  int pos = 0;
  int start = 47;
  while (find_i == -1 && start != 1) {
    if (start == 47) start = 1; // begin iteration
    FOR(i, l+1) {
      if (!i) continue;
      pos++;
      if (reduce(start, prefix[i]) == I) {
        find_i = pos;
        break;
      }
    }
    start = reduce(start, prefix[l]);
  }
//  printf("find_i: %d\n", find_i);
  if (find_i == -1) return false;

  int find_k = -1;
  pos = 0;
  start = 47;
  while (find_k == -1 && start != 1) {
    if (start == 47) start = 1; // begin iteration
    FOR(i, l+1) {
      if (!i) continue;
      pos++;
      if (reduce(postfix[i], start) == K) {
        find_k = pos;
        break;
      }
    }
    start = reduce(postfix[l], start);
  }

//  printf("find_k: %d\n", find_k);
  if (find_k == -1) return false;
  if (find_i + find_k >= l * rep) return false;
  return true;


}

int main() {
  int T;
  scanf("%d", &T);
  FOR(i, T) {
    int res = solve();
    printf("Case #%d: %s\n", i+1, res ? "YES" : "NO");
  }
}
