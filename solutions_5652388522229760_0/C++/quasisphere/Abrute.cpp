#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  int64_t T;
  cin >> T;

  for(int64_t t=1;t<=T;t++) {
    int64_t n;
    cin >> n;
    if(n == 0) cout << "Case #" << t << ": INSOMNIA\n";
    else {
      vector<bool> seen(10);
      int64_t cur=n;
      while(true) {
        int64_t tmp=cur;
        while(tmp > 0) {
          seen[tmp%10]=true;
          tmp/=10;
        }
        bool allseen=true;
        for(int64_t d=0;d<10;d++) {
          if(!seen[d]) {
            allseen=false;
            break;
          }
        }
        if(allseen) break;
        cur+=n;
      }
      cout << "Case #" << t << ": " << cur << "\n";
    }
  }
  return 0;
}
