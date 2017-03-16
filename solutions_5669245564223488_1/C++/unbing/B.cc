#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl
#define MOD 1000000007LL

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef long double ld;

void input(vector<string>& arr) {
  int N, i;
  cin >> N;
  fr (i, N) {
    string s;
    cin >> s;
    arr.pb(s);
  }
}

bool valid(vector<string>& arr) {
  int i, j, k;
  vi imp(26, 0);
  fr (i, SZ(arr)) {
    string tmp;
    fr (j, SZ(arr[i])) {
      if (SZ(tmp) > 0) {
        if (tmp[SZ(tmp) - 1] == arr[i][j]) continue;
        if (SZ(tmp) == 2) {
          imp[tmp[1] - 'a']++;
          tmp[1] = arr[i][j];
          if (tmp[1] == tmp[0]) return false;
          continue;
        }
      }
      tmp.pb(arr[i][j]);
    }
    if (SZ(tmp) == 1) tmp.pb(tmp[0]);
    arr[i] = tmp;
  }

  fr (i, 26) if (imp[i] > 1) return false;
  fr (i, SZ(arr)) if(imp[arr[i][0] - 'a'] > 0 || imp[arr[i][1] - 'a'] > 0) return false;

  vi front(26, 0);
  vi back(26, 0);
  fr (i, SZ(arr)) if(arr[i][0] != arr[i][1]) {
    front[arr[i][0] - 'a']++;
    back[arr[i][1] - 'a']++;
  }

  fr (i, SZ(front)) if (front[i] > 1 || back[i] > 1) return false;

  return true;
}

bool dfs(vector<string>& arr, vi& done, vector<string>& head, vector<string>& tail) {
  int i, j;
  while (1) {
    int idx = -1;
    fr (i, SZ(arr)) if (done[i] == 0 && arr[i][0] != arr[i][1]) {
      int h = SZ(head) - 1;
      int t = SZ(tail) - 1;
      if (head[h][0] == arr[i][1] && tail[t][1] == arr[i][0]) return false;
      if (head[h][0] == arr[i][1]) {
        head.pb(arr[i]);
        idx = i;
        break;
      }
      if (tail[t][1] == arr[i][0]) {
        tail.pb(arr[i]);
        idx = i;
        break;
      }
    }
    if (idx == -1) break;
    done[idx] = 1;
  }

  return true;
}

void proc(vector<string>& arr, ll& res, vi& done, int& chunks) {
  int i, j, k;
  fr (i, SZ(arr)) if (done[i] == 0 && arr[i][0] != arr[i][1]) {
    vector<string> head, tail;
    head.pb(arr[i]);
    tail.pb(arr[i]);
    done[i] = 1;
    if (!dfs(arr, done, head, tail)) {
      res = 0;
      break;
    }
    
    reverse(head.begin(), head.end());
    for (j = 1; j < SZ(tail); ++j) head.pb(tail[j]);

    vector<ll> cnt = vector<ll>(SZ(head) + 1, 0);
    fr (j, SZ(arr)) if (done[j] == 0 && arr[j][0] == arr[j][1]) {
      bool found = false;
      fr (k, SZ(head)) if (head[k][0] == arr[j][0]) {
        found = true;
        cnt[k]++;
        res = (res * cnt[k]) % MOD;
        break;
      }
      
      if (!found && head[k - 1][1] == arr[j][0]) {
        found = true;
        cnt[k]++;
        res = (res * cnt[k]) % MOD;
      }
      if (found) done[j] = 1;
    }
    chunks++;
    res = (res * chunks) % MOD;
  }
}

int main() {
  int tc, cn = 0;
  cin >> tc;
  while (cn++ < tc) {
    vector<string> arr;
    input(arr);

    ll res = 1;
    if (!valid(arr)) {
      res = 0;
    }

    vi done = vi(SZ(arr), 0);
    int chunks = 0;
    if (res != 0) proc(arr, res, done, chunks);

    int i, j;
    if (res != 0) fr (i, SZ(arr)) if (done[i] == 0) {
      done[i] = 1;
      int cnt = 1;
      fr (j, SZ(arr)) if (done[j] == 0 && arr[i][0] == arr[j][0]) {
        done[j] = 1;
        cnt++;
        res = (res * cnt) % MOD;
      }
      chunks++;
      res = (res * chunks) % MOD;
    }

    cout << "Case #" << cn << ": " << res << endl;
  }
  return 0;
}
