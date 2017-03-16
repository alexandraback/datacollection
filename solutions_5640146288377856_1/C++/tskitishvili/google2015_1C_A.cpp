#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int64_t reverse(int64_t i)
{
  char buffer[20];
  sprintf(buffer, "%Ld", i);
  string s = buffer;
  std::reverse(s.begin(), s.end());
  return atoll(s.c_str());
}

int64_t solve(int64_t R, int64_t C, int64_t W)
{
  int64_t sum = 0;
  if (R > 1) {
    sum += (R - 1) * (C / W);
  }
  sum += W;
  if ((C - W) > 0) {
    sum += (C - 1) / W;
  }
  return sum;
}

int main (int argc, char *argv[])
{
  int64_t T, R, C, W;
  string s;
  cin >> T;
  for(int i = 0; i<T; ++i) {
    cin >> R >> C >> W;
    cout << "Case #" << i+1 << ": ";
    cout << solve(R, C, W);
    cout << endl;
  }

  return 0;
}

