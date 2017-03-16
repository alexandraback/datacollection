#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb(x) push_back(x)

int n;
vector<vector<int>> inp;
#define MAX 60

int f[MAX][MAX];

bool isConsistent() {
  memset(f, 0, sizeof(f));
  int b = 0, e = n-1;
  for(int i=0; i < (int)inp.size(); i += 2) {
    int pos;
    if ( (i/2)%2 == 0 ) {
      pos = b++;
    } else {
      pos = e--;
    }
    if (inp[i][0] != 0) {
      for(int j=0; j<n; j++) {
        if (f[pos][j] != 0 && f[pos][j] != inp[i][j]) {
          return false;
        } else {
          f[pos][j] = inp[i][j];
        }
      }
    }
  }
  b = 0; e = n-1;
  for(int i=1; i < (int)inp.size(); i += 2) {
    int pos;
    if ( (i/2)%2 == 0 ) {
      pos = b++;
    } else {
      pos = e--;
    }
    if (inp[i][0] != 0) {
      for(int j=0; j<n; ++j) {
      if (f[j][pos] != 0 && f[j][pos] != inp[i][j]) {
        return false;
      } else {
        f[j][pos] = inp[i][j];
      }
      }
    }
  }

  return true;
}

void solve(int st, int b, int e) {
  if (e < b) return;
  else if(b == e) {
    if (inp.size() % 2 == 1) {
      inp.insert(inp.begin() + st, vector<int>(n, 0));
    }
    return;
  }
  int len = inp.size();

  int mx = 0;
  int mn = numeric_limits<int>::max();
  for(int i=st; i<len; ++i) {
    mx = max(inp[i][e], mx);
    mn = min(inp[i][b], mn);
  }

  int nxt = st;
  int cntmn = 0;
  int cntmx = 0;
  for(int i=st; i<len; ++i) {
    if (inp[i][b] == mn) {
      swap(inp[i], inp[nxt++]);
      cntmn ++;
    }
  }
  for(int i=st; i<len; ++i) {
    if (inp[i][e] == mx) {
      swap(inp[i], inp[nxt++]);
      cntmx ++;
    }
  }

  if (cntmn < 2) {
    inp.insert(inp.begin() + st, vector<int>(n, 0));
    nxt ++;
    len ++;
  } else if(cntmx < 2) {
    inp.insert(inp.begin() + st + 2, vector<int>(n,0));
    nxt ++;
    len ++;
  }

  solve(nxt, b+1, e-1);
}

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    cin >> n;
    inp.clear();
    memset(f, -1, sizeof(f));

    for(int i = 0; i<2*n-1; ++i) {
      vector<int> v;
      for(int j=0; j<n; j++) {
        int aux;
        cin >> aux;
        v.pb(aux);
      }
      inp.pb(v);
    }

    solve(0, 0, n-1);


    printf("Case #%d:", cn);

    for(int k=0; k< (1<<n); ++k) {
      for(int j=0; j<(int)inp.size(); j+=2) {
        if ( (1<<(j>>1)) & k ) {
          swap(inp[j], inp[j+1]);
        }
      }

      if (isConsistent()) {
        int b = 0, e = n-1;
        for(int i=0; i < (int)inp.size(); i += 2) {
          int pos;
          if ( (i/2)%2 == 0 ) {
            pos = b++;
          } else {
            pos = e--;
          }
          if (inp[i][0] == 0) {
            for(int j=0; j<n; j++) {
              printf(" %d", f[pos][j]);
            }
          }
        }
        b = 0; e = n-1;
        for(int i=1; i < (int)inp.size(); i += 2) {
          int pos;
          if ( (i/2)%2 == 0 ) {
            pos = b++;
          } else {
            pos = e--;
          }
          if (inp[i][0] == 0) {
            for(int j=0; j<n; j++) {
              printf(" %d", f[j][pos]);
            }
          }
        }

        printf("\n");
        break;
      }

      for(int j=0; j<(int)inp.size(); j+=2) {
        if ( (1<<(j>>1)) & k ) {
          swap(inp[j], inp[j+1]);
        }
      }
    }


  }
  return 0;
}
