//bcw0x1bd2 {{{
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define SZ(x) ((int)((x).size()))
#define ALL(x) begin(x),end(x)
#define REP(i,x) for (int i=0; i<(x); i++)
#define REP1(i,a,b) for (int i=(a); i<=(b); i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

#ifdef DARKHH
#define FILEIO(name)
#else
#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#endif

#ifdef DARKHH
template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
    s << "[ ";
    for ( auto it=b; it!=e; it++ ) s << *it << " ";
    s << "]";
    return s;
}
template<typename A, typename B>
ostream& operator << (ostream &s, const pair<A,B> &p) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator << (ostream &s, const vector<T> &c) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator << (ostream &s, const array<T,N> &c) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator << (ostream &s, const set<T> &c) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator << (ostream &s, const map<A,B> &c) { return _out(s,ALL(c)); }
#endif
// }}}
// Let's Fight! ~OAO~~

int N,M,arr[55][55],brr[55][55],used[205],u2[205];
int u3[205];
vector<int> vec[205];

bool check(int k) {
  //cout << "CHECK " << k << endl;
  //REP(i,N) {
    //REP(j,N) cout << brr[i][j] << " ";
    //cout << endl;
  //}
  vector<int> v2[105];
  int pos = 0;
  REP(i,N) {
    REP(j,N) {
      v2[pos].PB(brr[i][j]);
    }
    pos++;
    REP(j,N) {
      v2[pos].PB(brr[j][i]);
    }
    pos++;
  }
  assert(pos == M+1);
  sort(v2,v2+M+1);
  //REP(i,M+1) cout << v2[i] << endl;
  //REP(i,N) if (used[i]) cout << i << " ";
  //cout << endl;

  REP(i,M) u3[i] = 0;
  pos = 0;
  REP(i,M+1) {
    int kk = -1;
    REP(x,M) {
      if (u3[x]) continue;
      int fail = 0;
      REP(j,N) {
        if (used[j] and v2[i][j] != vec[x][j]) {
          fail = 1;
          break;
        }
      }
      if (!fail) {
        kk = x;
        break;
      }
    }
    if (kk != -1) {
      u3[kk] = 1;
    }

  }
  REP(i,M) {
    if (!u3[i]) {
      //cout << "FAIL @ " << vec[i] << endl;
      return false;
    }
  }

  memcpy(arr,brr,sizeof(arr));
  return true;
}
void input() {
  cin >> N;
  M = 2*N-1;
  REP(i,M) {
    vec[i].resize(N);
    REP(j,N) cin >> vec[i][j];
  }
}
void solve() {
  memset(brr,0,sizeof(brr));
  REP(i,105) u2[i] = used[i] = 0;
  sort(vec,vec+M);
  int rev = 0;
  if (vec[0][0] != vec[1][0]) {
    rev = 1;
    REP(i,M) {
      REP(j,N) vec[i][j] = -vec[i][j];
      reverse(ALL(vec[i]));
    }
    sort(vec,vec+M);
  }
  assert(vec[0][0] == vec[1][0]);
  REP(i,N) {
    arr[0][i] = vec[0][i];
    arr[i][0] = vec[1][i];
  }
  REP(i,N) used[i] = 0;
  used[0] = 1;
  vector<int> spj;
  int spk = -1;
  int k = 1;

  //REP(i,M) cout << vec[i] << endl;
  REP(i,M) u2[i] = 0;
  u2[0] = u2[1] = 1;

  while (k < N) {
    vector<int> a,b;
    REP(i,M) {
      if (u2[i]) continue;
      int ok = 1;
      REP(j,N) {
        if (used[j] and vec[i][j] != arr[k][j]) ok = 0;
        //if (j == k and vec[i][0] != x) ok = 0;;
      }
      if (ok) a.PB(i);
      ok = 1;
      REP(j,N) {
        if (used[j] and vec[i][j] != arr[j][k]) ok = 0;
        //if (j == k and vec[i][0] != y) ok = 0;
      }
      if (ok) b.PB(i);
    }

    if (a.empty() or b.empty()) {
      assert(spk == -1);
      spk = k;
    } else {
      //cout << a << " " << b << endl;
      //REP(i,N) {
        //REP(j,N) cout << arr[i][j] << " ";
        //cout << endl;
      //}
      int ok = 0;
      used[k] = 1;
      for (auto i:a) for (auto j:b) {
        if (ok) continue;
        if (i == j) continue;
        u2[i] = u2[j] = 1;
        //cout << pii(i,j) << endl;
        //cout << vec[i] << endl;
        //cout << vec[j] << endl;
        memcpy(brr,arr,sizeof(arr));
        REP(l,N) brr[k][l] = vec[i][l];
        REP(l,N) brr[l][k] = vec[j][l];
        if (check(k)) {
          ok = 1;
        }
        if (!ok) u2[i] = u2[j] = 0;
      }
      if (!ok) {
        assert(spk == -1);
        used[k] = 0;
        spk = k;
      }
    }
    k++;
  }

  //REP(i,N) {
    //REP(j,N) cout << arr[i][j] << " ";
    //cout << endl;
  //}
  assert(spk != -1);
  REP(i,M) {
    if (!u2[i]) {
      spj = vec[i];
      break;
    }
  }
  used[spk] = 1;
  int ok = 0;
  if (!ok) {
    memcpy(brr,arr,sizeof(arr));
    REP(j,N) brr[spk][j] = spj[j];
    if (check(spk)) ok = 1;
  }
  if (!ok) {
    memcpy(brr,arr,sizeof(arr));
    REP(j,N) brr[j][spk] = spj[j];
    if (check(spk)) ok = 1;
  }
  assert(ok);
  //REP(i,N) {
  //REP(j,N) cout << arr[i][j] << " ";
  //cout << endl;
  //}

  if (rev) {
    memcpy(brr,arr,sizeof(arr));
    REP(i,N) {
      REP(j,N) arr[i][j] = -brr[N-i-1][N-j-1];
    }
    REP(i,M) {
      REP(j,N) vec[i][j] = -vec[i][j];
      reverse(ALL(vec[i]));
    }
  }

  REP(i,105) used[i] = 0;
  REP(i,N) {
    vector<int> v2;
    REP(j,N) v2.PB(arr[i][j]);

    //cout << "? " << v2 << endl;
    ok = 1;
    REP(j,M) {
      if (used[j]) continue;
      if (v2 == vec[j]) {
        ok = 0;
        used[j] = 1;
        break;
      }
    }
    if (ok) {
      REP(j,N) cout << v2[j] << " \n"[j==N-1];
      return;
    }

    v2.clear();
    REP(j,N) v2.PB(arr[j][i]);
    //cout << "? " << v2 << endl;
    ok = 1;
    REP(j,M) {
      if (used[j]) continue;
      if (v2 == vec[j]) {
        ok = 0;
        used[j] = 1;
        break;
      }
    }
    if (ok) {
      REP(j,N) cout << v2[j] << " \n"[j==N-1];
      return;
    }
  }
  assert(false);
}
int main() {
  IOS;
  int nT;
  cin >> nT;
  REP1(cas,1,nT) {
    input();
    cout << "Case #" << cas << ": ";
    solve();
  }

  return 0;
}

