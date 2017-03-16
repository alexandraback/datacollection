#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

template<typename T> inline int sz(const T& x) { return (int) x.size(); }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }

typedef long long ll;

const double PI = 2 * acos(0);

// <---------------- actual solution begins here ---------------->

// HEAD-HEAD1-HEAD2-...-HEADM
//        |     |    :    |
// R_C  R1_C1-R1_C2-...-R1_CM
//  =     :     :    :    :
//  1   RN_C1-RN_C2-...-RN_CM

#define FOR(p, init, dir) for(pList p = init; p; p = p->dir)
#define IF(p, l, r, q) if(p->l) p->l->r = q

struct List {
  List *u, *d, *l, *r, *head, *stack;
  int number;
  List() : number(0) { u = d = l = r = head = stack = NULL; }
};

typedef List* pList;

inline void remove(pList p, pList& backup) {
  IF(p, l, r, p->r); IF(p, u, d, p->d);
  IF(p, r, l, p->l); IF(p, d, u, p->u);
  p->head->number--;
  p->stack = backup; backup = p;
}

inline void restore(pList& p) {
  for (; p; p = p->stack) {
    IF(p, l, r, p); IF(p, u, d, p);
    IF(p, r, l, p); IF(p, d, u, p);
    p->head->number++;
  }
}

inline void remove_common(pList p, pList& backup) {
  remove(p, backup);
  FOR(l, p->l, l) remove(l, backup);
  FOR(r, p->r, r) remove(r, backup);
}

inline void remove_head(pList h, pList& backup) {
  h = h->head; remove(h, backup);
  FOR(p, h->d, d) remove_common(p, backup);
}

inline void remove_heads(pList p, pList& backup) {
  FOR(l, p->l, l) remove_head(l, backup);
  FOR(r, p->r, r) remove_head(r, backup);
}

vector<int> answer;

inline int exact_cover(pList head) {
  if (!head->r) return 1;
  pList cur = head->r;
  FOR(p, cur, r) if (p->number < cur->number) cur = p;
  if (cur->number == 0) return 0;
  pList col = NULL, backup = NULL;
  remove_head(cur->d, col);
  FOR(p, cur->d, d) {
    remove_heads(p, backup);
    if (exact_cover(head)) {
      answer.pb(p->number); restore(backup); restore(col);
      return 1;
    } restore(backup);
  } restore(col);
  return 0;
}

template<int NUM_BIT>
pair<bool, vector<int>> solve(const vector<bitset<NUM_BIT>>& have, const bitset<NUM_BIT>& need) {

  pList HEAD = new List();
  HEAD->number = -1;
  pList LAST_HEAD = HEAD;
  vector<pList> LAST_COL(NUM_BIT, NULL);
  vector<pList> HEADS(NUM_BIT, NULL);
  for (int i = 0; i < NUM_BIT; ++i) {
    if (need[i]) {
      pList LAST = new List();
      LAST->head = LAST;
      LAST->number = 0;
      LAST_HEAD->r = LAST;
      LAST->l = LAST_HEAD;
      LAST_HEAD = LAST;
      HEADS[i] = LAST;
      LAST_COL[i] = LAST;
    }
  }
  forn (i, sz(have)) {
    if ((have[i] & need) == have[i]) {
      pList CURR = NULL;
      forn (j, NUM_BIT) {
        if (have[i][j]) {
          pList LAST = new List();
          HEADS[j]->number++;
          LAST->head = HEADS[j];
          LAST->number = i;
          LAST->l = CURR;
          if (CURR) CURR->r = LAST;
          CURR = LAST;
          LAST->u = LAST_COL[j];
          LAST_COL[j]->d = LAST;
          LAST_COL[j] = LAST;
        }
      }
    }
  }
  answer.clear();
  bool ok = exact_cover(HEAD);
  while (HEAD != NULL) {
    pList CURR = HEAD;
    HEAD = HEAD->r;
    while (CURR != NULL) {
        pList NEXT = CURR->d;
        delete CURR;
        CURR = NEXT;
    }
  }
  return make_pair(ok, answer);
}

// 

const int N = 7;

long long mask(const vector<vector<int>>& field) {
    int min_i = 1000;
    int min_j = 1000;
    forn (i, sz(field)) {
        forn (j, sz(field[i])) {
            if (field[i][j]) {
                mn(min_i, i);
                mn(min_j, j);
            }
        }
    }
    long long mask = 0;
    forn (i, sz(field)) {
        forn (j, sz(field[i])) {
            if (field[i][j]) {
                int index = (i - min_i) * N + (j - min_j);
                mask |= 1LL << index;
            }
        }
    }
    return mask;
}

vector<vector<int>> field(const long long& mask) {
    vector<vector<int>> field(N, vector<int>(N, 0));
    forn (i, N) {
        forn (j, N) {
            int index = i * N + j;
            if ((mask >> index) & 1) {
                field[i][j] = 1;
            }
        }
    }
    return field;
}

vector<vector<int>> rotate(const vector<vector<int>>& field) {
    int n = sz(field);
    int m = sz(field[0]);
    vector<vector<int>> rotate(m, vector<int>(n));
    forn (i, n) {
        forn (j, m) {
            rotate[j][n - 1 - i] = field[i][j];
        }
    }
    return rotate;
}

vector<vector<int>> mirror(const vector<vector<int>>& field) {
    int n = sz(field);
    int m = sz(field[0]);
    vector<vector<int>> mirror(n, vector<int>(m));
    forn (i, n) {
        forn (j, m) {
            mirror[i][m - 1 - j] = field[i][j];
        }
    }
    return mirror;
}

