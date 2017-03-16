#include <algorithm>
#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ifstream fin ("b0.in");
ofstream fout ("b0.out");
const int INF = 0x3f3f3f3f;

int abs(int x) { return x >= 0 ? x : -x; }

string s;
int n;
int d[6];

int coders, jammers, mn;
string cstring, jstring;
void process() {
  int c = 0, j = 0;
  stringstream sc, sj;
  for (int i = 0; i < n; ++i) {
    c *= 10;
    c += d[i];
    sc << d[i];
  }
  for (int i = n; i < 2*n; ++i) {
    j *= 10;
    j += d[i];
    sj << d[i];
  }
  int diff = abs(c-j);
  if (mn > diff ||
      (mn == diff && coders > c) ||
      (mn == diff && coders == c && jammers > j)) {
    mn = diff;
    coders = c;
    jammers = j;
    cstring = sc.str();
    jstring = sj.str();
  }
}

void back(int lvl) {
  if (lvl == 2*n) {
    process();
  } else if (d[lvl] != -1) {
    back(lvl+1);
  } else {
    for(int digit = 0; digit < 10; ++digit) {
      d[lvl] = digit;
      back(lvl+1);
    }
    d[lvl] = -1;
  }
}

int main() {
  int T;
  string sc, sj;
  fin >> T;
  //cout << T << " cases" << endl;
  for(int t = 1; t <= T; ++t) {
    mn = INF, coders = INF, jammers = INF;
    fin >> sc >> sj;
    n = sc.size();
    s = sc + sj;

    //cout << "Case #" << t << ": " << s << "\t" << n << endl;
    for (int i = 0; i < 2*n; ++i) {
      d[i] = (s[i] == '?' ? -1 : s[i] - '0');
    }

    back(0);
    //cout << mn << "\t" << coders << "\t" << jammers << endl;
    fout << "Case #" << t << ": ";
    fout << cstring << " " << jstring << '\n';
  }

  return 0;
}