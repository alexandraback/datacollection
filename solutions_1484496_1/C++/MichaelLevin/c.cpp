#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "C"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

bool FindTwoSubsetsSimple(const vector<int>& a, int n, vector<int>& first, vector<int>& second) {
  for (int mask = 1; mask < (1 << n); ++mask) {
    int other = (((1 << n) - 1) ^ mask);
    for (int mask2 = other; mask2; mask2 = ((mask2 - 1) & other)) {
      int sum1 = 0;
      int sum2 = 0;
      for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
          sum1 += a[i];
        } else if ((mask2 >> i) & 1) {
          sum2 += a[i];
        }
      }
      if (sum1 == sum2) {
        first.clear();
        second.clear();
        for (int i = 0; i < n; ++i) {
          if ((mask >> i) & 1) {
            first.push_back(a[i]);
          } else if ((mask2 >> i) & 1) {
            second.push_back(a[i]);
          }
        }
        return true;
      }
    }
  }
  return false;
}

ll GenRandomNumber(ll max) {
  return (rand() + (ll(rand()) << 16) + (ll(rand()) << 32)) % max + 1;
}

const ll MAX = 1000000 * ll(1000000);

unsigned short start = 1;
int MyRand() {
  start = 37 * start + 239;
  return start;
}

bool FindTwoSubsetsFast(const vector<ll>& a, int n, vector<ll>& first, vector<ll>& second) {
  map<ll, vi> sums;
  ll new_sum;
  long t = clock();
  do {
    new_sum = 0;
    vi masks;
    for (int i = 0; i < 4; ++i) {
      masks.push_back(rand());
      for (int j = i * 15; j < i * 15 + 15 && j < a.size(); ++j) {
        if ((masks.back() >> (j - i * 15)) & 1) {
          new_sum += a[j];
        }
      }
    }
    if (sums.count(new_sum) && sums[new_sum] != masks) {
      cerr << "Found answer" << endl;
      vi other_masks = sums[new_sum];
      ll sum1 = 0;
      ll sum2 = 0; 
      first.clear();
      second.clear();
      for (int i = 0; i < 4; ++i) {
        for (int j = i * 15; j < i * 15 + 15 && j < a.size(); ++j) {
          if ((masks[i] >> (j - i * 15)) & 1) {
            first.push_back(a[j]);
            sum1 += a[j];
          }
          if ((other_masks[i] >> (j - i * 15)) & 1) {
            second.push_back(a[j]);
            sum2 += a[j];
          }
        }
      }
      if (sum1 != sum2) {
        cerr << "Sums are different!" << endl;
        exit(1);
      }
      if (first != second) {
        cerr << clock() - t << endl;
        return true;
      }
    }
    sums[new_sum] = masks;
    if ((sums.size() & 65535) == 0) {
      cerr << sums.size() << endl;
    }
    /*if (sums.size() % 100000 == 0) {
      cerr << sums.size() << endl;
    }*/
  } while (true);
  return false;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    n = 500;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
      //cin >> a[i];
      a[i] = GenRandomNumber(MAX);
    }
    vector<ll> first, second;
    cerr << "Case #" << test_index + 1 << ":" << endl;
    //bool res = FindTwoSubsetsSimple(a, n, first, second);
    bool res = FindTwoSubsetsFast(a, n, first, second);
    cout << "Case #" << test_index + 1 << ":" << endl;
    if (!res) {
      cout << "Impossible" << endl;
    } else {
      for (int i = 0; i < first.size(); ++i) {
        cout << first[i] << ' ';
      }
      cout << endl;
      for (int i = 0; i < second.size(); ++i) {
        cout << second[i] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
