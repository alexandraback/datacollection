#include <iostream>
using namespace std;

long r, total;

bool check(int val) {
  if (2*r + 2*val - 1 <= (total/val)) return true;
  return false;
}

void solve(int t) {
  cin >> r >> total;
  cout << "Case #" << t << ": ";
  int first = 1;
  int last = 1000000000;
  int mid;
  do {
    mid = (first + last) / 2;
    if (check(mid)) first = mid;
    else last = mid - 1;
  } while (first < last - 1);
  if (check(last)) cout << last << endl;
  else cout << first << endl;
}

int main() { 
  int test;
  cin >> test;
  for (int i = 1; i <= test; i++) solve(i);
  return 0;
}
