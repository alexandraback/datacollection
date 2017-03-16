 
/* ========================================

   * File Name : A.cpp

   * Creation Date : 02-05-2015

   * Last Modified : Sat 02 May 2015 06:42:16 PM CEST

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://code.google.com/codejam/contest/8224486/dashboard

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

int rev(int k) {
  int r = 0;
  while (k) {
    r = 10 * r + k % 10;
    k /= 10;
  }
  return r;
}

int main() {
  const int ma = 1000000;

  /* 
  ERR(rev(1234));
  ERR(rev(1201));
  ERR(rev(120));
  ERR(rev(10200));
  ERR(rev(10000));
 */

  // pre-comp
  vector<int> d(ma+1, ma+10);
  queue<int> q;
  q.push(1);
  d[1] = 1;
  while (q.size()) {
    int k = q.front();
    q.pop();
    if (k < ma && d[k+1] > d[k] + 1) {
      d[k+1] = d[k] + 1;
      q.push(k+1);
    }

    int r = rev(k);
    if (d[r] > d[k] + 1) {
      d[r] = d[k] + 1;
      q.push(r);
    }
  }

  int t;
  cin >> t;
  vector<int> n(t);
  REP(i,t) {
    cin >> n[i];
    printf("Case #%d: %d\n", i+1, d[n[i]]);
  }

  return 0;
}
