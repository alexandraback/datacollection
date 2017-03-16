#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int T;
bool v[1000];
int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    J--; P--; S--;
    for(int i=0; i<1000; i++) v[i] = true;
    vector<int> seq;
    for(int i=0; i<=(100*J + 10 * P + S); i++) {
      int ij = (i/100) % 10;
      int ip = (i/10) % 10;
      int is = i %10;
      if(is > S || ip > P || ij  > J) continue;
      if(!v[i]) continue;
      seq.push_back(i);
      int k1, k2, k3;
      k1 = k2 = k3 = 1;
      for(int j=i+1; j<=(100*J + 10*P + S); j++) {
        int jj = (j/100) % 10;
        int jp = (j/10) % 10;
        int js = j %10;
        if(js > S || jp >P || jj > J) continue;
        if(!v[j]) continue;
        if(jj == ij && ip == jp){ 
          if(k1 == K) v[j] = false;
          else k1 ++;
        }
        if(jj == ij && is == js) {
          if(k2 == K) v[j] = false;
          else k2 ++;
        }
        if(is == js && ip == jp) {
          if(k3 == K) v[j] = false;
          else k3 ++;
        }
      }
    }

    printf("Case #%d: ",tc);
    printf("%d", seq.size());
    printf("\n");
    for(int i=0; i<seq.size(); i++) {
      int sj = (seq[i] / 100) % 10;
      int sp = (seq[i] / 10) % 10;
      int ss = (seq[i])  % 10;
      cout << sj+1 << ' ' << sp+1 << ' ' << ss+1 << endl;
    }
  }

  return 0;
}