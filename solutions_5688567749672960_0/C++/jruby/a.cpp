#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int dd[1000001];

int reverse_n(int n) {
  string s = std::to_string(n);
  reverse(s.begin(), s.end());
  return stoi(s.c_str());
}
int N;
int calc(int n) {
  if (n > N)
    return N+1;
  if (dd[n] != -1) return dd[n];
  if (n == N) {
    dd[n] = 1;
    return dd[n];
  }
  int r = reverse_n(n);
  int m2;
  if (r != n && r > n) {
     m2 = calc(r) + 1;
  } 
  int m = calc(n+1) + 1;
  if (r != n && r > n) {
    dd[n] = min(m, m2);
  } else {
    dd[n] = m;
  }
  return dd[n];
}

int main() {
	int T;
	cin >> T;
  
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
    
    memset(dd, -1, sizeof(dd));
    cin >> N;
    int ret = calc(1);
    cout << ret << endl;

	}
	return 0;
}
