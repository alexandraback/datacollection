#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

void makeLargest(string& s, int st, int end) {
  for(int i = st; i < end; i++) {
    if(s[i] == '?') s[i] = '9';
  }
}

void makeSmallest(string& s, int st, int end) {
  for(int i = st; i < end; i++) {
    if(s[i] == '?') s[i] = '0';
  }
}

void makeEqual(string& s1, string& s2, int st, int end) {
  for(int i = st; i < end; i++) {
    if(s1[i] == '?') {
      if(s2[i] == '?') s1[i] = s2[i] = '0';
      else s1[i] = s2[i];
    } else {
      if(s2[i] == '?') s2[i] = s1[i];
      else if(s1[i] > s2[i]) {
        makeLargest(s2, i + 1, end);
        makeSmallest(s1, i + 1, end);
        break;
      } else if(s1[i] < s2[i]) {
        makeLargest(s1, i + 1, end);
        makeSmallest(s2, i + 1, end);
        break;
      }
    }
  }
}

void makeABitLarger(string& sl, string& ss, int st, int end) {
  for(int i = end - 1; i >= st; i--) {
    if(sl[i] == '?') {
      if(ss[i] == '?') {
        sl[i] = '1'; ss[i] = '0';
        makeEqual(sl, ss, st, i);
        break;
      }
      else if(ss[i] == '9') {
        sl[i] = '9';
      } else {
        sl[i] = (char) (ss[i] + 1);
        makeEqual(sl, ss, st, i);
        break;
      }
    } else {
      if(ss[i] == '?') {
        if(sl[i] == '0') {
          ss[i] = '0';
        } else {
          ss[i] = (char) (sl[i] - 1);
          makeEqual(sl, ss, st, i);
          break;
        }
      }
      else cerr << "ERROR" << endl;
    }
  }
}

bool better(string& cs, string& js, string& cs2, string& js2) {
  return abs(stoll(cs) - stoll(js)) < abs(stoll(cs2) - stoll(js2));
}

string bestCs, bestJs;

bool better2(string& cs, string& js, string& cs2, string& js2) {
  ll diff1 = abs(stoll(cs) - stoll(js));
  ll diff2 = abs(stoll(cs2) - stoll(js2));
  if(diff1 != diff2) return diff1 < diff2;

  else if(stoll(cs) != stoll(cs2)) return stoll(cs) < stoll(cs2);
  else return stoll(js) < stoll(js2);
}

void goJs(string cs, string js, int k) {
  if(k >= js.size()) {
    if(bestCs.empty() || better2(cs, js, bestCs, bestJs)) {
      cerr << "new: " << cs << " " << js << endl;
      bestCs = cs; bestJs = js;
    }
  }
  else if(js[k] != '?') goJs(cs, js, k + 1);
  else {
    for(int i = 0; i <= 9; i++) {
      string js2 = js;
      js2[k] = '0' + i;
      goJs(cs, js2, k + 1);
    }
  }
}

void goCs(string cs, string js, int k) {
  if(k >= cs.size()) goJs(cs, js, 0);
  else if(cs[k] != '?') goCs(cs, js, k + 1);
  else {
    for(int i = 0; i <= 9; i++) {
      string cs2 = cs;
      cs2[k] = '0' + i;
      goCs(cs2, js, k + 1);
    }
  }
}

int main() {
  int t; scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    cerr << "tc" << tc << endl;
    string cs, js; cin >> cs >> js;

    bestCs = bestJs = "";
    goCs(cs, js, 0);

    cout << "Case #" << tc << ": " << bestCs << " " << bestJs << endl;
  }
  return 0;
}

//int main() {
//  int t; scanf("%d", &t);
//  for (int tc = 1; tc <= t; tc++) {
//    cerr << "tc" << tc << endl;
//    string cs, js; cin >> cs >> js;
//
//    string cs1 = cs, js1 = js;
//    makeEqual(cs1, js1, 0, (int) cs.size());
//
//    cerr << "1: " << cs1 << endl;
//    cerr << "2: " << js1 << endl;
//
//    int sep = 0;
//    while(sep < cs.size() &&
//        (cs[sep] == '?' || js[sep] == '?' || cs[sep] == js[sep])) sep++;
//
//    if(sep < cs.size()) {
//      string cs2 = cs, js2 = js;
//
//      if(cs[sep] > js[sep]) {
//        makeABitLarger(js2, cs2, 0, sep);
//        makeLargest(cs2, sep + 1, (int) cs.size());
//        makeSmallest(js2, sep + 1, (int) cs.size());
//      } else {
//        makeABitLarger(cs2, js2, 0, sep);
//        makeLargest(js2, sep + 1, (int) cs.size());
//        makeSmallest(cs2, sep + 1, (int) cs.size());
//      }
//
//      if(better(cs2, js2, cs1, js1)) { cs1 = cs2; js1 = js2; }
//    }
//
//    cerr << "1: " << cs1 << endl;
//    cerr << "2: " << js1 << endl;
//
//    cout << "Case #" << tc << ": " << cs1 << " " << js1 << endl;
//  }
//  return 0;
//}
