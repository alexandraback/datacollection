#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int inf = 99999;

int solve(
  int ix, string &cur, int must,
  const string &ss, const set<string> &pref, const set<string> &dict,
  map<pair<pair<int, int>, string>, int> &tbl)
{
  // cerr << ix << ", " << cur << ", " << must << endl;

  if (ix >= ss.length()) {
    if (cur == "" || dict.count(cur))
      return 0;
    return inf;
  }

  if (tbl.count(make_pair(make_pair(ix, must), cur)))
    return tbl[make_pair(make_pair(ix, must), cur)];

  int &ret = tbl[make_pair(make_pair(ix, must), cur)];
  ret = inf;

  if (must > 0) {
    cur.push_back(ss[ix]);
    if (dict.count(cur)) {
      string emp;
      ret = min(ret, solve(ix+1, emp, must-1, ss, pref, dict, tbl));
    }
    if (pref.count(cur))
      ret = min(ret, solve(ix+1, cur, must-1, ss, pref, dict, tbl));
    cur.pop_back();
    return ret;
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    cur.push_back(c);
    if (c == ss[ix]) {
      string emp;
      if (dict.count(cur)) {
        ret = min(ret, solve(ix+1, emp, 0, ss, pref, dict, tbl));
      }
      if (pref.count(cur))
        ret = min(ret, solve(ix+1, cur, 0, ss, pref, dict, tbl));
    }
    else {
      if (dict.count(cur)) {
        string emp;
        ret = min(ret, solve(ix+1, emp, 4, ss, pref, dict, tbl) + 1);
      }
      if (pref.count(cur))
        ret = min(ret, solve(ix+1, cur, 4, ss, pref, dict, tbl) + 1);
    }
    cur.pop_back();
  }

  return ret;
}

int main()
{
  set<string> dict, pref;
  ifstream ifs("garbled_email_dictionary.txt");
  for (string w; ifs>>w; ) {
    for (int i=1; i+1<=w.length(); ++i)
      pref.insert(w.substr(0, i));
    dict.insert(w);
  }
  // cerr << "loaded" << endl;

  int cases; cin>>cases;
  for (int cn = 1; cn<=cases; ++cn) {
    string ss; cin>>ss;

    map<pair<pair<int, int>, string>, int> mm;
    string tt;
    int ans = solve(0, tt, 0, ss, pref, dict, mm);

    cout << "Case #" << cn << ": " << ans << endl;
  }

  return 0;
}