#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

typedef long long LL;

int main() {
  int cases, k, c, s;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    cin >> k >> c >> s;
    printf("Case #%d:", i);
    vector<LL> ans;
    int pos = 0;
    while (pos < k) {
      LL x = 0;
      for (int j = 0; j < c; j++) {
	x = x * k;
	if (pos < k) {
	  x += pos;
	  pos++;
	}
	//cout << "j " << j << " x " << x << endl;
      }
      ans.push_back(x);
    }
    if (ans.size() <= s) {
      for (int j = 0; j < ans.size(); j++) {
	cout << ' ' << (ans[j] + 1);
      }
      cout << endl;
    } else {
      cout << " IMPOSSIBLE\n";
    }
  }
  return 0;
}
