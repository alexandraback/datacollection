#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>
#include <fstream>

using namespace std;


struct Trie {
  Trie* c[26];
  bool end;
  Trie() {
    for(int i = 0; i < 26; ++i)
      c[i] = nullptr;
    end = false;
  }
};

Trie root;

void insert(Trie* t, const string& s, int idx) {
  //cerr << " " << s << " after " << idx << ": " << t << endl;
  if(idx == s.size()) {
    t->end = true;
    return;
  }
  if(t->c[s[idx]-'a'] == nullptr)
    t->c[s[idx]-'a'] = new Trie();
  insert(t->c[s[idx]-'a'], s, idx+1);
}

void parseDict() {
  ifstream fin("dict.txt");
  string s;
  while(fin >> s) {
    insert(&root, s, 0);
  }
}

void add(map<pair<Trie*, int>, int>& m, Trie* t, int p, int v) {
  if(p > 5) p = 5;
  pair<Trie*, int> pp = make_pair(t, p);
  if(m.find(pp) == m.end())
    m[pp] = v;
  else
    m[pp] = min(m[pp], v);
  if(t->end)
    add(m, &root, p, v);
}
void doit (int casenum) {
  string s;
  cin >> s;
  map<pair<Trie*, int>, int> mm[2];
  int l = 0;
  add(mm[l], &root, 5, 0);
  for(int i = 0; i < s.size(); ++i) {
    mm[1-l].clear();
    for(auto e : mm[l]) {
      //cout << "  " << i << ": " << e.first.first << " " << e.first.second << "  "<< e.second << endl;
      //if(e.first.first->end)
      //	add(mm[1-l], &root, e.first.second+1, e.second);
      if(e.first.first->c[s[i]-'a'])
	add(mm[1-l], e.first.first->c[s[i]-'a'], e.first.second + 1, e.second);
      for(int j = 0; j < 26; ++j)
	if(e.first.first->c[j] && e.first.second >= 5)
	  add(mm[1-l], e.first.first->c[j], 1, e.second + 1);
    }
    l = 1-l;
  }
  int k = s.size();
  for(int i = 0; i <= 5; ++i) {
    if(mm[l].find(make_pair(&root, i)) != mm[l].end())
      k = min(k, mm[l][make_pair(&root, i)]);
  }
  cout << "Case #" << casenum << ": " << k << endl;
}

int main () {
  parseDict();
  int t;
  cin >> t; //scanf ("%d ", &t);
  for (int i = 0; i < t; i++) {
    doit (i + 1);
  }
  return 0;
}
