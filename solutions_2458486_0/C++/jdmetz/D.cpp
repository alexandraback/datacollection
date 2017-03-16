#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;
string readLine();
int readIntLine();
vector<int> readVI(int n = 0);
vector<string> readVS(int n = 0);
vector<int> itokens(string s, string sep);
vector<string> stokens(string s, string sep);

class Chest {
public:

vector<int> keys, open, co, path, self, last;
vector<vector<int> > ck;
set<vector<int> > seen;

bool bestPath() {
/*  for (size_t i = 0; i < path.size(); i++) {
    printf("%d ", path[i]);
  }
  printf(" : ");
  for (size_t i = 0; i < keys.size(); i++) {
    printf("%d ", keys[i]);
  }
  printf(" : ");
  for (size_t i = 0; i < open.size(); i++) {
    printf("%d", open[i]);
  }
  printf("\n");*/
  if (path.size() == open.size()) return true;
  if (seen.find(open) != seen.end()) return false;
  seen.insert(open);


  for (size_t i = 0; i < open.size(); i++) if (!open[i] && keys[co[i]]) {
    path.push_back(i+1);
    keys[co[i]]--;
    open[i]++;
    for (size_t j = 0; j < ck[i].size(); j++) keys[ck[i][j]]++;

    if (bestPath()) return true;

    for (size_t j = 0; j < ck[i].size(); j++) keys[ck[i][j]]--;
    open[i]--;
    keys[co[i]]++;
    path.pop_back();

    if (self[i] || last[i]) return false;
  }
  return false;
}

void doit(bool print = true) {
  int N;
  {
    int k;
    scanf("%d %d", &k, &N);
    vector<int> ks = readVI(k);
    for (size_t i = 0; i < ks.size(); i++) {
      if (ks[i] >= (int)keys.size()) keys.resize(ks[i]+1, 0);
      keys[ks[i]]++;
    }
  }
  co.resize(N);
  ck.resize(N);

  int mxk = keys.size()-1;
  for (int i = 0; i < N; i++) {
    scanf("%d", &co[i]);
    ck[i] = readVI();
    for (size_t j = 0; j < ck[i].size(); j++) if (ck[i][j] > mxk) mxk = ck[i][j];
  }
  if (mxk >= (int)keys.size()) keys.resize(mxk+1, 0);

  self.resize(N, 0);
  last.resize(N);

  vector<int> lco(keys.size(), -1);
  for (int i = 0; i < N; i++) {
    if (lco[co[i]] > -1) last[lco[co[i]]] = 0;
    last[i] = 1;
    lco[co[i]] = i;

    for (size_t j = 0; j < ck[i].size(); j++) if (ck[i][j] == co[i]) self[i] = 1;
  }
  
  open.resize(N, 0);

//  vector<int> totk = keys;
//  for (size_t i = 0; i < ck.size(); i++) for (size_t; j = 0; j < ck[i].size(); j++)

  bestPath();

  if (print) {
    if (path.empty()) printf("IMPOSSIBLE\n");
    else {
      for (size_t i = 0; i < path.size(); i++)
        printf("%d%c", path[i], i+1 == path.size() ? '\n' : ' ');
    }
  }
}
};



/**
 * Library code
 */

int main(int argc, char **argv) {
  int wcase = 0;
  if (argc > 1) wcase = atoi(argv[1]);

	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
    bool print = !wcase || wcase == cn;
		if (print) printf("Case #%d: ", cn);
    Chest c;
		c.doit(print);
	}
	return 0;
}

string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}
int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}
vector<int> readVI(int n) {
	if (!n) scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}
vector<string> readVS(int n) {
	if (!n) scanf("%d ", &n);
	vector<string> v(n);
	for (int i = 0; i < n; i++) v[i] = readLine();
	return v;
}
vector<string> stokens(string s, string sep = " \n\r\t") {
	vector<string> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}
vector<int> itokens(string s, string sep = " \n\r\t") {
	vector<int> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}

