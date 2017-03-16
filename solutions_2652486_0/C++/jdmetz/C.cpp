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

void doit(int N, int M, int K) {
  vector<int> p = readVI(K);
  vector<vector<int> > cts(M+1, vector<int>(7, 0));
  for (int i = 0; i < K; i++) {
    for (int j = 2; j <= M; j++) {
      int v = j, k = 0;
      while (!(p[i]%v)) {
        cts[j][k++]++;
        v *= j;
      }
    }
  }
  vector<int> d;
/*  for (int i = 2; i <= M; i++) {
    printf("%d: ", i);
    for (int j = 0; j < N; j++) printf("%d ", cts[i][j]);
    printf("\n");
  }*/
  for (int i = 0; i < N; i++) if (cts[5][i]) d.push_back(5);
  for (int i = 0; i < N; i++) if (cts[3][i]) d.push_back(3);
  if (cts[4][1]) d.push_back(4);
  if (cts[4][2] || cts[2][4]) d.push_back(4);
  if (cts[2][0] > cts[2][1] || cts[2][2] > cts[2][3] || cts[2][4] > cts[2][5]) d.push_back(2);
  else if (cts[4][0]) d.push_back(4);
  if (d.size() != N) {
    if (cts[5][0] > cts[3][0]) {
      d.push_back(5);
    } else {
      d.push_back(3);
    }
  }
  while (d.size() != N) {
    d.push_back(2);
  }
  for (int i = 0; i < N; i++) printf("%d", d[i]);
  printf("\n");
}




/**
 * Library code
 */

int main(int argc, char **argv) {
  int wcase = 0;
  if (argc > 1) wcase = atoi(argv[1]);

	int CCT = readIntLine();
  printf("Case #1:\n");
  int R, N, M, K;
  scanf("%d %d %d %d ", &R, &N, &M, &K);
	for (int cn = 1; cn <= R; cn++) {
		doit(N, M, K);
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

