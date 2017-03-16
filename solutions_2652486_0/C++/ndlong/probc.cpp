#include <iostream>
#include <string>
using namespace std;

int n, m, k, a[15];
bool c[20];
bool mark[10];

string solve() {
  for (int i = 1; i <= k; i++) cin >> a[i];
  for (int i = 1; i <= k; i++)
    if (a[i] == 24) return "234";
    else if (a[i] == 60) return "345";
    else if (a[i] == 30) return "235";
    else if (a[i] == 40) return "245";
    else if (a[i] == 125) return "555";
    else if (a[i] == 64) return "444";
    else if (a[i] == 27) return "333";
    else if (a[i] == 36) return "334";
    else if (a[i] == 45) return "335";
    else if (a[i] == 18) return "233";
    else if (a[i] == 32) return "244";
    else if (a[i] == 48) return "344";
    else if (a[i] == 80) return "445";
    else if (a[i] == 50) return "255";
    else if (a[i] == 75) return "355";
    else if (a[i] == 100) return "455";
  string res = "";
  for (int i = 2; i <= 10; i++) c[i] = false;
  for (int i = 2; i <= 10; i++) 
    for (int j = 1; j <= k; j++)
      if (a[j] % i == 0) c[i] = true;
  for (int i = 2; i <= 5; i++) mark[i] = false;
  if (c[3]) mark[3] = true;
  if (c[5]) mark[5] = true;
  if ((c[2]) && (!c[4])) mark[2] = true;
  if (c[4] && c[3] && c[5]) mark[4] = true;
  if (c[6]) {
    mark[2] = true;
    mark[3] = true;
  }
  if (c[10]) {
    mark[2] = true;
    mark[5] = true;
  }
  for (int i = 2; i <= 5; i++)
    if (mark[i]) res += i + 48;
  while (res.length() < 3) res += '2';
  return res;
}

int main() {
  int test, r;
  cin >> test >> r >> n >> m >> k;
  cout << "Case #1:" << endl;
  for (int t = 1; t <= r; t++) cout << solve() << endl;
  return 0;
}
