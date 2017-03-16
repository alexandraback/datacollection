#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define FOR(i, a, b) for(int i(a);i<=(int)(b);i++)
#define REP(i,n) FOR(i,0,n-1)


void Prepare() {

}

void Work(int casenum) {
    int n;
    cin >> n;
    map<int, int> cnt;
    REP(i, n + n - 1) REP(j, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> ans;
    for (map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++)
    if (itr->second % 2 == 1) {
        ans.push_back(itr->first);
    }
    cout << "Case #" << casenum << ":";
    REP(i, ans.size()) cout << ' ' << ans[i];
    cout << endl;
}

int main() {
  Prepare();
  int n;
  cin >> n;
  FOR(i, 1, n) Work(i);

}
