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
vector<double> readVD(double n = 0);
vector<string> readVS(int n = 0);
vector<int> itokens(string s, string sep = " \n\r\t");
vector<string> stokens(string s, string sep = " \n\r\t");

// 0 -> 1, 1 -> -1, 2 -> i, 3 -> -i, 4 -> j, 5 -> -j, 6 -> k, 7 -> -k
int multtable[8][8] = {
{0, 1, 2, 3, 4, 5, 6, 7},
{1, 0, 3, 2, 5, 4, 7, 6},
{2, 3, 1, 0, 6, 7, 5, 4},
{3, 2, 0, 1, 7, 6, 4, 5},
{4, 5, 7, 6, 1, 0, 2, 3},
{5, 4, 6, 7, 0, 1, 3, 2},
{6, 7, 4, 5, 3, 2, 1, 0},
{7, 6, 5, 4, 2, 3, 0, 1}
};

bool consume_val(const vector<int> &ijk, int &used, int &rep, int maxrep, int target) {
  int val = 0, s_used = used;
//  printf(" consume %d, %d, %d, %d\n", used, rep, maxrep, target);
  for (; rep < maxrep; rep++) {
    for (used = s_used; used < (int)ijk.size(); used++) {
      val = multtable[val][ijk[used]];
//      printf("  ijk[%d] %d -> %d\n", used, ijk[used], val);
      if (val == target) {
        used++;
        if (used == (int)ijk.size()) {
          used = 0;
          rep++;
        }
        return true;
      }
    }
    // Start at beginning of next rep
    s_used = 0;
  }
  return false;
}
int consume_all(const vector<int> &ijk, int &used, int &rep, int maxrep) {
  int val = 0, s_used = used;
//  printf(" consume %d, %d, %d, %d\n", used, rep, maxrep, target);
  for (; rep < maxrep; rep++) {
    for (used = s_used; used < (int)ijk.size(); used++) {
      val = multtable[val][ijk[used]];
    }
    // Start at beginning of next rep
    s_used = 0;
  }
  return val;
}

void doIt() {
  int L, X;
	scanf("%d %d ", &L, &X);
  string sijk = readLine();
  vector<int> ijk(L);
  for (int i = 0; i < L; i++) ijk[i] = sijk[i] == 'i' ? 2 : (sijk[i] == 'j' ? 4 : 6);

//  printf("L %d, K %d\n", L, X);

  int used = 0, rep = 0;
  bool ok = consume_val(ijk, used, rep, X, 2);
  if (ok) {
//    printf("i done at %d, %d\n", used, rep);
    ok = consume_val(ijk, used, rep, X, 4);
    if (ok) {
//      printf("j done at %d, %d\n", used, rep);
      int v = consume_all(ijk, used, rep, X);
//      printf("final val %d\n", v);
      if (v != 6) {
        ok = false;
      }
    }
  }

  printf("%s\n", ok ? "YES" : "NO");
}

int main(int argc, char ** /*argv*/) {
	dbg = argc;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		printf("Case #%d: ", cn);
		doIt();
	}
	return 0;
}








string readLine() {
	char sz[100000];
	fgets(sz, 100000, stdin);
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
vector<string> stokens(string s, string sep) {
	vector<string> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}
vector<int> itokens(string s, string sep) {
	vector<int> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}
