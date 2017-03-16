#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef long double ld;

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a%b);
}

int main() {
  int tc, cn = 0;
  cin >> tc;
  while (cn++ < tc) {
    string s;
    cin >> s;
    int i;
    fr (i, SZ(s)) if (s[i] == '/') s[i] = ' ';
    istringstream sin(s);
    ll a, b;
    sin >> a >> b;
    ll g = gcd(a, b);
    a /= g; b /= g;

    ll tmp = b, cnt = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      cnt++;
    }

    if (tmp != 1 || cnt > 40) {
      cout << "Case #" << cn << ": impossible" << endl;
      continue;
    }
    
    cnt = 1;
    while (a < b / 2) {
      b /= 2;
      cnt++;
    }
    cout << "Case #" << cn << ": " << cnt << endl;
  }
  return 0;
}
