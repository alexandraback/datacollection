// {{{ Headers
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <cassert>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;
// }}}

typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }

int
main () {
#ifdef LOCALHOST
    freopen ("test.in", "r", stdin);
    // freopen ("test.out", "w", stdout);
#endif
    int T, N;
    scanf ("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf ("%d", &N);
        vector <string> v;
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            v.push_back (s);
        }
        sort (v.begin (), v.end ());
        vector <int> u;
        for (int i = 0; i < N; i++) u.push_back (i);
        int cnt = 0;
        do {
            string w = "";
            for (int i = 0; i < N; i++)
                w += v [u [i]];
            w.erase (unique (w.begin (), w.end ()), w.end ());
            int lw = len (w);
            int dat [30];
            memset (dat, 0, sizeof (dat));
            for (int i = 0; i < len (w); i++) dat [w [i] - 'a'] = 1;
            int lx = 0;
            for (int i = 0; i < 30; i++) lx += dat [i];
            // string x = w;
            // sort (x.begin (), x.end ());
            // x.erase (unique (x.begin (), x.end ()), x.end ());
            // debug ("1: ", w);
            // if (len (x) == len (w)) {
            if (lx == lw) {
                cnt++;
            }
        } while (next_permutation (u.begin (), u.end ()));
        // map <string, int> d;
        // int64 ret = cnt;
        // for (int i = 0; i < len (v); i++) d [v [i]]++;
        // for (__typeof__ (d.begin ()) it = d.begin (); it != d.end (); ++it)
            // ret *= (it->second);
        printf ("Case #%d: %d\n", t, cnt);

    }

    return 0;
}

