#include <iostream>
#include <vector>
#include <algorithm>

#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define trace(x) { cerr << #x << " = " << x << endl; }

using namespace std;

typedef long long ll;

bool vow(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int solve(string S, int n) {
  
  vector<int> start;
  vector<int> end;

  int L = S.size();

  int st = -1;

  rep(i, L) {
    if(!vow(S[i])) {
      if(st == -1) {
        st = i;
      }
    }
    else {
      if(st != -1) {
        start.push_back(st);
        end.push_back(i - 1);
        st = -1;
      }
    }
  }

  if(st != -1) {
    start.push_back(st);
    end.push_back(L - 1);
  }

  int RN = end.size();

  #if 0
  cerr << "RN = " << RN << endl;
  rep(i, RN) cerr << start[i] << ",";
  cerr << endl;
  rep(i, RN) cerr << end[i] << ",";
  cerr << endl;
  #endif

  int ans = 0;

  int ptr = 0;

  rep(i, L) {
    while(ptr != RN && end[ptr] - max(start[ptr], i) + 1 < n) ptr++;
    if(ptr == RN) break;

    ans += L - (max(i, start[ptr])) - (n-1);
  }
  
  return ans;
  
}

void run() {

  int T;
  cin >> T;

  rep(i, T) {
    string L;
    int n;
    cin >> L >> n;

    cout << "Case #" << (i+1) << ": " << solve(L, n) << endl;
  }

}

#undef int
int main() {
  run();
  return 0;
}
