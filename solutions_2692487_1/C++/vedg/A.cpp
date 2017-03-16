//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        int a, n;
        cin >> a >> n;
        deque<int> motes(n);
        for (int i = 0; i != motes.size(); ++i)
            cin >> motes[i];
        int ans = n;

        sort(motes.begin(), motes.end());
        if (a > 1) {
            for (int i = 0; ! motes.empty() ; ++i) {
                while (! motes.empty() && a > motes.front()) {
                    a += motes.front();
                    motes.pop_front();
                }
                ans = min(ans, int(motes.size()) + i);
                a += a - 1;
            }
        }

        cout << "Case #" << cas << ": ";
        cout << ans << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    //putchar('\n');
#endif
}

