#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<class T> ostream& operator<<(ostream& os, vector<T> v) {
  for(T x : v) os << x << ", ";
  return os;
}

typedef vector<vector<bool> > graph_t;

string solve(vector<string> zip, graph_t graph) {

  int n = zip.size();
  string ans(50, '9');

  vector<int> v(n);
  rep(i, n) v[i] = i;

  //cerr << "n = " << n << endl;

  do {

    int index = 0;
    int cur = v[index];
    vector<int> stack;

    string conzip = zip[v[index]];

    while(true) {
      //cerr << "cur = " << cur << endl;
      //cerr << "index = " << index << endl;
      if(index >= n-1) break;
      if(graph[cur][v[index + 1]]) {
	stack.push_back(cur);
	index++;
	cur = v[index];
	conzip += zip[v[index]];
      }
      else {
	if(stack.empty()) {
	  conzip = string(50, '9');
	  break;
	}
	cur = stack.back();
	stack.pop_back();
      }
    }

    //cerr << "conzip = " << conzip << endl;
    //cerr << "---------------" << endl;

    if(conzip < ans) {
      ans = conzip;
    }

  } while(next_permutation(v.begin(), v.end()));  

  return ans;
  
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {

    cout << "Case #" << (t+1) << ": ";
    int N, M;
    cin >> N >> M;
    vector<string> zip(N);
    rep(i, N) cin >> zip[i];

    vector<vector<bool> > graph(N, vector<bool>(N, false));
    rep(i, M) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      graph[u][v] = true;
      graph[v][u] = true;
    }

    cout << solve(zip, graph) << endl;

  }

  return 0;
}
