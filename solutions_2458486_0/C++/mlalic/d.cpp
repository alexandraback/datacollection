#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

struct Key {
    int type;
    int id;
    Key(int type, int id) : type(type), id(id) { }
    Key() : type(-1), id(-1) { }
};

int keysInPossession[201];
int chestTypes[21];
vector<vector<Key> > keysInChest;
int totalChests;
int totalKeys;
vector<int> path;

int allChestsPattern = 0;

map<pair<int, long long>, bool> memo;
bool solve(int chests, long long keys) {
    if (memo.find(make_pair(chests, keys)) != memo.end()) {
        return memo[make_pair(chests, keys)];
    }
    if (chests == allChestsPattern) {
        memo[make_pair(chests, keys)] = true;
        return true;
    }

    for (int i = 0; i < totalChests; ++i) {
        if (!(chests & (1 << i))) {
            // Do we have the matching key?
            if (keysInPossession[chestTypes[i]] > 0) {
                // Use one of them
                --keysInPossession[chestTypes[i]];
                // Mark the chest opened
                chests |= (1 << i);
                path.push_back(i);
                // Take all the keys from the chest
                int newKeysPattern = 0;
                for (int k = 0; k < keysInChest[i].size(); ++k) {
                    ++keysInPossession[keysInChest[i][k].type];
                    newKeysPattern |= (1 << keysInChest[i][k].id);
                }
                keys |= newKeysPattern;

                //cout << "Taking chest " << i << endl;

                if (solve(chests, keys)) {
                    return true;
                }

                // Backtrack
                keys &= ~newKeysPattern;
                for (int k = 0; k < keysInChest[i].size(); ++k) {
                    --keysInPossession[keysInChest[i][k].type];
                }
                path.pop_back();
                chests &= ~(1 << i);
                ++keysInPossession[chestTypes[i]];
            }
        }
    }

    memo[make_pair(chests, keys)] = false;
    return false;
}

void reconstruct() {
    cout << path[0] + 1;
    for (int i = 1; i < path.size(); ++i) {
        cout << " " << path[i] + 1;
    }
}

int main() {
    int tn;
    cin >> tn;
    for (int tt = 1; tt <= tn; ++tt) {
        int k, n;
        cin >> k >> n;

        memset(keysInPossession, 0, sizeof keysInPossession);
        memo.clear();
        keysInChest.clear();
        keysInChest.resize(n);
        totalChests = n;
        totalKeys = 0;
        path.clear();

        int keysTypeCount[201];
        memset(keysTypeCount, 0, sizeof keysTypeCount);

        for (int i = 0; i < k; ++i) {
            int key;
            cin >> key;
            ++keysInPossession[key];
            ++keysTypeCount[key];
        }


        for (int i = 0; i < n; ++i) {
            int type, totalKeysInChest;
            cin >> type >> totalKeysInChest;
            chestTypes[i] = type;
            for (int j = 0; j < totalKeysInChest; ++j) {
                int kk; cin >> kk;
                keysInChest[i].push_back(Key(kk, totalKeys));
                ++totalKeys;
                ++keysTypeCount[kk];
            }
        }

        int chestTypeCount[201];
        memset(chestTypeCount, 0, sizeof chestTypeCount);
        for (int i = 0; i < totalChests; ++i) {
            ++chestTypeCount[chestTypes[i]];
        }
        bool impossible = false;
        for (int i = 1; i <= 200; ++i) {
            if (chestTypeCount[i] > keysTypeCount[i]) {
                impossible = true;
            }
        }

        allChestsPattern = 0;
        for (int i = 0; i < n; ++i) {
            allChestsPattern |= (1 << i);
        }

        cout << "Case #" << tt << ": ";
        if (impossible) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        if (solve(0, 0)) {
            reconstruct(); cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}

