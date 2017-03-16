#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector <int> type;
vector <vector <int> > keys;
vector <int> init;
int n, k;

vector <int> used;
vector <vector <int> > best_path;
const vector <int> max_path(1, 999999);

queue<int> q;

void load()
{
    cin >> k >> n;
    type.resize(n);
    keys.clear();
    keys.resize(n);
    init.resize(k);

    used.clear();
    used.resize(1 << n);
    best_path.clear();
    best_path.resize(1 << n, max_path);
    best_path[0].clear();

    for (int i = 0; i < k; ++i) {
        cin >> init[i];
    }
    for (int i = 0; i < n; ++i) {
        int len = 0;
        cin >> type[i] >> len;
        keys[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> keys[i][j];
        }
    }
}

inline bool vec_cmp(const vector <int>& v1, const vector <int>& v2)
{
    int len = min(v1.size(), v2.size());
    for (int i = 0; i < len; ++i) {
        if (v1[i] != v2[i]) {
            return v1[i] < v2[i];
        }
    }
    return v1.size() < v2.size();
}

void process(int mask)
{
    map <int, int> amount;
    for (int i = 0; i < init.size(); ++i) {
        amount[init[i]]++;
    }
    for (int v = 0; v < n; ++v) {
        if (mask & (1 << v)) {
            for (int i = 0; i < keys[v].size(); ++i) {
                amount[keys[v][i]]++;
            }
            amount[type[v]]--;
        }
    }
    for (int v = 0; v < n; ++v) {
        if ((mask & (1 << v)) == 0) {
            if (amount[type[v]] <= 0) {
                continue;
            }
            vector <int> path = best_path[mask];
            path.push_back(v);
            if (vec_cmp(path, best_path[mask | (1 << v)])) {
                best_path[mask | (1 << v)] = path;
            }
        }
    }
}

int main()
{
    int TEST = 0;
    cin >> TEST;
    for (int test = 1; test <= TEST; ++test) {
        cout << "Case #" << test << ": ";
        load();
        for (int v = 0; v < (1 << n); ++v) {
            process(v);
        }
        
        if (vec_cmp(best_path[(1 << n) - 1], max_path) == false) {
            cout << "IMPOSSIBLE" << endl;
        } else {    
            for (int i = 0; i < n; ++i) {
                cout << best_path[(1 << n) - 1][i] + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}