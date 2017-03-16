#include <iostream>
#include <sstream> 
#include <cstdio>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
template<typename T> T ABS(const T& val) { return val < 0 ? -val : val; }

int dfs(int& ind, vector<char>& used, const vector<pair<int, int> >& cities, const vector< vector<int> >& edges)
{
    if (used[ind])
        return 0;
    used[ind] = true;
    int u = cities[ind].second;
    int res = 1;

    bool found = ind + 1 != cities.size();

    while (found) {
        found = false;

        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];

            if (ind + 1 != cities.size() && v == cities[ind + 1].second) {
                ++ind;
                res += dfs(ind, used, cities, edges);
                found = true;
            }
        }
    }

    return res;
}

bool check(const vector<pair<int, int> >& cities, const vector< vector<int> >& edges)
{
    vector<char> used(cities.size(), false);
    int ind = 0;
    return cities.size() == dfs(ind, used, cities, edges);
}

int main ()
{
    std::ios_base::sync_with_stdio(false);

    int T;
    while (cin >> T)
    {
        for (int test = 1; test <= T; ++test) {
            cout << "Case #" << test << ": ";

            int N, M;
            cin >> N >> M;

            vector<pair<int, int> > cities(N, pair<int, int>());
            for (int i = 0; i < N; ++i) {
                cin >> cities[i].first;
                cities[i].second = i;
            }

            vector<vector<int> > edges(N, vector<int>());
            for (int i = 0; i < M; ++i) {
                int u, v;
                cin >> u >> v;
                --u;
                --v;
                edges[u].push_back(v);
                edges[v].push_back(u);
            }

            sort(cities.begin(), cities.end());
            do {
                if (check(cities, edges)) {
                    stringstream ss;
                    for (int i = 0; i < cities.size(); ++i) {
                        ss << cities[i].first;
                    }

                    cout << ss.str() << "\n";
                    break;
                }
            } while (next_permutation(cities.begin(), cities.end()));
        }
    }


    return 0;
}
