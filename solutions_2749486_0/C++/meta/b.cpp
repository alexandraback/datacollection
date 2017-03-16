#include <iostream>
#include <algorithm>

using namespace std;

int dist(int x, int y, int a, int b) {
  return abs(a - x) + abs(b - y);
}

bool sameodd(int a, int b) {
  return (a % 2 == b % 2);
}

bool solve(int a, int b, int x, int y, long long sum, int n, char s[], int p) {
  if (p > n) return false;  
  int d = dist(a, b, x, y);
  // cerr << "s: " << s << " d" << d << " " << sum << " " << p << "\n";
  if (d == 0) return true;
  if (d > sum) return false;
  for (int i = 0; i < 4; i++) {
    int j = a;
    int k = b;
    switch (i) {
      case 0:  
        if (a < x) {
          s[p] = 'E';
          j += p + 1; 
        } else {
          s[p] = 'W';
          j -= p + 1; 
        }
        break;
      case 1:
        if (b < y) {
          s[p] = 'N';
          k += p + 1; 
        } else {
          s[p] = 'S';
          k -= p + 1; 
        }
        break;        
      case 2:
        if (a < x) {
          s[p] = 'W';
          j -= p + 1;          
        } else {
          s[p] = 'E';
          j += p + 1; 
        }
        break;        
      case 3:
        if (b < y) {
          s[p] = 'S';
          k -= p + 1;           
        } else {
          s[p] = 'N';
          k += p + 1; 
        }
        break;                        
    }
    if (solve(j, k, x, y, sum - p - 1, n, s, p + 1)) return true;
  }
  s[p] = '\0';
  return false;
}

int main() {
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; c++) {
    char s[500];
    for (int i = 0; i < 500; i++) s[i] = 0;
    int x, y;
    cin >> x >> y;
    int n = 0;
    long long sum = 0;
    int d = dist(x, y, 0, 0);
    for (int i = 0; i < 500; i++) {
      sum += i;
      if (sum < d) continue;
      n = i;      
      break;
    }
    if (!sameodd(sum,d)) {
      n++;
      sum += n;
    }
    // cerr << "sum: " << sum << " n " << n << "\n";
    while (!solve(0, 0, x, y, sum, n, s, 0)) {
      // cerr << "++";
      n++;
      sum+=n;
      n++;
      sum+=n;
      if (n > 500) break;
    }
    cout << "Case #" << c + 1 << ": " << s << "\n";
  }
  return 0;
}