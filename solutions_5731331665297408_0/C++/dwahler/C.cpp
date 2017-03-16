// CPPFLAGS=-std=gnu++11 -O3

#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <cstdlib>
#include <string>
#include <cstdint>

#define D(x)

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int T = 1; T <= numCases; T++) {
        int N, M;
        cin >> N >> M;

        vector<int> zips(N);
        for (int i = 0; i < N; i++) {
            cin >> zips[i];
        }

        map<int, set<int> > edges;
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            x = zips[x-1];
            y = zips[y-1];
            edges[x].insert(y);
            edges[y].insert(x);
        }

        vector<int> path = zips;
        sort(path.begin(), path.end());

        do {
            stack<int> pending;
            pending.push(path[0]);

            for (int i = 1; i < N; i++) {
                int next = path[i];
                D(cerr << "trying to go from " << pending.top() << " to " << next << endl);
                while (!pending.empty() && edges[pending.top()].find(next) == edges[pending.top()].end()) {
                    D(cerr << "popping " << pending.top() << endl);
                    pending.pop();
                }
                if (pending.empty()) {
                    D(cerr << "abort" << endl);
                    break;
                }
                D(cerr << "traveling from " << pending.top() << endl);
                pending.push(next);
            }
            if (!pending.empty()) break;
        } while (next_permutation(path.begin(), path.end()));

        cout << "Case #" << T << ": ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
        }
        cout << endl;
    }
}
