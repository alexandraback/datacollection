#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "B"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

int N;
vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs1 (to);
	}
	order.push_back (v);
}

void dfs2 (int v, int cl) {
	comp[v] = cl;
	for (size_t i=0; i<gt[v].size(); ++i) {
		int to = gt[v][i];
		if (comp[to] == -1)
			dfs2 (to, cl);
	}
}

vi SAT() {
  order.clear();
	used.assign (N, false);
	for (int i=0; i<N; ++i)
		if (!used[i])
			dfs1 (i);

	comp.assign (N, -1);
	for (int i=0, j=0; i<N; ++i) {
		int v = order[N-i-1];
		if (comp[v] == -1)
			dfs2 (v, j++);
	}

  for (int i=0; i<N; ++i) {
		if (comp[i] == comp[i^1]) {
			return vi();
		}
  }
  vi result(N);
	for (int i=0; i<N; ++i) {
		//int ans = comp[i] > comp[i^1] ? i : i^1;
		//printf ("%d ", ans);
    if (comp[i] > comp[i^1]) {
      result[i] = 1;
    } else {
      result[i] = 0;
    }
	}
  return result;
}

vi Restore(int n, const vvi& lists) {
  vb used(2 * n - 1, false);
  vvi field(n, vi(n));
  vector<pii> rowcols(n);
  vi num(2 * n - 1);
  int lost_index;
  for (int i = 0; i < n; ++i) {
    int Min = 2501;
    int min_index = -1;
    for (int j = 0; j < lists.size(); ++j) {
      if (!used[j] && lists[j][i] < Min) {
        Min = lists[j][i];
        min_index = j;
      }
    }
    field[i][i] = Min;
    used[min_index] = true;
    num[min_index] = i;
    bool found = false;
    for (int j = 0; j < lists.size(); ++j) {
      if (!used[j] && lists[j][i] == Min) {
        used[j] = true;
        rowcols[i] = MP(min_index, j);
        num[j] = i;
        found = true;
        break;
      }
    }
    if (!found) {
      lost_index = i;
      rowcols[i] = MP(min_index, -1);
    }
  }
  vi all;
  for (int i = 0; i < rowcols.size(); ++i) {
    if (rowcols[i].first != -1) {
      all.push_back(rowcols[i].first);
    }
    if (rowcols[i].second != -1) {
      all.push_back(rowcols[i].second);
    }
  }
  vi index(2 * n - 1);
  for (int i = 0; i < all.size(); ++i) {
    index[all[i]] = i;
  }
  N = 2 * (2 * n - 1);
  g.assign(N, vi());
  for (int i = 0; i < n; ++i) {
    if (rowcols[i].first != -1 && rowcols[i].second != -1) {
      g[2 * index[rowcols[i].first]].push_back(2 * index[rowcols[i].second] + 1);
      g[2 * index[rowcols[i].first] + 1].push_back(2 * index[rowcols[i].second]);
      g[2 * index[rowcols[i].second]].push_back(2 * index[rowcols[i].first] + 1);
      g[2 * index[rowcols[i].second] + 1].push_back(2 * index[rowcols[i].first]);
    }
  }
  for (int i = 0; i < n; ++i) {
    vi is;
    if (rowcols[i].first != -1) {
      is.push_back(rowcols[i].first);
    }
    if (rowcols[i].second != -1) {
      is.push_back(rowcols[i].second);
    }
    for (int j = i + 1; j < n; ++j) {
      vi js;
      if (rowcols[j].first != -1) {
        js.push_back(rowcols[j].first);
      }
      if (rowcols[j].second != -1) {
        js.push_back(rowcols[j].second);
      }
      for (int ii = 0; ii < is.size(); ++ii) {
        for (int jj = 0; jj < js.size(); ++jj) {
          if (lists[is[ii]][j] != lists[js[jj]][i]) {
            g[2 * index[is[ii]]].push_back(2 * index[js[jj]]);
            g[2 * index[is[ii]] + 1].push_back(2 * index[js[jj]] + 1);
            g[2 * index[js[jj]]].push_back(2 * index[is[ii]]);
            g[2 * index[js[jj]] + 1].push_back(2 * index[is[ii]] + 1);
          }
        }
      }
    }
  }
  gt.assign(N, vi());
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      gt[g[i][j]].push_back(i);
    }
  }    
  vi values = SAT();
  if (values.empty()) {
    cerr << "No solution!" << endl;
    abort();
  }
  bool is_lost_row;
  for (int i = 0; i < n; ++i) {
    if (rowcols[i].first == -1 || rowcols[i].second == -1) {
      if (rowcols[i].first == -1) {
        is_lost_row = !values[2 * index[rowcols[i].second]];
      } else {
        is_lost_row = !values[2 * index[rowcols[i].first]];
      }
      break;
    }
  }
  vi result(n, -1);
  if (is_lost_row) {
    for (int i = 0; i < 2 * n - 1; ++i) {
      if (!values[2 * i]) {
        int list_index = all[i];
        result[num[list_index]] = lists[list_index][lost_index];
      }
    }
  } else {
    for (int i = 0; i < 2 * n - 1; ++i) {
      if (values[2 * i]) {
        int list_index = all[i];
        result[num[list_index]] = lists[list_index][lost_index];
      }
    }
  }
  return result;
}

