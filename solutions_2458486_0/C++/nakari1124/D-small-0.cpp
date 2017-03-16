#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <cmath>
#include <set>
#include <bitset>

using namespace std;

typedef long long i64;
typedef int int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

const int NUM_KEYS = 40;

typedef bitset<20> state;
vvi orders;
i64 K0, N;
vi T;
vvi K;

void search(const state &status, const vi &keys, vi &order) {
  if(!orders[status.to_ulong()].empty()) {
    order = orders[status.to_ulong()];
    return;
  }

  i64 i, j;
  if(status.count() == N - 1) {
    REP(0, N, i) {
      if(!status[i]) {
	if(keys[T[i]] > 0)
	  order = vi(1, i);
	else
	  order = vi(1, -1);
	break;
      }
    }
  }
  else {
    bool flag = false;
    REP(0, N, i) {
      state temp = status;
      vi ks = keys;
      if(!temp[i]) {
	if(ks[T[i]] > 0) {
	  temp.set(i, 1);
	  ks[T[i]] -= 1;
	  REP(0, sz(K[i]), j) {
	    ks[K[i][j]] += 1;
	  }

	  order.clear();
	  search(temp, ks, order);
	  if(order.empty()) {
	    cout << "err..." << endl;
	  }
	  if(order[0] != -1) {
	    flag = true;
	    order.pb(i);
	    break;
	  }
	}
      }
    }
    if(!flag) {
      order = vi(1, -1);
    }
  }

  orders[status.to_ulong()] = order;
}

int main(int argc, char *argv[]) {

  i64 C;
  cin >> C;
  i64 n;
  i64 i, j;

  orders = vvi(1 << 20);

  REP(0, C, n) {
    cout << "Case #" << n + 1 << ": ";

    cin >> K0 >> N;
    
    vi keys(NUM_KEYS, 0);
    REP(0, K0, i) {
      i64 k;
      cin >> k;
      keys[k-1]++;
    }

    T = vi(N);
    K = vvi(N);
    T.clear();
    K.clear();
    REP(0, N, i) {
      cin >> T[i];
      T[i]--;
      i64 nk;
      cin >> nk;
      REP(0, nk, j) {
	i64 k;
	cin >> k;
	K[i].pb(k-1);
      }
    }

    if(K0 == 0) {
      cout << "IMPOSSIBLE";
    }
    else {
      REP(0, 1<<20, i) {
	orders[i].clear();
      }

      /*
      state st0;
      st0.reset();
      REP(0, N, i) {
	st0.set(i);
      }
      REP(0, N, i) {
	st0.reset(i);
	orders[st0.to_ulong()] = vi(1, i);
	//cout << st0.to_ulong() << endl;
	st0.set(i);
      }
      */
      state st;
      st.reset();

      vi order;
      search(st, keys, order);

      if(order[0] == -1) {
	cout << "IMPOSSIBLE";
      }
      else {
	if(sz(order) != N) {
	  cout << "err..." << sz(order) << endl;
	}
	REP(0, N, i) {
	  if(i != 0)
	    cout << " ";
	  cout << order[N - 1 - i] + 1;
	}
      }

    }

    cout << endl;
  }

  return 0;
}
