#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define loop(a,b,c) for (int a = b; a < c; a++) 

using namespace std;

int N=0, E=1, S=2, W=3;

int sum(int n,int missing1=0,int missing2=0) {
  return (n*n+n)/2 - (n < missing1 ? 0 : missing1 + (n < missing2 ? 0 : missing2));
}
int ish(int n,int missing1=0,int missing2=0) {
  int a = sqrt(2*n);
  while (sum(a,missing1,missing2) < n) a++;
  return a;
}

string reprvec(vector<int> vec) {
  char o[5] = "NESW";
  string out;
  loop (i,0,vec.size()) out += o[vec[i]];
  return out;
}

int main() {
  int cases; cin >> cases;
  loop (cs,0,cases) {
    int x,y;
    cin >> x >> y;
    int dtot = abs(x)+abs(y);
    int mvs = ish(dtot)-1;
    vector<int> allmoves(mvs,0);
    int hmflag = 3;
    while (1) {
      if (hmflag == 3) {
        mvs++;
        allmoves.push_back(y > 0 ? 0 : 2);
        hmflag = 0;
      }
      else hmflag += 1;
      //cout << mvs << " " << hmflag << "##\n";
      if ((sum(mvs) - dtot) % 2 == 1) continue;
      loop (i,0,mvs) allmoves[i] = y > 0 ? 0 : 2;
      int mt = (sum(mvs) - dtot) / 2, d, missing1, missing2;
      if (mt <= mvs) { missing1 = mt; missing2 = 0; }
      else {
        if (mt%2 == 1) {
          missing1 = mt/2;
          missing2 = (mt+1)/2;
        }
        else {
          missing1 = mt/2 - 1;
          missing2 = mt/2 + 1;
        }
      }
      //cout << missing1 << " " << missing2 << "\n";
      d = sum(mvs,missing1,missing2) - abs(y);
      if (hmflag >= 2) {
        if (missing1 > 0) allmoves[missing1-1] = x > 0 ? 3 : 1;
      } else {
        if (missing1 > 0) allmoves[missing1-1] = y > 0 ? 2 : 0;
        d -= missing1;
      }
      if (hmflag % 2 == 1) {
        if (missing2 > 0) allmoves[missing2-1] = x > 0 ? 3 : 1;
      } else {
        if (missing2 > 0) allmoves[missing2-1] = y > 0 ? 2 : 0;
        d -= missing2;
      }
      bool flag = true;
      int ctr = abs(x)+abs(y)+5;

      while(d != 0) {
        ctr--;
        if (ctr == 0) break;
        int n = ish(abs(d),missing1,missing2);
        loop(i,0,n) {
          if (i != missing1-1 && i != missing2-1) allmoves[i] = flag ? (x > 0 ? 1 : 3) : (y > 0 ? 0 : 2);
        }
        d += flag ? -sum(n,missing1,missing2) : sum(n,missing1,missing2);
        flag = !flag;
      }
      if (d == 0) { cout << "Case #" << (cs+1) << ": " << reprvec(allmoves) << "\n"; break; }
    }
  }
}
