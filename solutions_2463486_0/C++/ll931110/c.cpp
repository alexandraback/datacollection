#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

vector<long long> fair;

bool isPalin(long long d) {
  vector<int> digits;
  while (d) {
    digits.push_back(d % 10);
    d /= 10;
  }
  for (int i = 0,j = digits.size() - 1; i < j; i++,j--) if (digits[i] != digits[j]) return false;
  return true;
}

int T;

void solveCase(int it) {
  long long A,B;
  cin >> A >> B;
  int ret = 0;
  for (int i = 0; i < fair.size(); i++)
    if (A <= fair[i] && fair[i] <= B) ret++;
  printf("Case #%d: %d\n", it, ret);
}

int main() {  
  for (int i = 1; i <= 1e7; i++) if (isPalin(i))
    if (isPalin(1LL * i * i)) fair.push_back(1LL * i * i);
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
