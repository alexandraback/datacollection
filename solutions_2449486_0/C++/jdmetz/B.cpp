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
vector<int> readVI(int n);
vector<string> readVS(int n);
vector<int> itokens(string s, string sep);
vector<string> stokens(string s, string sep);

void doit(bool print = true) {
  int X, Y;
  scanf("%d %d ", &Y, &X);
  vector<vector<int> > g(Y);
  for (int i = 0; i < Y; i++) g[i] = readVI(X);

  bool ok = true;
  vector<int> cmax(X, 0), rmax(Y, 0);
  for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
    if (g[y][x] > cmax[x]) cmax[x] = g[y][x];
    if (g[y][x] > rmax[y]) rmax[y] = g[y][x];
  }

  for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
    if (g[y][x] < cmax[x] && g[y][x] < rmax[y]) {
      ok = false;
    }
  }

  if (print) printf("%s\n", ok ? "YES" : "NO");
}




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
		doit(print);
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
vector<int> readVI(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}
vector<string> readVS(int n = 0) {
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