long long min_shift(vector<vector<int>> field) {
    long long x = 1e18;
    forn (i, 2) {
        forn (j, 4) {
            mn(x, mask(field));
            field = rotate(field);
        }
        field = mirror(field);
    }
    return x;
}

set<long long> figures;
// vector<long long> order;
// set<long long> cache;

void print(const vector<vector<int>>& f) {
    forn (i, sz(f)) {
        forn (j, sz(f[i])) {
            cout << (f[i][j] ? '#' : '_');
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

void gen(int d, int left, int prevL, int prevR, int dim, vector<vector<int>>& f) {
    if (left == 0) {
        figures.insert(min_shift(f));
        return;
    }
    if (d == dim) {
        return;
    }
    for (int r = 0; r < dim; ++r) {
        for (int l = 0; l <= r; ++l) {
            if (max(prevL, l) <= min(prevR, r) && left >= (r - l + 1)) {
                fill(f[d].begin() + l, f[d].begin() + r + 1, 1);
                gen(d + 1, left - (r - l + 1), l, r, dim, f);                
                fill(f[d].begin() + l, f[d].begin() + r + 1, 0);
            }            
        }
    }
}

vector<vector<int>> norm(const vector<vector<int>>& f) {
    return field(mask(f));
}

typedef bitset<401> BIT;

vector<long long> masks;
vector<vector<vector<vector<int>>>> fields;
vector<vector<BIT>> bits;

pair<bool, BIT> place(const vector<vector<int>>& field, int r, int c, int place_i, int place_j) {
    BIT result;
    forn (i, N) {
        forn (j, N) {
            if (field[i][j]) {
                int field_i = i + place_i;
                int field_j = j + place_j;
                if (field_i < 0 || field_j < 0 || field_i >= r || field_j >= c) {
                    return {false, result};
                }
                result[field_i * 20 + field_j] = true;
            }
        }
    }
    return {true, result};
}


vector<set<pair<int, int>>> all_possible(10);

bool ans[10][21][21];

bool solve(int x, int r, int c, bool use_calc) {
    if (r * c % x != 0) {
        return true;
    }
    if (x >= 7) {
        return true;
    }
    if (x > max(r, c)) {
        return true;
    }
    if ((x - 1) / 2 + 1 > min(r, c)) {
        return true;
    }

    for (int dr = 1; dr <= r; ++dr) if (r % dr == 0)
    for (int dc = 1; dc <= c; ++dc) if (c % dc == 0)
    if (all_possible[x].count({dr,dc})) {
        return false;
    }

    if (use_calc) {
        return ans[x][r][c];
    }

    figures.clear();
    vector<vector<int>> gen_f(N, vector<int>(N, 0));
    gen(0, x, 0, x - 1, x, gen_f);

    masks.clear();
    fields.clear();
    bits.clear();
    vector<BIT> allbits;

    BIT need;
    forn (i, r) {
        forn (j, c) {
            need[i * 20 + j] = true;
        }
    }
    need[400] = true;

    for (long long mask : figures) {
        masks.pb(mask);
        fields.pb(vector<vector<vector<int>>>());
        bits.pb(vector<BIT>());
        vector<vector<int>> f = field(mask); 
        forn (i, 2) {
            forn (j, 4) {
                f = norm(f);
                fields.back().pb(f);
                f = rotate(f);
            }
            f = mirror(f);
        }
        for (const vector<vector<int>>& field : fields.back()) {
            forn (i, r) {
                forn (j, c) {
                    pair<bool, BIT> bit = place(field, r, c, i, j);
                    if (bit.first) {
                        // if ((bit.second & need) != bit.second) {
                            // cout << "error" << endl;
                        // }
                        bits.back().pb(bit.second);
                        allbits.pb(bit.second);
                    }
                }
            }
        }
    }


    unordered_set<BIT> solved;
    forn (i, sz(bits)) {
        bool already_solved = false;
        for (const BIT& bit : bits[i]) {
            if (solved.count(bit)) {
                already_solved = true;
                break;
            }
        }
        if (already_solved) {
            continue;
        }
        unordered_set<BIT> sorted;
        forn (j, sz(bits)) {
            for (const BIT& bit : bits[j]) {
                sorted.insert(bit);
                if (i == j) {
                    BIT current = bit;
                    current[400] = true;
                    sorted.insert(current);
                }
            }
        }
        vector<BIT> have;
        copy(all(sorted), back_inserter(have));

        auto solution = solve<401>(have, need);
        // debug(sz(have));
        if (!solution.first) {
            return true;
        }
        for (int index : solution.second) {
            have[index][400] = false;
            solved.insert(have[index]);
        }

        // if (!can(allbits, bits[i], full)) {
            // print(field(mask));
            // return true;
        // }
        // random_shuffle(all(order));
    }
    // debug(sz(figures));

    all_possible[x].insert({r,c});
    all_possible[x].insert({c,r});
    return false;
}

// 2 4 1

set<pair<int, int>> no_exist;


int main() {
    for (int x = 1; x <= 6; ++x) {
        for (int r = 1; r <= 20; ++r) {
            for (int c = 1; c <= r; ++c) {
                // cout << x << ' ' << r << ' ' << c << ' ' << endl;
                ans[x][r][c] = ans[x][c][r] = solve(x, r, c, false);
                // cout << ans[x][r][c] << endl;
            }
        }
    }

    // freopen("in.txt", "r", stdin);
    freopen("D-large.in.txt", "r", stdin);
    freopen("D.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x, r, c;
        cin >> x >> r >> c;
        cout << "Case #" << i + 1 << ": ";
        cout << (solve(x, r, c, true) ? "RICHARD" : "GABRIEL") << endl;
    }
    return 0;
}