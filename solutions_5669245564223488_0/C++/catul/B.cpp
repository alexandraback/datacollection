#define DBG 0

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
#include <cstring>

typedef vector<int>          vint;
typedef vector<unsigned int> vuint;
typedef vector<string>       vstr;
typedef long long            ll;
typedef unsigned long long   ull;
typedef pair<int, int>       pii;
typedef pair<char, int>    PSI;

#define FORN(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define FE  (i,x) for (typeof((x).begin()) (i) = (x).begin(); (i) != (x).end(); (i)++)

#define pb push_back
#define mp make_pair
#define X  first
#define Y  second

#if DBG
#define db(x) { cout << __FUNCTION__ << "(" << __LINE__ << "): " << #x << " = " << x << endl; }
#define dbgp(...) fprintf(stderr, __VA_ARGS__);
#define dmp(table,n) { for (int __i = 0; __i < n; __i++) cerr << (__i==0 ? "" : ",") << table[__i]; cout << endl;}
ostream& operator<<(ostream& os, const vector<int> keys) {
  vector<int>::size_type sz = keys.size();
  for (unsigned int i = 0; i < sz; i++)
    os << keys[i] << " ";
  os << endl;
  return os;
}
ostream& operator<<(ostream& os, const vstr keys) {
  vector<int>::size_type sz = keys.size();
  for (unsigned int i = 0; i < sz; i++)
    os << keys[i] << " ";
  os << endl;
  return os;
}
ostream& operator<<(ostream& os, const vector<char> keys) {
  vector<int>::size_type sz = keys.size();
  for (unsigned int i = 0; i < sz; i++)
    os << keys[i] << " ";
  os << endl;
  return os;
}

void disp_table(int table[101][101], int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      dbgp("%d ", table[i][j]);
    dbgp("\n");
  }
  dbgp("\n");
}
#else
#define db(x)
#define dbgp(...)
#define dmp(t,n)
#define disp_table(t,n,m)
#endif

ull fact(int n) {
  ull result = n;
  if (n <= 0) return 1;
  while ( --n > 1 )
    result *= n;
  return result;
}

