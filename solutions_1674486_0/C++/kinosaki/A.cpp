#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> node[1000];
vector<int> able[1000];

bool rec( int n){
  able[n].push_back(n);
  for (int i=0; i<node[n].size(); i++){
    if (able[node[n][i]].size() == 0) if(rec(node[n][i])) return true;
    for (int j=0; j<able[node[n][i]].size(); j++){
      able[n].push_back(able[node[n][i]][j]);
    }
  }
  sort(able[n].begin(), able[n].end());
  for (int i=0; i<able[n].size()-1; i++){
    if (able[n][i] == able[n][i+1]) return true;
  }
  return false;
}

int main(){
  int T;
  cin >> T;
  for (int testCase = 1; testCase <=T; testCase++){
    cin >> N;
    for (int i=0; i<N; i++){
      node[i].clear();
      able[i].clear();
      int t;
      cin >> t;
      for (int j=0; j<t; j++){
	int a; cin >> a;
	node[i].push_back(a-1);
      }
    }

    bool f = false;
    for (int i=0; i<N; i++){
      if (able[i].size() == 0) {
	if (rec(i)){
	  f = true;
	  break;
	}
      }
    }
    printf ("Case #%d: ",testCase);
    if (f) {
      printf ("Yes\n");
    } else {
      printf ("No\n");
    }

  }
}
