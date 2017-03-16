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

void doIt() {
  int C, D, V;
	scanf("%d %d %d ", &C, &D, &V);
//  printf("Trying to solve %d: ", V);
  vector<int> dv = readVI(D);
  sort(dv.begin(), dv.end());
//  for (int i = 0; i < D; i++) printf("%d ", dv[i]);
//  printf("\n");

  vector<int> ok(V+1, 0);
  ok[0] = 1;
  for (int i = 0; i < D; i++) {
    for (int j = V; j >= dv[i]; j--) if (!ok[j]) {
        int x = j - dv[i];
        if (ok[x]) {
          ok[j] = 1;
        }
    }
  }

  int n = 0;
  for (int i = 0; i <= V; i++) if (!ok[i]) {
//    printf("Need a %d\n", i);
    n++;
    for (int j = V; j >= i; j--) if (!ok[j]) {
        int x = j - i;
        if (ok[x]) {
          ok[j] = 1;
        }
    }
  }
    
  printf("%d\n", n);
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
	char sz[10000];
	fgets(sz, 10000, stdin);
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
