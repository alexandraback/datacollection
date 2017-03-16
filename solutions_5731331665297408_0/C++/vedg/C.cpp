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
# include <utility>
# include <array>
# include <cassert>

using namespace std;

vector<int> codes;


vector<vector<int>> neigbours;
vector<int> priorities;


struct Point {
    vector<int> ans;
    vector<char> used;
};

vector<Point> history;

bool solve()
{
    if (history.size() == codes.size())
        return true;
    const vector<char> & lastUsed = history.back().used;
    const vector<int> & lastAns = history.back().ans;
    history.push_back(history.back());
    for (int i = 1; i < priorities.size(); ++i) {
        int cur = priorities[i];
        if (! lastUsed[cur]) {
            for (int j = lastAns.size() - 1; j >= 0; --j) {
                if (binary_search(neigbours[cur].begin(), neigbours[cur].end(),  j)) {

                    history.back().ans.push_back(cur);
                    history.back().used[cur] = true;
                    if (solve())
                        return true;
                    else {
                        history.back().ans.pop_back();
                        history.back().used[cur] = false;
                    }
                }
            }
        }
    }
    history.pop_back();
    return false;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("small.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        cout << "Case #" << cas << ": " << endl;
        int cities, flights;
        cin >> cities >> flights;
        codes.resize(cities);
        for (int i = 0; i < cities; ++i)
            cin >> codes[i];
        neigbours.clear();
        neigbours.resize(cities);
        for (int i = 0; i < flights; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            neigbours[a].push_back(b);
            neigbours[b].push_back(a);
        }
        priorities.resize(cities);
        iota(priorities.begin(), priorities.end(), 0);
        sort(priorities.begin(), priorities.end(), [& codes](int a, int b) {
            return codes[a] < codes[b];
        });


        history.clear();
        history.resize(1);
        history.front().ans.resize(1, priorities[0]);
        history.front().used.resize(cities);
        history.front().used[priorities[0]] = true;

        for (int i = 0; i < neigbours.size(); ++i)
            sort(neigbours[i].begin(), neigbours[i].end());
history.reserve(cities);

if (cities == 2) {
    cout << codes[priorities[0]] << codes[priorities[1]];
}else {

        const bool ss = solve();



       // assert(ss);

        vector<int> t = history.back().ans;
        for (int i = 0; i < t.size(); ++i)
            cout << codes[t[i]];
}
        cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}
