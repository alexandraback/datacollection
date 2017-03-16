#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

set<int> dig;
void addig(int a) {
  while(a) {
    dig.insert(a%10);
    a/=10;
  }
}

int f(int n, int t) {
  dig.clear();
  int ans = 0;
  for(int i = 1;i <= t; ++i) {
    ++ans;
    addig(i*n);
    if(dig.size() == 10) return i*n;
  }
  return 9999;
}

int main() {
  // ios::sync_with_stdio(0);
  freopen("a.in","r",stdin);
  freopen("a.txt","w",stdout);
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    int a;
    cin >> a;
    cout << "Case #" << t << ": ";
    if(a == 0) cout << "INSOMNIA\n";
    else cout << f(a,9999) << "\n";
  }
   return 0;
}