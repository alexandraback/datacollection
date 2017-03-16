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

vector<string> patterns;

void input() {
  initial();
  patterns.clear();

  cin >> N;
  string tmp;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;
    tmp = uniqueString(tmp);
    patterns.push_back(tmp);
  }
}

bool valid(vector<int> order) {
  bool used[26];
  char prev = '#';
  fill_n(used, 26, false);

  for (int o : order) {
    string &s = patterns[o];
    for (char ch : s) {
      if (ch != prev && used[ch - 'a']) return false;
      prev = ch;
      used[ch - 'a'] = true;
    }
  }
  return true;
}

ll compute() {
  vector<int> order;
  order.resize(N);
  for (int i = 0; i < N; ++i) order[i] = i;

  ll ways = 0;
  do {
    if (valid(order)) ways++;
    trim(ways);
  } while(next_permutation(order.begin(), order.end()));

  return ways % MODULE;
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
        cout << compute();

        printf("\n");
    }

    return 0;
}
