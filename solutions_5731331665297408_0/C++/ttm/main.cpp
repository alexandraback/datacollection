#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long iint;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int cases; cin >> cases;
    int seen[51];
    for (int cas = 1; cas <= cases; ++cas) {
        cout << "Case #" << cas << ": ";
        int nv, ne; cin >> nv >> ne;
        vector<pair<int, int>> places;
        places.emplace_back(0, 0);
        vector<int> res;
        vector<vector<int>> adj(nv + 1);
        for (int i = 1; i <= nv; ++i) {
            int zip; cin >> zip;
            places.emplace_back(zip, i);
        }
        sort(places.begin(), places.end());
        memset(seen, 0, sizeof seen);
        for (int i = 0; i < ne; ++i) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        seen[places.front().second] = 1;
        set<int> s;
        s.insert(places[1].second);
        res.push_back(places[1].second);
        while (s.size() != nv) {
            int min = 1000000;
            int best;
            for (int in : s) {
                for (int i = 0; i < adj[in].size(); ++i) {
                    int next = adj[in][i];
                    if (seen[next]) continue;
                    int tmp = places[next].first;
                    if (tmp < min) {
                        min = tmp;
                        best = next;
                    }
                }
            }
            seen[best] = true;
            s.insert(best);
            res.push_back(places[best].second);
        }
        sort(places.begin(), places.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second < b.second; });
        for (int r : res) {
            cout << places[r].first;
        }
        cout << endl;
    }
}
