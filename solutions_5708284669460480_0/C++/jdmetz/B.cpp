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

int countB(string &keys, string &target, char sofar[], int pos, int S) {
  int b = 0;
  if (pos == S) {
    int ts = target.size();
    for (int i = 0; i+ts <= S; i++) {
      bool ok = true;
      for (int j = 0; j < ts; j++) if (target[j] != sofar[j+i]) {
        ok = false;
        break;
      }
      if (ok) b++;
    }
    return b;
  }

  for (size_t i = 0; i < keys.size(); i++) {
    sofar[pos] = keys[i];
    b += countB(keys, target, sofar, pos+1, S);
  }
  return b;
}

bool ispossible(string &k, string &t) {
  vector<int> c(26, 0);
  for (size_t i = 0; i < k.size(); i++) c[k[i]-'A']++;
  for (size_t i = 0; i < t.size(); i++) if (!(c[t[i]-'A'])) return false;
  return true;
}

void doIt() {
  int K, L, S;
	scanf("%d %d %d ", &K, &L, &S);
  string keys = readLine();
  string target = readLine();

  if (ispossible(keys, target)) {
    int nono = target.size();
    for (size_t i = 1; i < target.size(); i++) {
      bool ok = true;
      for (size_t j = 0; j+i < target.size(); j++) {
        if (target[j] != target[i+j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        nono = i;
        break;
      }
    }

    int maxb = 1 + (S - target.size())/nono;
    int totct = 1;
    for (int i = 0; i < S; i++) totct *= K;
    char sofar[128];
    int totb = countB(keys, target, sofar, 0, S);
    double expect = (maxb * totct - totb)/(double)totct;
    printf("%.10lf\n", expect);
  } else {
    printf("0.0\n");
  }
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