int main() {
  int T, num=1;

  for (cin >> T; T--;) {
    unsigned long long found;
    vector<int> combos;
    vector<int> graph[101];
    vector<int> inv_graph[101];
    int         inv_graph_cnt[101];
    int roots = 0;
    vstr cars;
    string car;
    int N;
    cin >> N;
    FORN(i,N) { cin >> car; cars.pb(car); }
    db(cars);
    memset(inv_graph_cnt,0,sizeof(inv_graph_cnt));

    // Transform
    vector< vector<char> > letters; // letters and counts for each string
    vector< vector<char> > letters2; // letters and counts for each string
    map <char,int> all;            // all letters and nb of cars they appear in
    map <char,int> singles;        // all letters in cars of length 1
    FORN(i,N) {
      int sz;
      vector<char> let;
      sz = cars[i].size();
      for (int j = 1; j < sz; j++) {
        if (cars[i][j] != cars[i][j-1]) {
          let.pb(cars[i][j-1]);
          all[cars[i][j-1]]++;
        }
      }
      let.pb(cars[i][sz-1]);
      all[cars[i][sz-1]]++;
      letters.pb(let);
#if DBG
      FORN(j,let.size()) cerr << let[j] << ",";
      cerr << endl;
#endif
    }
#if DBG
    for (map<char,int>::iterator x = all.begin(); x != all.end(); x++) cerr << x->X << ":" << x->Y << ",";
    cerr << endl;
#endif

    // Check if middle letters appear elsewhere
    FORN(i,N) {
      int sz = letters[i].size();
      if (sz < 3) continue;
      for (int j = 1; j < sz - 1; j++) {
        // Look for that middle letter in other strings
        if (all[letters[i][j]] > 1) {
          dbgp("middle letter KO\n");
          goto KO;
        }
      }
    }

    // From here we don't care about middle letters anymore,
    // each car is defined only by beginning letter and end letter : a-b, b-c, c-d
    
    // First pass to reduce the 1-letter cars to number of combos :
    FORN(i,N) {
      int sz = letters[i].size();
      char c1 = letters[i][0];
      char c2 = letters[i][sz-1];
      if (c1 != c2) {
        vector <char> let;
        let.pb(c1);
        let.pb(c2);
        letters2.pb(let);
        continue;
      }
      singles[c1]++;
    }

    for (map<char,int>::iterator x = singles.begin(); x != singles.end(); x++) {
      int count = x->Y;
      if (count > 1) combos.pb(fact(count));
      dbgp("Combo %c : appears %d times\n", x->X, count);
      vector<char> let;
      let.pb(x->X);
      letters2.pb(let);
    }
    db(combos);
    FORN(i,letters .size()) db(letters [i]);
    FORN(i,letters2.size()) db(letters2[i]);
    N = letters2.size();
    letters.clear();
   
    // Prepare a graph of connections
    FORN(i,N) {
      // Origin string: a__b
      // Dest   string: c__d
      int sz = letters2[i].size();
      char a = letters2[i][0];
      //vint g; // graph from letters2[i]

      // Only one char in origin string
      if (sz == 1) {
        FORN(j,N) {
          if (i == j) continue;
          char c = letters2[j][0];
          if (a == c) {
            //g.pb(j);
            graph[i].pb(j);
            inv_graph[j].pb(i);
            inv_graph_cnt[j]++;
          }
        }

      } else {
        char b = letters2[i][sz-1];
        FORN(j,N) {
          if (i == j) continue;
          char c = letters2[j][0];
          if (b == c) {
            //g.pb(j);
            graph[i].pb(j);
            inv_graph[j].pb(i);
            inv_graph_cnt[j]++;
          }
        }
      }

      // If more than one out, only valid if all but one of the outs are length 1
      //if (g.size() > 1) {
      if (graph[i].size() > 1) {
        dbgp("direct graph check [%d]\n",i);
        int big = 0;
        FORN(j, graph[i].size()) {
          int s = letters2[graph[i][j]].size();
          dbgp("%d -> %d (sz:%d)\n", i, j, s);
          if (s > 1) big++;
          if (big > 1) {dbgp("direct graph KO\n"); goto KO;}
        }
      }
      //graph.pb(g);
    }
#if DBG
    dbgp("------------- Graph:\n");
    FORN(i,N) db(graph[i]);
    dbgp("------------- Inverse graph count:\n");
    FORN(i,N) dbgp("%d <-- %d\n", i, inv_graph_cnt[i]);
    cerr << endl;
#endif

    /*
    for (map<int,int>::iterator x = inv_graph_cnt.begin(); x != inv_graph_cnt.end(); x++) {
      if (x->Y > 1) goto KO;
    }
    */
    FORN(i,N) {
      if (inv_graph_cnt[i] > 1) {
        int big = 0;
        FORN(j, inv_graph[i].size()) {
          int s = letters2[inv_graph[i][j]].size();
          if (s > 1) big++;
          if (big > 1) { dbgp("inv_graph KO\n"); goto KO;}
        }
      }
    }

    // Regroup in connected parts
    dbgp("============================================================\n");
    FORN(i,N) {
      if (inv_graph_cnt[i] > 0) {
        if (letters2[i].size() > 1) {
          dbgp("Element %d : %c-%c is not a root\n", i, letters2[i][0], letters2[i][1]);
        } else {
          dbgp("Element %d : %c   is not a root\n", i, letters2[i][0]);
        }
      } else {
        if (letters2[i].size() > 1) {
          if (graph[i].size() > 0) {
            dbgp("Element %d : %c-%c is a root -> %d\n", i, letters2[i][0], letters2[i][1], graph[i][0]);
          } else {
            dbgp("Element %d : %c-%c is a root -> -\n", i, letters2[i][0], letters2[i][1]);
          }
        } else {
          if (graph[i].size() > 0) {
            dbgp("Element %d : %c   is a root -> %d\n", i, letters2[i][0], graph[i][0]);
          } else {
            dbgp("Element %d : %c   is a root -> -\n", i, letters2[i][0]);
          }
        }
        roots++;
      }
    }
    dbgp("============================================================\n");

    combos.pb(fact(roots));
    db(combos);
    found = 1;
    FORN(i, combos.size()) {
      found *= combos[i];
    }

    printf("Case #%d: %llu\n", num++, found);
    getchar();
    continue;
KO:
    printf("Case #%d: 0\n", num++);
    getchar();
  }


}
