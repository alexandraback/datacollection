#include <iostream>
using namespace std;

int a[1001];
int b[1001];
bool slvd1[1001];
bool slvd2[1001];

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    int cnt = 0;
    bool success = false;
    
    int N; cin >> N;
    for (int i=1;i<=N;i++) {
      cin >> a[i] >> b[i];
      slvd1[i] = false;
      slvd2[i] = false;
    }

    int rem = N;
    int st = 0;
    while (true) {
      if (rem == 0) {success=true;break;}

      bool flag = false;
      for (int n=1;n<=N;n++) {
        if(slvd2[n])continue;
        if(b[n]<=st) {
          slvd2[n]=true;
          rem--; st++;
          if(!slvd1[n]) {st++;slvd1[n]=true;}
          cnt++;
          flag = true;
        }
      }

      if (flag) continue;

      int maxind = 0;
      int maxb = 0;
      for (int n=1;n<=N;n++) {
        if(slvd1[n])continue;
        if(a[n]<=st) {
          if (maxb < b[n]) {maxb=b[n]; maxind=n;}
          flag=true;
        }
      }

      if (!flag) break;
      else {
        slvd1[maxind]=true;
        st++;
        cnt++;
      }
    }

    if (success) {
      printf("Case #%d: %d\n",t,cnt);
    } else {
      printf("Case #%d: Too Bad\n",t);
    }
  }
}
