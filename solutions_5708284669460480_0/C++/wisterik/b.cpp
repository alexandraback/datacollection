#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int K, L, S;
string keyboard;
string target;

int mp[26];
int term;

int maximum() {
  int n = target.size();
  rep(i, n) {
    if (mp[target[i] - 'A'] == 0) return 0;
  }
  term = n;
  for(int i = 1; i < n; i++) {
    bool same = true;
    for(int j = 0; j < n - i; j++) {
      if(target[i + j] != target[j]) {
	same = false;
      }
    }
    if(same) {
      term = i;
      cerr << "HOGE" << endl;
      break;
    }
  }
  cerr << "term = " << term << endl;
  int ans = 0;
  for(int i = 0; i < S; i += term) {
    if(i + target.size() - 1 < S) ans++;
  }
  return ans;
}

double memo[105][105];

double f(int count, int index) {
  //cerr << count << " " << index << endl;
  if(count == 0) return 0;
  double& d = memo[count][index];
  if(d >= -0.5) return d;
  double ans = 0;
  for (char c = 'A'; c <= 'Z'; c++) {
    int nextindex;
    if (c == target[index]) {
      nextindex = index + 1;
    }
    else if (c == target[0]) {
      nextindex = 1;
    }
    else {
      nextindex = 0;
    }

    double tmp = 0;
    
    if(nextindex >= L) {
      tmp += 1;
      nextindex = L - term;
    }
    tmp += f(count - 1, nextindex);
    ans += tmp *  mp[c - 'A'] / K;
  }
  return d = ans;
}

double solve() {

  rep(i, 26) mp[i] = 0;
  rep(i, (int)keyboard.size()) {
    mp[keyboard[i] - 'A']++;
  }

  int M = maximum();
  cerr << "maximum() = " << M << endl;
  rep(i, 105) rep(j, 105) memo[i][j] = -1;
  double expect = f(S, 0);
  cerr << "expect = " << expect << endl;

  return M - expect;

}

int main() {

  int T;
  cin >> T;

  cout << setprecision(8);

  rep(i, T) {
    cin >> K >> L >> S;
    cin >> keyboard >> target;
    cerr << endl;
    cout << "Case #" << (i+1) << ": " << solve() << endl;
  }

  return 0;
}
