#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

namespace debug {
  
template<class T> string _str(const T x) {ostringstream str; str << x; return str.str(); }
string _str(const bool x) {ostringstream str; str << (x ? "true" : "false"); return str.str(); }
string _str(const int x) {ostringstream str; str << x; return str.str(); }
string _str(const long long x) {ostringstream str; str << x; return str.str(); }
string _str(const char x) {ostringstream str; str << "'" << x << "'"; return str.str(); }
string _str(const string x) {ostringstream str; str << '"' << x << '"'; return str.str(); }
string _str(const double x) {ostringstream str; str.precision(6); str.setf(ios::fixed); str << x; return str.str(); }
string _str(const char* x) { return _str((string) x);}

template<class K, class V> string _str(const pair<K, V> x);
template<class T> string _str(const vector<T> x);
template<class T> string _str(const set<T> x);
template<class K, class V> string _str(const map<K, V> x);

template<class K, class V> string _str(const pair<K, V> x) {ostringstream str; str << '(' << _str(x.first) << ", " << _str(x.second) << ')'; return str.str();}   
template<class T> string _str(const vector<T> x) {ostringstream str; str << "["; for(int i = 0; i < x.size(); ++i) { if (i) str << ", "; str << _str(x[i]); } str << "] size " << x.size(); return str.str(); }
template<class T> string _str(const set<T> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << _str(it); } str << "} size " << x.size(); return str.str(); }
template<class K, class V> string _str(const map<K, V> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << _str(it.X) << " -> " << _str(it.Y); } str << "} size " << x.size(); return str.str(); }

void _dvar(bool isfirst, vector<string>::iterator it) {}
template<typename TCur, typename... TArgs>
void _dvar(bool isfirst, vector<string>::iterator it, TCur cur, TArgs... x) {if (!isfirst) cerr << " | "; cerr << *it << " = " << _str(cur); _dvar(false, ++it, x...); }

template<typename... TArgs>
void _d(string arg_names, TArgs... args) {
  int open = 0;
  vector<string> names;
  string cur;
  char wait_for_quote = 0;
  for (char c: arg_names) {
    if (c == ',' && open == 0 && !wait_for_quote) {
      names.pb(cur);
      cur = "";
    } else {
      cur += c;
      if (wait_for_quote) {
	if (wait_for_quote == c)
	  wait_for_quote = 0;
      } else {
	if (c == '\'' || c == '"') wait_for_quote = c; else {
	  if (c == '(') open++; else if (c == ')') open--;
	}
      }
    }
  }
  if (sz(cur)) {
    names.pb(cur);
  }
  _dvar(true, names.begin(), args...);
  cout << endl;
}
	
#ifdef LocalHost2
#define D(x...) _d(#x, x)
// Use it as C(__LINE__)
#define C(line, x...) cout << __FILE__ << ":" << line << " "; D(x)
#else
#define D(x...);
#define C(x...);
#endif
} // ~namespace debug
using namespace debug;

string problemName = "D";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

int x, r, c;

struct tile {
  int n, m;
  vector<vector<bool>> a;

  tile() {
  }
  
  tile(int n, int m): n(n), m(m) {
    a.resize(n);
    REP (i, n) a[i].resize(m);
  }

  vector<bool>& operator[](int i) {
    return a[i];
  }

  bool operator < (tile o) const {
    return a < o.a;
  }

  bool operator == (tile o) const {
    return a == o.a;
  }

  bool apply(vector<vector<bool>>& field, int y, int x) {
    if (y + n > r) return false;
    if (x + m > c) return false;
    REP (i, n) {
      REP (j, m) if (a[i][j] && field[i+y][x+j]) return false;
    }
    REP (i, n) {
      REP (j, m) if (a[i][j]) field[i+y][x+j] = true;
    }
    return true;
  }

  void remove(vector<vector<bool>>& field, int y, int x) {
    REP (i, n) {
      REP (j, m) if (a[i][j]) field[i+y][x+j] = false;
    }
  }

  tile rot() {
    tile t(m, n);
    REP (i, n) {
      REP (j, m) {
	t[j][i] = a[i][j];
      }
    }
    return t;
  }
};

