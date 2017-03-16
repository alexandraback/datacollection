#include <bits/stdc++.h>

using namespace std;

inline void read(int current, bool* seen, int& count)
{
  while (current > 0) {
    if (!seen[current%10]) {
      count++;
      seen[current%10] = true;
    }
    current /= 10;
  }
}

void solveCase ()
{
  int N;
  cin >> N;

  if (N == 0) {
    cout << "INSOMNIA";
    return;
  }

  bool seen[10] = { 0, };
  int count = 0;
  int current = N;
  while (true) {
    read(current, seen, count);
    if (count == 10) {
      printf("%d", current);
      return;
    }
    current += N;
  }
}

int main ()
{
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    solveCase();
    cout << endl;
  }
  return 0;
}