vi RestoreSlow(int n, const vvi& lists) {
  vi perm;
  for (int i = -1; i < int(lists.size()); ++i) {
    perm.push_back(i);
  }
  do {
    vvi field(n, vi(n, -1));
    bool good = true;
    for (int i = 0; i < perm.size(); ++i) {
      int index = perm[i];
      if (index == -1) {
        continue;
      }
      if (i < n) {
        for (int j = 0; j < n; ++j) {
          if (field[i][j] != -1 && lists[index][j] != field[i][j]) {
            good = false;
            break;
          }
          if (field[i][j] == -1) {
            field[i][j] = lists[index][j];
          }
        }
        if (!good) {
          break;
        }
      } else {
        for (int j = 0; j < n; ++j) {
          if (field[j][i - n] != -1 && lists[index][j] != field[j][i - n]) {
            good = false;
            break;
          }
          if (field[j][i - n] == -1) {
            field[j][i - n] = lists[index][j];
          }
        }
        if (!good) {
          break;
        }
      }
    }
    if (good) {
      vi result;
      for (int i = 0; i < perm.size(); ++i) {
        if (perm[i] == -1) {
          if (i < n) {
            for (int j = 0; j < n; ++j) {
              result.push_back(field[i][j]);
            }
          } else {
            for (int j = 0; j < n; ++j) {
              result.push_back(field[j][i - n]);
            }
          }
          return result;
        }
      }
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return vi();
}

int main() {
  /*while (true) {
    int n = rand() % 5 + 1;
    vvi field(n, vi(n));
    bool good_test = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int min_value = 0;
        if (i > 0) {
          min_value = max(min_value, field[i - 1][j]);
        }
        if (j > 0) {
          min_value = max(min_value, field[i][j - 1]);
        }
        ++min_value;
        if (min_value >= 2500) {
          good_test = false;
          break;
        }
        field[i][j] = min_value + rand() % (2500 - min_value + 1);
      }
    }
    if (!good_test) {
      cerr << "Bad test" << endl;
      continue;
    }
    cerr << n << endl << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cerr << field[i][j] << ' ';
      }
      cerr << endl;
    }
    cerr << endl;
    vvi lists;
    int lost = rand() % (2 * n);
    vi lost_list;
    for (int i = 0; i < 2 * n; ++i) {
      if (i == lost) {
        for (int j = 0; j < n; ++j) {
          if (i < n) {
            lost_list.push_back(field[i][j]);
          } else {
            lost_list.push_back(field[j][i - n]);
          }
        }
        continue;
      }
      vi list;
      for (int j = 0; j < n; ++j) {
        if (i < n) {
          list.push_back(field[i][j]);
        } else {
          list.push_back(field[j][i - n]);
        }
      }
      lists.push_back(list);
    }
    for (int i = 0; i < lists.size(); ++i) {
      for (int j = 0; j < lists[i].size(); ++j) {
        cerr << lists[i][j] << ' ';
      }
      cerr << endl;
    }
    cerr << endl;
    for (int i = 0; i < lost_list.size(); ++i) {
      cerr << lost_list[i] << ' ';
    }
    cerr << endl;
    vi res2 = RestoreSlow(n, lists);
    if (res2 != lost_list) {
      cerr << "Ambiguous answer: slow solution differs from correct answer" << endl;
      for (int i = 0; i < n; ++i) {
        cerr << lost_list[i] << ' ';
      }
      cerr << endl;
      for (int i = 0; i < n; ++i) {
        cerr << res2[i] << ' ';
      }
      cerr << endl;
      continue;
    }
    vi res1 = Restore(n, lists);
    if (res1 != res2) {
      cerr << "Wrong answer!" << endl;
      for (int i = 0; i < n; ++i) {
        cerr << res1[i] << ' ';
      }
      cerr << endl;
      for (int i = 0; i < n; ++i) {
        cerr << res2[i] << ' ';
      }
      cerr << endl;
      break;
    } else {
      cerr << "OK" << endl;
      for (int i = 0; i < n; ++i) {
        cerr << res1[i] << ' ';
      }
      cerr << endl;
    }
  }*/
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n;
    cin >> n;
    vvi lists(2 * n - 1, vi(n));
    for (int i = 0; i < 2 * n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &lists[i][j]);
      }
    }
    vi result = Restore(n, lists);
    cout << "Case #" << (test_index + 1) << ":";
    cerr << "Case #" << (test_index + 1) << ":";
    for (int i = 0; i < n; ++i) {
      cout << ' ' << result[i];
      cerr << ' ' << result[i];
    }
    cout << endl;
    cerr << endl;
  }
  return 0;
}
