/*       GCJ - Recycled Numbers       */
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

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
  vector<string> data;
  char t[100]; sprintf(t, "%d", a);
  string end(t), now(t);
  do {
    data.push_back(now);
    sprintf(t, "%s%c", now.c_str() + 1, now.c_str()[0]);
    now = string(t);
  } while (now != end);
  int min = 0x7FFFFFFF;
  for (int i = 0; i < data.size(); i++) {
    int t; sscanf(data[i].c_str(), "%d", &t);
    if (t < min) min = t;
  }
  return min;
}