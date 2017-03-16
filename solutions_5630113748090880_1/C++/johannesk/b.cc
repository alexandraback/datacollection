#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
#include <boost/range.hpp>
#include "../../prettyprint.hpp"
using namespace std;
using boost::irange;
using boost::make_iterator_range;

#ifdef NDEBUG
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/null.hpp>
boost::iostreams::stream<boost::iostreams::null_sink> logs((boost::iostreams::null_sink()));
#else
auto& logs = cerr;
#endif

using int_ = int;
#define int int_fast64_t

vector<int> solve() {
  int n; cin >> n;
  vector<vector<int> > lists(2*n-1);
  for (auto& l : lists) {
    copy_n(istream_iterator<int>(cin), n, back_inserter(l));
    assert(is_sorted(l.begin(), l.end()));
  }
  int missing = -1;
  int missing_index = -1;
  for (int d=0, k=0; d<n; ++d) {
    sort(lists.begin()+k, lists.end(), [d](auto& a, auto& b) { return a[d] < b[d]; });
    if (k+1 < lists.size() && lists[k][d] == lists[k+1][d]) {
      k += 2;
    } else {
      missing = k;
      missing_index = d;
      k += 1;
    }
  }
  assert(missing != -1);
  assert(missing_index != -1);
  auto x = lists[missing];
  vector<int> solution(n);
  for (int d=0, k=0; d<n; ++d) {
    if (d == missing_index) {
      k += 1;
      solution[missing_index] = x[missing_index];
      continue;
    }
    int a = lists[k][missing_index];
    int b = lists[k+1][missing_index];

    if (x[d] == a) {
      solution[d] = b;
    } else {
      assert(x[d] == b);
      solution[d] = a;
    }
    k += 2;
  }
  return solution;
}

int_ main() {
  int testcases; cin >> testcases;
  for (auto i : irange(int(1), testcases+1)) {;
    cout << "Case #" << i << ": ";
    auto res = solve();
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 b.cc -o b && for f in *.in; do echo \"--- $f -------------\"; ./b <$f; done"
 * end:
 */