ostream& operator << (ostream& out, tile& t) {
  REP (i, t.n) {
    REP (j, t.m) {
      out << (t[i][j] ? '#' : ' ');
    }
    out << endl;
  }
  return out;
}

ostream& operator << (ostream& out, vector<vector<bool>>& t) {
  REP (i, sz(t)) {
    REP (j, sz(t[i])) {
      out << (t[i][j] ? '#' : '.');
    }
    out << endl;
  }
  return out;
}

const int offset = 16;
bool togen[2*offset][2*offset];

vector<tile> tiles;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void gen(int num) {
  if (num == x) {
    int miny = offset, minx = offset, maxy = offset, maxx = offset;
    REP (i, 2*offset) {
      REP (j, 2*offset) if (togen[i][j]) {
	minx = min(minx, j);
	miny = min(miny, i);
	maxx = max(maxx, j);
	maxy = max(maxy, i);
      }
    }
    tile t(maxy-miny+1, maxx-minx+1);
    REP (i, t.n) REP (j, t.m) {
      t[i][j] = togen[i+miny][j+minx];
    }
    tiles.pb(t);
    return;
  }
  REP (i, 2*offset) {
    REP (j, 2*offset) if (togen[i][j]) {
      REP (dir, 4) {
	int q = i + dy[dir];
	int w = j + dx[dir];
	if (!togen[q][w]) {
	  togen[q][w] = true;
	  gen(num+1);
	  togen[q][w] = false;
	}
      }
    }
  }
}

vector<vector<bool>> field;
unordered_set<long long> visited;
	      
bool fill(int y, int x, int itile = 0) {
  if (x == c) {
    return true;
  }
  //  cout << field << endl;
  long long mask = 0;
  FOR (xx, x, x + 6) {
    REP (y, r) {
      if (xx >= c) mask *= 2; else {
	mask = mask * 2 + field[y][x];
      }
    }
  }
  mask = mask * r + y;
  mask = mask * c + x;
  mask = mask * sz(tiles) + itile;
  if (visited.count(mask)) return false;
  visited.insert(mask);

  int nexty = y+1;
  int nextx = x;
  if (nexty == r) {
    nexty = 0;
    nextx++;
  }
  if (field[y][x]) {
    if (fill(nexty, nextx)) return true;
  }
  for (; itile < sz(tiles); ++itile) {
    if (tiles[itile].apply(field, y, x)) {
      if (fill(y, x, itile)) {
	tiles[itile].remove(field, y, x);
	return true;
      }
      tiles[itile].remove(field, y, x);
    }
  }
  return false;
}

bool exists() {
  if (x > 6) return true;
  if ((r * c) % x) return true;
  if (x > r && x > c) return true; // Either r or c <= 6
  if (r > c) swap(r, c);

  tiles.clear();
  togen[offset][offset] = true;
  gen(1);

  // D(sz(tiles));
  sort(all(tiles));
  tiles.resize(unique(all(tiles)) - tiles.begin());
  D(sz(tiles));

  // REP (i, sz(tiles)) {
  //   cout << tiles[i] << endl;
  // }

  for (auto t: tiles) {
    bool can = false;
    REP (rot, 2) {
      REP (y, r) REP (x, c) if (!can) {
	field = vector<vector<bool>>(r, vector<bool>(c));
	if (t.apply(field, y, x)) {
	  visited.clear();
	  D(y, x);
	  if (fill(0, 0)) can = true;
	  t.remove(field, y, x);
	}
      }
      t = t.rot();
    }
    if (!can) {
      //      cout << t << endl;
      return true;
    }
  }
  return false;
}

int main () {
    freopen(inputFileName.data(), "r", stdin);
    if (fileName == smallFileName || fileName == largeFileName)
    {
    	freopen(outputFileName.data(), "w", stdout);
    }
    int T;
    cin >> T;
    REP (test, T) {
	cin >> x >> r >> c;
	//	D(x, r, c);
	bool e = exists();
	cout << "Case #" << (test + 1) << ": ";
	cout << (e ? "RICHARD" : "GABRIEL") << endl;
    }
    return 0;
}
