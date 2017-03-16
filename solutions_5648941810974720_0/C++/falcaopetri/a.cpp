#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))

#define INF 0x3f3f3f3f
#define MAX -1

#define DEBUG false
#define debug(x) if (DEBUG) cout << #x << " = (" << x << ")\n"

int let[30];
vector<int> v;

int id(char c) { return c - 'A'; }
void solve() {
    // solve 0
    while(let[id('Z')]) {
        let[id('Z')]--;
        let[id('E')]--;
        let[id('R')]--;
        let[id('O')]--;
        v.push_back(0);
    }
    // solve 2
    while(let[id('W')]) {
        let[id('T')]--;
        let[id('W')]--;
        let[id('O')]--;
        v.push_back(2);
    }
    // solve 8
    while(let[id('G')]) {
        let[id('E')]--;
        let[id('I')]--;
        let[id('G')]--;
        let[id('H')]--;
        let[id('T')]--;
        v.push_back(8);
    }
    // solve 4
    while(let[id('U')]) {
        let[id('F')]--;
        let[id('O')]--;
        let[id('U')]--;
        let[id('R')]--;
        v.push_back(4);
    }
    // solve 1
    while(let[id('O')]) {
        let[id('O')]--;
        let[id('N')]--;
        let[id('E')]--;
        v.push_back(1);
    }
    // solve 6
    while(let[id('X')]) {
        let[id('S')]--;
        let[id('I')]--;
        let[id('X')]--;
        v.push_back(6);
    }
    // solve 5
    while(let[id('F')]) {
        let[id('F')]--;
        let[id('I')]--;
        let[id('V')]--;
        let[id('E')]--;
        v.push_back(5);
    }
    // solve 7
    while(let[id('V')]) {
        let[id('S')]--;
        let[id('E')]--;
        let[id('V')]--;
        let[id('E')]--;
        let[id('N')]--;
        v.push_back(7);
    }
    // solve 9
    while(let[id('N')]) {
        let[id('N')]--;
        let[id('I')]--;
        let[id('N')]--;
        let[id('E')]--;
        v.push_back(9);
    }
    // solve 3
    while(let[id('T')]) {
        let[id('T')]--;
        let[id('H')]--;
        let[id('R')]--;
        let[id('E')]--;
        let[id('E')]--;
        v.push_back(3);
    }
}
int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1) {
      string str; cin >> str;
      v.clear();
      memset(let, 0, sizeof let);

      FOR(i,0,str.size()) {
          let[str[i]-'A']++;
      }

      solve();

      sort(v.begin(), v.end());
      cout << "Case #"  << t << ": ";
      FOR(i,0,v.size()) cout << v[i];
      cout << endl;
  }

  return 0;
}
