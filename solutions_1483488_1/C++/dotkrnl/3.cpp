/*       GCJ - Recycled Numbers       */
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int exp[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void process(int c);

int main(void) {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    process(i);
  return 0;
}

int sorted_i(int a);

void process(int c) {
  int beg, end;
  scanf("%d%d", &beg, &end);
  vector<int> data;
  for (int i = beg; i <= end; i++)
    data.push_back(sorted_i(i));
  data.push_back(0x7FFFFFFF);
  sort(data.begin(), data.end());
  long long answer = 0, count = 1;
  for (int i = 1; i < data.size(); i++) {
    if (data[i] != data[i-1]) {
      answer += count * (count - 1) / 2;
      count  = 1;
    } else count++;
  }
  printf("Case #%d: %I64d\n", c, answer);
}

int sorted_i(int a) {
  int expi;
  for (expi = 0; exp[expi+1] <= a; expi++);
  int now = a / exp[expi] + a % exp[expi] * 10,
    min = a;
  while (now != a) {
    if (now < min) min = now;
    now = now / exp[expi] + now % exp[expi] * 10;
  }
  return min;
}