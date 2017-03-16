#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

#define MAXLOGAB 10000000

static vector<long long> palind;

inline bool
ispal (long long num)
{
    char tmp[100];
    int len;

    sprintf (tmp, "%lld", num);
    len = strlen (tmp);
    for (int i = 0; i < len - i; ++i) {
        if (tmp[i] != tmp[len - 1 - i]) return false;
    }
    return true;
}

void
get_palind (int limit)
{
    palind.clear();
    for (int i = 1; i <= limit; ++i) {
        if (ispal (i)) palind.push_back(i);
    }
}

int
main ()
{
    int T, ans;
    long long A, B;

    get_palind (MAXLOGAB);

    cin >> T;
    for (int k = 1; k <= T; ++k) {
        cin >> A >> B;
        ans = 0;

        for (size_t i = 0; i < palind.size(); ++i) {
            long long t = palind[i] * palind[i];
            if (t >= A && t <= B && ispal(t)) ++ans;
        }
        cout << "Case #" << k << ": " << ans << endl;
    }
    return 0;
}
