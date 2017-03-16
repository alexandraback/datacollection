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
  int T, N, h;
  set<int> s;
  cin >> T;
  rep(i,T) {
    s.clear();
    cin >> N;
    rep(j,2*N-1) {
      rep(k,N) {
	cin >> h;
	if(s.count(h) > 0) 
	  s.erase(h);
	else 
	  s.emplace(h);
      }
    }
    cout << "Case #" << i+1 << ":";
    for(auto it = s.begin(); it != s.end(); ++it) {
      cout << " " << *it;
    }
    cout << endl;
  }
  return 0;
}
