#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<pair<string, string>> lists;
map<string, int> cfirst, csecond;
int count() {
    int ans = 0;
    for (const auto& entry : lists) {
        if (cfirst[entry.first] > 1 && csecond[entry.second] > 1) {
            ans++;
        }
        cfirst[entry.first]--;
        csecond[entry.second]--;
    }
    return ans;
}

void solve() {
    cfirst.clear();
    csecond.clear();
    lists.clear();
    int N;
    cin >> N;
    string f, s;
    for (int i = 0 ; i < N ; i++) {
        cin >> f >> s;
        lists.push_back({f, s});
        cfirst[f]++;
        csecond[s]++;
    }
    printf("%d", count());
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}
