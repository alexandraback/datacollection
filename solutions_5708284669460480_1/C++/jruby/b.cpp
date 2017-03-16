#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int cnt[30];
double prob[30];
double pbsum;
double pp[101][101];
int dd[101][101];
string target, key;
int S, K, L;
int si;

double calc(int idx, int tidx) {
  
  if (pp[idx][tidx] != -1.0)
    return pp[idx][tidx];

  if (idx == S) {
    pp[idx][tidx] = 0.0;
    return 0.0;
  }

  // next
  //cout << "idx: " << idx << " " << tidx << endl;
  double sum = 0.0;
  for (int i=0;i<='Z'-'A';i++) {
    if (cnt[i] > 0) {
      if (target[tidx]-'A' == i) {
        if (tidx == target.size()-1) {
          // complete one word
          sum += prob[i] * (calc(idx+1, 0)  + 1.0);
 //         cout << "p" << prob[i] << endl;
  //        cout << "sum1 : " << i << sum << endl;
        } else {
          sum += prob[i] * calc(idx+1, tidx+1);
   //       cout << "sum2 : " << i << sum << endl;
        }
      } else {
        sum += prob[i] * calc(idx+1, 0);
    //      cout << "sum3 : " << sum << endl;
      }
    }
  }
  //cout << idx << " " << tidx << " : " << sum << endl;
  //cout << sum << endl;
  pp[idx][tidx] = sum;
  return sum;
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
    cin >> K;
    cin >> L;
    cin >> S;
    memset(cnt, 0, sizeof(cnt));

    cin >> key;
    cin >> target;
    for (int i=0;i<key.size();i++) {
      cnt[key[i]-'A']++;
    }
    pbsum = 0.0;
    for (int i=0;i<='Z'-'A';i++) {
      prob[i] = cnt[i] / (double)key.size();
      pbsum += prob[i];
    }
    bool pos = true;
    for (int i=0;i<target.size();i++) {
      if (cnt[target[i]-'A'] == 0) {
        pos = false;
        break;
      }
    }
    if (!pos) {
      cout << "0.0" << endl;
      continue;
    }
    for (int i=0;i<101;i++)
      for (int j=0;j<101;j++)
        pp[i][j] = -1.0;

    // maximum
    si = -1;
    for (int i=1;i<target.size();i++) {
      bool flag = true;
      for (int j=0;j<target.size()-i;j++) {
        if (target[i+j] != target[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        si = i;
        break;
      }
    }

    double pt = 1.0;
    for (int i=0;i<target.size();i++) {
      pt *= prob[target[i]-'A'];
    }

    int maxcnt;
    if (si > 0) {
      maxcnt = (S - (target.size()-si)) / si;
    } else {
      maxcnt = S / target.size();
    }

    //cout << "maccnt : " << maxcnt << endl;
    double md = (double) maxcnt;
    double ret = 0.0;
    for (int i=0;i<=S-L;i++) {
      ret += pt;
    }
    printf("%lf\n", md-ret);
    // calculate ex
	}
	return 0;
}
