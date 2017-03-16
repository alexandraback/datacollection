#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> fs) {
  int ret = 0;
  for(int c = 1; c <= fs.size(); c++) {
    vector<bool> cs(fs.size());
    fill(cs.end() - c, cs.end(), true);
    do {
      vector<int> ps;
      for(int i = 0; i < fs.size(); i++)
        if(cs[i]) ps.push_back(i + 1);
      do {
        int count = 0;
        int all = true;
        // for(auto _i = ps.begin(); _i != ps.end(); _i++) {
        //   cout << *_i << " ";
        // }
        // cout << endl;
        for(int i = 0; i < ps.size(); i++) {
          // int f    = fs[ps[i]                               - 1];
          int f    = fs[ps[i] - 1];
          int prev = ps[(i - 1 + ps.size()) % ps.size()];
          int next = ps[(i + 1            ) % ps.size()];
          // cout << "f = " << f << "; prev = " << prev << "; next = " << next << endl;
          all = all && (f == prev || f == next);
        }
        if(all && ps.size() > ret) ret = ps.size();
        // cout << "ret = " << ret << endl;
      } while(next_permutation(ps.begin(), ps.end()));
    } while(next_permutation(cs.begin(), cs.end()));
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    vector<int> fs(n);
    for(int i = 0; i < n; i++) cin >> fs[i];
    cout << "Case #" << t << ": " << solve(fs) << endl;
  }
}
