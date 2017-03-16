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

void solve(string& s) {
  if (s.empty())
    return;
  auto mid = max_element(s.begin(), s.end());
  char best = *mid;
  string middle(s.begin(), mid);
  string pre, post;
  for (char c : make_iterator_range(mid, s.end())) {
    if (c == best)
      pre += c;
    else
      post += c;
  }
  solve(middle);
  s = pre + middle + post;
}

int_ main() {
  int testcases; cin >> testcases;
  for (auto i : irange(int(1), testcases+1)) {;
    string s; cin >> s;
    solve(s);
    cout << "Case #" << i << ": " << s << '\n';
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 a.cc -o a && for f in *.in; do echo \"--- $f -------------\"; ./a <$f; done"
 * end:
 */
