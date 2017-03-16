#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

ii solve(vector<int> v) {
  const int n = v.size();

  for(int i=0; i<(1<<n); i++) {
    for(int j=i+1; j<(1<<n); j++) {
      if(i==j || i==0 || j==0) continue;
      int a=0, b=0;
      for(int k=0; k<n; k++)
        if((1<<k)&i) a+=v[k];
      for(int k=0; k<n; k++)
        if((1<<k)&j) b+=v[k];
      if(a == b) return ii(i,j);
    }
  }
  return ii(-1,-1);
}

int main() {
  int t; cin >> t;
  for(int cs=1; cs<=t; cs++) {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ii ans = solve(v);
    cout << "Case #" << cs << ":" << endl;
    if(ans==ii(-1,-1)) cout << "Impossible" << endl;
    else {
      for(int k=0; k<n; k++) if((1<<k)&ans.first) cout << v[k] << " ";
      cout << endl;
      for(int k=0; k<n; k++) if((1<<k)&ans.second) cout << v[k] << " ";
      cout << endl;
    }
  }
  return 0;
}
