#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int limits[] = {10, 100, 1000};

bool check(string score, string base){
	while (score.size() < base.size()){
		score = "0" + score;
	}
	for (int i = 0; i < score.size(); i++){
		if (score[i] != base[i]){
			if (base[i] == '?')continue;
			return false;
		}
	}
	return true;
}

void solve(int case_id, string C, string J) {
  int N = C.size();
  int limit = limits[N - 1] - 1;
  int res_diff = INF;
  int ans_c = INF;
  int ans_j = INF;
  for (int i = 0; i <= limit; i++){
  	for (int j = 0; j <= limit; j++){
  		if (res_diff <= abs(i - j))continue;
  		string score_c = to_string(i);
  		string score_j = to_string(j);
  		if (check(score_c, C) and check(score_j, J)){
  			if (res_diff == abs(i - j)){
  				if (ans_c > i){
  					ans_c = i;
  					ans_j = j;
  				}
  				if (ans_c == i){
  					if (ans_j > j){
  						ans_c = i;
  						ans_j = j;
  					}
  				}
  			}else{
  				res_diff = abs(i - j);
  				ans_c = i;
  				ans_j = j;
  			}
  		}
  	}
  }
  string score_c = to_string(ans_c);
  string score_j = to_string(ans_j);
  while (score_c.size() < C.size()){
  	score_c = "0" + score_c;
  }
  while (score_j.size() < J.size()){
  	score_j = "0" + score_j;
  }
  printf("Case #%d: %s %s\n", case_id, score_c.c_str(), score_j.c_str());
}
int main() {
  int T;
  cin >> T;
  for (int case_id = 1; case_id <= T; case_id++) {
    string C, J;
    cin >> C >> J;
    solve(case_id, C, J);
  }
  return 0;
}