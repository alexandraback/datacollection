#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std; 

int N;
int d[1000];
int n[1000];
int w[1000];
int e[1000];
int s[1000];
int dd[1000];
int dp[1000];
int ds[1000];
int h[10000];
int nh[10000];

#define OH 5000

int main() {
  int T;
  cin>>T;
    int minp = 0, maxp = 0;
  for (int t=1;t<=T;++t) {
    memset(h,0,sizeof(h));
    cin>>N;
    for (int i=0;i<N;++i) {
      cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];
    }
    int done = 0;
    int day = 0;
    int ans = 0;
    while (done < N) {
      bool active = false;
      for (int i=0;i<N;++i) {
        if (n[i] == 0) continue;

        if (day == d[i] || day > d[i] && (day-d[i])%dd[i] == 0) {
          if (!active) {
            active = true;
            memcpy(nh, h, sizeof(nh));
          }
          n[i]--;
          
          bool success = false;
          for (int j=w[i];j<e[i];++j) {
            if (h[j+OH] < s[i]) {
              success = true;
            }
            minp = min(minp, j);
            maxp = max(maxp, j);
            nh[j+OH] = max(nh[j+OH], s[i]);
          }

          if (success) {
            ans++;
            s[i] += ds[i];
          } else {
            s[i] += ds[i];
            if (s[i] < 0) s[i] = 0;
          }
          
          w[i] += dp[i];
          e[i] += dp[i];
          if (n[i] == 0) ++done;
        }
      }
      if (active) {
        memcpy(h, nh, sizeof(nh));
      }

      ++day;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}
