#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

const long long MODULE = 1000000007LL;

int N;
bool fail;
bool charInMid[26];
ll trainsWay[26][26];
int startTrainsNumber[26];
int endTrainsNumber[26];
int singleTrainsNumber[26];

void initial() {
  fail = false;
  fill_n(charInMid, 26, false);
  for (int i = 0; i < 26; ++i) {
    singleTrainsNumber[i] = 0;
    endTrainsNumber[i] = 0;
    startTrainsNumber[i] = 0;
    for (int j = 0; j < 26; ++j) {
      trainsWay[i][j] = 0;
    }
  }
}

string uniqueString(string s) {
  auto it = unique(s.begin(), s.end());
  s.resize(distance(s.begin(), it));
  return s;
}

void trim(ll &number) {
  number %= MODULE;
  if (!number) number = MODULE;
}

ll factorial(int k) {
  ll cnt = 1;
  for (int i = 1; i <= k; ++i) {
    cnt *= i;
    trim(cnt);
  }
  return cnt;
}

void input() {
  initial();

  cin >> N;
  string tmp;
  //cout << endl;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;
    tmp = uniqueString(tmp);
    //cout << " " << tmp << endl;

    char b = tmp[0];
    char e = tmp[tmp.length() - 1];
    if (charInMid[b - 'a'] || charInMid[e - 'a']) {
      fail = true;
    }

    if (tmp.length() > 2) {
      for (unsigned j = 1; j < tmp.length() - 1; ++j) {
        char c = tmp[j];
        if (charInMid[c - 'a']) {
          fail = true;
        }
        charInMid[c - 'a'] = true;
      }
    }

    if (tmp.length() == 1) {
      singleTrainsNumber[b - 'a']++;
    } else {
      if (b == e) {
        fail = true;
      }
      if (trainsWay[b - 'a'][e - 'a']) {
        fail = true;
      } else {
        startTrainsNumber[b - 'a']++;
        endTrainsNumber[e - 'a']++;
        trainsWay[b - 'a'][e - 'a'] = 1;
      }
    }
  }
}

bool quickFail() {
  for (int i = 0; i < 26; ++i) {
    if (startTrainsNumber[i] > 1) return true;
    if (endTrainsNumber[i] > 1) return true;
  }
  return false;
}

bool hasCycle() {
  bool ways[26][26];
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (i == j) ways[i][j] = false;
      else {
        ways[i][j] = (trainsWay[i][j] > 0);
      }
    }
  }

  for (int k = 0; k < 26; ++k)
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) {
        if (ways[i][k] && ways[k][j]) ways[i][j] = true;
      }

  for (int k = 0; k < 26; ++k) {
    if (ways[k][k]) return true;
  }

  return false;
}

ll compute() {
  for (int i = 0; i < 26; ++i) {
    if (!singleTrainsNumber[i]) continue;

    ll way = factorial(singleTrainsNumber[i]);

    // find start.
    bool found = false;
    for (int j = 0; !found && j < 26; ++j) {
      if (j != i && trainsWay[i][j]) {
        found = true;
        trainsWay[i][j] *= way;
        trim(trainsWay[i][j]);
      }
    }

    // find end.
    for (int j = 0; !found && j < 26; ++j) {
      if (j != i && trainsWay[j][i]) {
        found = true;
        trainsWay[j][i] *= way;
        trim(trainsWay[j][i]);
      }
    }

    // single.
    if (!found) {
      trainsWay[i][i] = way;
    }
  }

  // simple contraction.

  bool update = true;
  while (update) {
    update = false;
    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j) {
          if (i == k || j == k) continue;

          if (trainsWay[i][k] && trainsWay[k][j]) {
            update = true;
            trainsWay[i][j] = trainsWay[i][k] * trainsWay[k][j];
            trim(trainsWay[i][j]);
            trainsWay[i][k] = trainsWay[k][j] = 0;
          }
        }
  }

  // handle all the remain
  int remainCnt = 0;
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j) {
      if (trainsWay[i][j]) remainCnt++;
    }

  ll permutation = factorial(remainCnt);

  ll finalResult = permutation;
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j) {
      if (trainsWay[i][j]) {
        finalResult *= trainsWay[i][j];
        trim(finalResult);
      }
    }

  return finalResult % MODULE;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    //cout << uniqueString("aaa") << endl;
    //cout << uniqueString("abba") << endl;
    //cout << uniqueString("abbcbba") << endl;
    //cout << uniqueString("abcd") << endl;

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        input();
        if (fail || quickFail() || hasCycle()) {
          cout << 0 << endl;
          continue;
        }

        cout << compute();

        printf("\n");
    }

    return 0;
}
