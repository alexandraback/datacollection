#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define ULL unsigned long long

int m[5][5]={0,0,0,0,0,   0, 1, 2, 3, 4,   0, 2, -1, 4, -3,    0, 3, -4, -1, 2,    0, 4, 3, -2, -1};

map<pair<int, int>, int> H;
int whole;

int mul(int a, int b) {
  int sign=1;
  if (a<0) sign *= -1;
  if (b<0) sign *= -1;
  return m[abs(a)][abs(b)]*sign;
}

int Pow(int a, int N) {
  if (a == 1) return 1;
  if (a == -1) return pow(-1, N);
  if (N % 4 == 1) return a;
  else if (N % 4 == 2) return -1;
  else if (N % 4 == 3) return -a;
  else if (N % 4 == 0) return 1;
}

void build(vector<vector<int> > &x, string &s) {
  whole = 1;
  H.clear();
  for (int i=0; i<s.size(); ++i) {
    x[i][i] = s[i]-'0';
    whole = mul(whole, s[i]-'0');
  }

  for (int i=0; i<s.size(); ++i) {
    for (int j=i+1; j<s.size(); ++j) {
        x[i][j] = mul(x[i][j-1], s[j]-'0');
    }
  }
}


int get(vector<vector<int>> &x, long a, long b) {
  if (a>b) return 1;

  int L=x.size();
  long tmp = a - a/L*L;
  b = b - a/L*L;
  a = tmp;

  if (b < L) return x[a][b];

  //if (H.find(make_pair(a, b)) != H.end()) return H[make_pair(a, b)];

  long start = (L > a) ? a+(L-a)%L : a+(a-L)%L;
  long end = b - (b+1) % L;
  long num = (end - start + 1) / L;

  //cout << num << " " << get(x, a, start-1) << " " <<Pow(whole, num) << " " << get(x, end+1, b) << endl;

  //H[make_pair(a, b)] = mul(mul(get(x, a, start-1), Pow(whole, num)), get(x, end+1, b));
  //return H[make_pair(a, b)];
  return mul(mul(get(x, a, start-1), Pow(whole, num)), get(x, end+1, b));
}

int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	if (fin==NULL) exit(1);

  int N;
  fscanf(fin, "%d", &N);
  vector<int> z(N, 0);

  for (int i=0; i<N; ++i) {
    cerr << "Index: " << i << endl;
    int L;
    long X;
    fscanf(fin, "%d %ld", &L, &X);
    char c;
    fscanf(fin, "%c", &c);
    stringstream ss;
    for (int j=0; j<L; ++j) {
      fscanf(fin, "%c", &c);
      ss << (char) (c-'g'+'0');
    }
    string s = ss.str();
    vector<vector<int> > dp(L, vector<int>(L, -1));
    build(dp, s);

    //cout << ": " << get(dp, 0, 120) << endl;
    //cout << ": " << get(dp, 3, 123) << endl;

    if (Pow(whole, X) != -1) {
      continue;
    }

    for (int j=0; j<L*X; ++j) {
      if (get(dp, 0, j) == 2) {
        for (int k=L*X-1; k>j+1; --k) {
          if (get(dp, k, L*X-1) == 4) {
            z[i] = 1;
            break;
          }
        }
        break;
      }
    }
  }

  for (int i=0; i<N; ++i) {
    if (z[i])
      cout << "Case #" << i+1 << ": " << "YES" << endl;
    else
      cout << "Case #" << i+1 << ": " << "NO" << endl;
  }

	fclose(fin);
	return 0;
}


