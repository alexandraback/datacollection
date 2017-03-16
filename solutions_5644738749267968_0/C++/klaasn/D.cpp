#include "cmath"
#include "iostream"
#include "iomanip"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
#include "cassert"
using namespace std;
typedef long long ll;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b)                                                    \
	for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define ITER(c, it) \
	for (auto it = (c).begin(); it != (c).end(); it++)

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int N;
    cin >> N;
    priority_queue<double, vector<double>, greater<double> > a, b, c, d;
    REP(i,1,N) { double v; cin >> v; a.push(v);c.push(v);}
    REP(i,1,N) { double v; cin >> v; b.push(v);d.push(v);}

    int gain = 0;
    while(!a.empty()) {
      double t = a.top(); a.pop();
      while(!b.empty() && t > b.top()) { b.pop();}
      if (b.empty()) {
        gain++;
      } else {
        b.pop();
      }
    }

    int gain2 = 0;
    while(!d.empty()) {
      double t = d.top(); d.pop();
      while(!c.empty() && t > c.top()) { c.pop();}
      if (c.empty()) {
        gain2++;
      } else {
        c.pop();
      }
    }
    
    cout << "Case #" << Ti << ":" << " " << N-gain2 << " " << gain <<  endl;
  }
  return 0;
}
