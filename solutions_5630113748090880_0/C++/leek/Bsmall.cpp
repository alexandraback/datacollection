#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int h[2501];
int n;


int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    
    cin >> n;
    for(int i=0; i<2501; i++) {
      h[i] = 0;
    }
    for(int i=0; i<n * n * 2 - n; i++) {
      int x;
      scanf("%d", &x);
      h[x] ++;
    }
    vector<int> ret;
    for(int i=0; i<2501; i++) {
      if (h[i] % 2) {
        ret.push_back(i);
      }
    }
    sort(ret.begin() , ret.end());

    printf("Case #%d:",tc);
    for(int i=0;i<ret.size(); i++) {
      cout << ' ' << ret[i];
    }
    cout << endl;
  }

  return 0;
}