#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-10;
static const double PI = 3.141592653589;
typedef long long ll;

struct S{
  int pos;
  vector<int> visited;
};

string solve(){
  int N;
  cin >> N;

  vector< vector<int> > v;
  for(int i = 0; i < N; i++){
    int M;
    cin >> M;
    v.push_back(vector<int>());
    for(int j = 0; j < M; j++){
      int a;
      cin >> a;
      v[i].push_back(a-1);
    }
  }

  for(int i = 0; i < N; i++){
    if(v[i].size() >= 2){
      S s;
      s.pos = i;      
      queue<S> q;
      q.push(s);

      int memo[1001] = {};

      while(!q.empty()){
	s = q.front();
	//	cout << s.pos << endl;
	q.pop();

	if(memo[s.pos]) return "Yes";
	memo[s.pos] = 1;

	for(int j = 0; j <(int)v[s.pos].size(); j++){
	  S ss = s;
	  ss.pos = v[s.pos][j];
	  q.push(ss);
	}
      }
    }
  }

  return "No";
}

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
