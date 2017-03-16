#include <iostream>
#include <cstring>

using namespace std;

char seen[2000001];
int a, b, len, len10;

int recyc(int x) {
  int c = 0;
  int pos = 10;
  int pos_h = len10;
  for (int i = 2; i <= len; i++) {
    int y = (x % pos) * pos_h + (x / pos);
    if (y >= a && y <= b && !seen[y]) {
      seen[y] = 1;
      c++;
    }
    pos *= 10;
    pos_h /= 10;
  }
  return c * (c+1) / 2;
}

int main() {
  int tc_cnt;
  cin >> tc_cnt;
  for (int tc = 1; tc <= tc_cnt; tc++) {
    cin >> a >> b;
    
    len = 1;
    len10 = 1;
    int chk = a;
    while ((chk /= 10) != 0) {
      len++;
      len10 *= 10;
    }
    
    memset(seen, 0, sizeof(seen));

    int c = 0;
    for (int x = a; x <= b; x++) {
      if (seen[x]) continue;
      seen[x] = 1;
      c += recyc(x);
    }
    
    cout << "Case #" << tc << ": " << c << endl;
  } 
}
