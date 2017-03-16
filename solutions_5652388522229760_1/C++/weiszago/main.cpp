#include <bits/stdc++.h>

using namespace std;

bool kesz(vector<bool>& jegy) {
  bool k = true;
  for (int i=0;i<10;i++) if (!jegy[i]) k = false;
  return k;
}

void berak(vector<bool>& jegy, long long mit) {
  while (mit>0) {
    jegy[mit%10]=true;
    mit/=10;
  }
}

long long solve(long long n) {
  vector<bool> jegy;
  for (int i=0;i<10;i++) jegy.push_back(false);

  long long tart = 0;
  while (!kesz(jegy)) {
    tart+=n;
    berak(jegy, tart);
  }
  return tart;
}

int main() {
  ios_base::sync_with_stdio(false);
  freopen("A-large.in", "r", stdin);
  freopen("ki.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i=0;i<t;i++) {
    long long n;
    cin >> n;
    cout << "Case #" << i+1<<": ";
    if (n==0) {
      cout << "INSOMNIA";
    } else {
      cout << solve(n);
    }
    cout<<endl;
  }
  return 0;
}
