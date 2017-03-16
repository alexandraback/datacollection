// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: "Treasure"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define D(x) x

using namespace std;

struct instance {
    int N;

    vector<int> type_required;
    vector<map<int, int> > types_contained;
    map<int, int> initial_keys;

    instance(int N) : N(N), type_required(N), types_contained(N) { }

    vector<int> solve() const;
    bool dfs(int opened, map<int, int>& keys_available, vector<int>& path, vector<bool>& visited) const;
};

vector<int> instance::solve() const {
    int opened = 0;
    map<int, int> keys_available = initial_keys;
    vector<int> path;
    vector<bool> visited(1<<N);

    dfs(opened, keys_available, path, visited);
    return path;
}

void add_map(map<int, int>& target, const map<int, int>& source, int multiplier) {
    for (map<int, int>::const_iterator it = source.begin(); it != source.end(); it++) {
        target[it->first] += it->second * multiplier;
    }
}

bool instance::dfs(int opened, map<int, int>& keys_available, vector<int>& path, vector<bool>& visited) const {
    if (visited[opened]) {
        // we've been in this state before, so the result must have been "false"
        return false;
    }
    visited[opened] = true;

    bool some_unopened = false;

    for (int i = 0, bitmask = 1; i < N; i++, bitmask <<= 1) {
        if (opened & bitmask) continue;
        some_unopened = true;

        if (keys_available[type_required[i]] == 0) continue;

        // recursive descent
        const int next_opened = opened | bitmask;
        keys_available[type_required[i]]--;
        add_map(keys_available, types_contained[i], 1);
        path.push_back(i);

        if (dfs(next_opened, keys_available, path, visited)) {
            // we found a solution, just return right away
            return true;
        }

        // otherwise backtrack
        keys_available[type_required[i]]++;
        add_map(keys_available, types_contained[i], -1);
        path.pop_back();
    }

    // were there any unopened chests? if not, we're done
    return !some_unopened;
}

// note that we convert keys/chests from 1-based to 0-based indexing on I/O

istream& read_keys(istream& in, map<int, int>& keys, int count) {
    for (int i = 0; i < count; i++) {
        int type;
        in >> type;
        keys[type-1]++;
    }
    return in;
}

int main() {
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++) {
        int N, K;
        cin >> K >> N;

        instance inst(N);
        read_keys(cin, inst.initial_keys, K);

        for (int i = 0; i < N; i++) {
            int Ki;
            cin >> inst.type_required[i] >> Ki;
            inst.type_required[i]--;
            read_keys(cin, inst.types_contained[i], Ki);
        }

        vector<int> path = inst.solve();

        cout << "Case #" << testCase << ": ";
        if (path.empty()) {
            cout << "IMPOSSIBLE";
        } else {
            for (int i = 0; i < path.size(); i++) {
                if (i > 0) cout << " ";
                cout << path[i]+1;
            }
        }
        cout << endl;
    }
}
