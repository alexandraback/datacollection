#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

template<typename T>
class RMQ {
  vector<vector<pair<T, int>>> sptable;
  vi lg;

public:
  RMQ(vector<T> &v)  {
    int n = (int) v.size();
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
      lg[i] = lg[i/2] + 1;

    sptable.assign(n, vector<pair<T, int>>(lg[n] + 1));
    for (int i = 0; i < n; i++)
      sptable[i][0] = {v[i], -i};

    for (int j = 1; j <= lg[n]; j++){
      for (int i = 0; i + (1 << j) - 1 < n; i++){
	// change min to max for maximum query
	sptable[i][j] = max(sptable[i][j-1], sptable[i + (1 << (j-1))][j-1]); 
      }
    }
  }
  pair<T, int> query(int L, int R){
    int k = lg[R - L + 1];
    // change min to max for maximum query
    return max(sptable[L][k], sptable[R - (1 << k) + 1][k]);
  }
};

void solve(){
  string str; cin >> str;
  int n = (int) str.size();
  string res = string(1, str[0]);
  for (int i = 1; i < n; i++){
    char c = str[i];
    if (c >= res[0]){
      res = c + res;
    } else {
      res += c;
    }
  }
  cout << res << endl;
}

int main(){
  int tc; cin >> tc;
  for (int cs = 1; cs <= tc; cs++){
    cout << "Case #" << cs << ": ";
    solve();
  }


  return 0;
}
