#include <stdio.h>
#include <functional>
#include <map>

// #define DEBUG 1

using namespace std;

int split(int max_val, int bound, const map<int, int, greater<int> >& plates) {
  int table[1001];
  for (int i = 1; i <= bound; ++i) {
    table[bound] = 0;
  }
  for (int i = bound + 1; i <= max_val; ++i) {
    table[i] = i + 1;
    for (int j = 1; j <= i/2; ++j) {
      table[i] = std::min(table[i], 1 + table[j] + table[i-j]);
    }
  }
  map<int, int>::const_iterator it;
  int val, num;
  int total = 0;
  for (it = plates.begin(); it != plates.end(); ++it) {
    val = it->first;
    num = it->second;
#ifdef DEBUG
    printf("bound %d val %d table %d\n", bound, val, table[val]);
#endif
    total += num * table[val];
  }
  return total;
}

int main() {

  int T;
  scanf("%d", &T);

for (int ic = 1; ic <= T; ++ic) {
  map<int, int, greater<int> > plates;
  int D, N;
  scanf("%d", &N);
  while(N--) {
    scanf("%d", &D);
    plates[D]++;
  }
  int max_val = plates.begin()->first;
#ifdef DEBUG
  printf("max val: %d\n", max_val);
#endif
  int answer = max_val + 1;
  for (int i = 1; i <= max_val; ++i) {
    int s = split(max_val, i, plates);
#ifdef DEBUG
    printf("split %d\n", s);
#endif
    if (s + i < answer) {
      answer = s + i;
    }
  }
  if (answer > max_val) {
    printf("wrong\n");
  }
  printf("Case #%d: %d\n", ic, answer);
}
  return 0;
}
