#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int tidx = 1; tidx <= t; tidx++){
    int n, s, p;
    cin >> n >> s >> p;
    vector<int> points(n,0);
    for(int i=0; i<n; i++) cin >> points[i];
    
    int ans = 0;
    for(int i=0; i<n; i++){
      if( points[i] / 3 + (points[i] % 3 ? 1 : 0) >= p ) { ans++; continue; }
      if( s > 0 ){
	int mid = points[i] / 3 + (points[i] % 3 == 2 ? 1 : 0);
	if( mid != 0 && mid + 1 >= p ) { ans++; s--; }
      }
    }
    printf("Case #%d: %d\n",tidx,ans);
  }
  return 0;
}
