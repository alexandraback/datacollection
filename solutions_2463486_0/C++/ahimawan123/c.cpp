#include<iostream>
#include<vector>
using namespace std;

typedef long long LL;

bool isPalin(LL x) {
  int a[20];
  int n = 0;
  while (x > 0) {
    a[n++] = x % 10;
    x /= 10;
  }
  for (int i = n / 2; i >= 0; i--) {
    if (a[i] != a[n-i-1]) return false;
  }
  return true;
}

vector<LL> a;

int main() {
  for (LL i = 1; i <= 10000000; i++) {
    if (! isPalin(i)) continue;
    LL x = i*i;
    if (isPalin(x)) {
      a.push_back(x);
      //cout << x << endl;
    }
  }
  
  //cout << a.size() << endl;

  int cases, ans;
  LL A, B;
  cin >> cases;
  for (int T = 1; T <= cases; T++) {
    cin >> A >> B;
    ans = 0;
    for (int i = 0; i < a.size(); i++) {
      if (A <= a[i] && a[i] <= B) {
	ans++;
	//cout << a[i] << endl;
      }
    }
    printf("Case #%d: %d\n", T, ans);
  }
  return 0;
}
