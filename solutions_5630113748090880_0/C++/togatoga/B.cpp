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
int T;


int main() {
  cin >> T;
  for (int case_id = 1; case_id <= T; case_id++) {
    ll N;
    cin >> N;

    map<int, int> degree;
    for (int i = 0; i < 2 * N - 1; i++) {
      for (int j = 0; j < N; j++) {
        int x;
        cin >> x;
        degree[x]++;
      }
    }
    vector<int> seq;
    for (const auto &val : degree){
      int tmp_val = val.first;
      int tmp_deg = val.second;
      if (val.second % 2){
        seq.push_back(tmp_val);
      }
    }
    sort(seq.begin(), seq.end());
    string res = "";
    for (int i = 0; i < seq.size(); i++){
      res = res + " " + to_string(seq[i]);
    }
    printf("Case #%d:%s\n", case_id, res.c_str());

  }
  return 0;
}