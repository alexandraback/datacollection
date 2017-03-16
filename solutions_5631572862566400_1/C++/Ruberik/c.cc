#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <stack>
using namespace std;
#define V vector
#define tD typedef
tD long long ll;
tD V<int> vi;
tD V<vi> vii;
tD V<ll> vll;
tD V<string> vs;
tD long double ld;
tD pair<int, int> pii;
#define prr make_pair
#define fr(x,y) for(int x=0;x<(y); ++x)
#define fi(n) fr(i,n)
#define fj(n) fr(j,n)
#define fk(n) fr(k,n)
#define pb push_back
#define sz size()
#define DEBUG 0

int N;
vi friends;
set<int> roots;

int largest() {
  int best = 0;
  // Try cycles
  fi(N) {
    int cur = i;
    int len = 0;
    while(true) {
      cur = friends[cur];
      ++len;
      if (cur == i) break;
      if (len > N + 5) {
	len = 0;
	break;
      }
    }
    best = max(best, len);
  }
  // Find mutual BFFs
  roots = set<int>();
  fi(N) {
    if (friends[friends[i]] == i) {
      roots.insert(i);
    }
  }
  vi longests(N, 0);
  fi(N) {
    int cur = i;
    int len = 0;
    int root = -1;
    if (roots.find(cur) != roots.end()) {
      continue;
    }
    while(true) {
      cur = friends[cur];
      len++;
      if (roots.find(cur) != roots.end()) {
	root = cur;
	break;
      }
      if (cur == i || len > N + 5) {
	break;
      }
    }
    if (root != -1) {
      longests[root] = max(longests[cur], len);
    }
  }
  int sum = 0;
  fi(N) {
    sum += longests[i];
  }
  sum += roots.sz;

  return max(best, sum);
}


int main() {
  int T; cin >> T;
  for (int qw = 1; qw <= T; qw++) {
    cin >> N;
    friends = vi();
    fi(N) { int a; cin >> a; friends.pb(a-1); }
    cout << "Case #" << qw << ": " << largest() << endl;
  }
}
