#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int T;
  cin >> T;
  deque<char> d;
  string s;
  rep(j,T) {
    cin >> s;
    d.clear();
    d.push_back(s[0]);
    for(int i = 1; i < s.size(); ++i) {
      if(s[i] >= d.front())
	d.push_front(s[i]);
      else d.push_back(s[i]);
    }
    cout << "Case #" << j+1 << ": ";
    rep(i,s.size()) {
      cout << d[i];
    }
    cout << endl;
  }
  return 0;
}
