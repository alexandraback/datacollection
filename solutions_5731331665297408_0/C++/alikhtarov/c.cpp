#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<size_t>;
using vvi = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;

vb fseen;
vi seen;
vi par;
vvi es;
vs ss;

bool reachable(size_t i, size_t j) {
  if (i == j) {
    return true;
  }

  ++seen[i];
  for (auto x : es[i]) {
    if (seen[x] < 2 && reachable(x, j)) {
      --seen[i];
      return true;
    }
  }
  --seen[i];
  return false;
}

void findbest(size_t i, vi& path, string& best, vi& bpath) {
  path.push_back(i);
  fseen[i] = true;
  cerr << i << ' ' << seen[i] << ' ' << ss[i] << ' ' << best << endl;
  if (seen[i] == 0) {
    if (ss[i] <= best) {
      best = ss[i];
      bpath = path;
    }
  } else if (seen[i] == 1) {
    for (auto x : es[i]) {
      if (seen[x] < 2 && !fseen[x]) {
	bool inc = false;
	if (x == par[i] || !seen[i]) {
	  ++seen[i];
	  inc = true;
	}

	bool bad = false;
	if (seen[i] == 2) {
	  for (auto y : es[i]) {
	    if (y != x && seen[y] < 2 &&
		!reachable(x, y)) {
	      bad = true;
	      break;
	    }
	  }
	}
	
	if (!bad) {
	  findbest(x, path, best, bpath);
	}

	if (inc) {
	  --seen[i];
	}
      }
    }
  }
  fseen[i] = false;
  path.pop_back();
}

string dfs(size_t i, size_t p) {
  string out = ss[i];
  assert(seen[i] == 0);
  par[i] = p;
  seen[i]++;

  string best = "99999";
  vi path, bpath;
  fseen = vb(ss.size(), false);
  cerr << "fb" << endl;
  findbest(i, path, best, bpath);
  if (bpath.empty()) {
    return out;
  }
  cerr << "best " << best << endl;
  for (size_t j = 1; j < bpath.size(); ++j) {
    if (bpath[j] == par[bpath[j-1]]) {
      seen[bpath[j-1]]++;
      cerr << "mark " << bpath[j-1] << " " << seen[bpath[j-1]] << endl;
    }
  }
  return out + dfs(bpath.back(), bpath[bpath.size() - 2]);
}

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    int n, m, a, b;
    cin >> n >> m;
    es = vvi(n);
    string s;
    ss.clear();
    while (n-- && cin >> s) ss.push_back(s);
    while (m-- && cin >> a >> b)
      --a, --b, es[a].push_back(b), es[b].push_back(a);

    string best = "99999";
    size_t bi = ss.size();
    for (size_t i = 0; i < ss.size(); ++i) {
      if (ss[i] <= best) {
	bi = i;
	best = ss[i];
      }
    }
    assert(bi < ss.size());

    seen = vi(ss.size(), 0);
    par = vi(ss.size(), ss.size());

    cout << "Case #" << ncase << ": " << dfs(bi, ss.size()) << endl;
  }
}
