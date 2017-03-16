#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

//#define debug(...)
#define debug printf

int R, N, M, K;


class Record {
  public:
    int num[3];
    vector<int> products;

    Record(int i, int j, int k) {
      num[0] = i;
      num[1] = j;
      num[2] = k;
    }
};

vector<Record> records;

void gen() {
  for (int i = 2; i <= 5; ++i)
    for (int j = 2; j <= 5; ++j)
      for (int k = 2; k <= 5; ++k) {
        records.push_back(Record(i, j, k));
      }
  //cout << records.size() << endl;

  for (int i = 0; i < records.size(); ++i) {
    Record &r = records[i];
    r.products.push_back(1);
    r.products.push_back(r.num[0]);
    r.products.push_back(r.num[1]);
    r.products.push_back(r.num[2]);
    r.products.push_back(r.num[0] * r.num[1]);
    r.products.push_back(r.num[0] * r.num[2]);
    r.products.push_back(r.num[1] * r.num[2]);
    r.products.push_back(r.num[0] * r.num[1] * r.num[2]);
  }
}

int main() {
  int caseN;
  scanf("%d", &caseN);

  for (int cc = 1; cc <= caseN; ++cc) {
    printf("Case #%d:\n", cc);

    cin >> R >> N >> M >> K;
    gen();

    bool ok[records.size()];

    // each line.
    for (int i = 0; i < R; ++i) {
      fill_n(ok, records.size(), true);

      for (int j = 0; j < K; ++j) {
        int num;
        cin >> num;

        for (int k = 0; k < records.size(); ++k) {
          if (!ok[k]) continue;
          if (find(records[k].products.begin(), records[k].products.end(), num)
              == records[k].products.end()) {
            ok[k] = false;
          }
        }
      }

      // find first ok.
      int res = 0;
      for (res = 0; res < records.size(); ++res)
        if (ok[res]) break;

      Record &result = records[res];
      printf("%d%d%d\n", result.num[0], result.num[1], result.num[2]);
    }

    printf("\n");
  }

  return 0;
}

