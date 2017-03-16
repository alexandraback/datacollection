
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define MAXN 200
#define MAXK 256

using namespace std;

int K, N;
int keys[MAXK];
int needed[MAXN];
vector <int> inside[MAXN];

int reach[1 << 20];

int dfs(int mask) {
    if (mask == (1 << N) - 1)
        return reach[mask] = 1;
    if (reach[mask] != -1)
        return reach[mask];

    int reached = 0;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            continue;
        if (keys[needed[i]] == 0)
            continue;

        keys[needed[i]]--;
        for (int j = 0; j < inside[i].size(); j++)
            keys[inside[i][j]]++;

        reached |= dfs(mask | (1 << i));

        keys[needed[i]]++;
        for (int j = 0; j < inside[i].size(); j++)
            keys[inside[i][j]]--;
    }
    return reach[mask] = reached;
}

const string impossible = "IMPOSSIBLE";

string solve() {
    for (int i = 0; i < (1 << N); i++)
        reach[i] = -1;
    for (int i = 0; i < (1 << N); i++)
        if (reach[i] == -1)
            reach[i] = 0;
    if (!dfs(0))
        return impossible;
    /*
    for (int i = 0; i < (1 << N); i++)
        cout << i << "\t" << reach[i] << endl;
    */

    int mask = 0;
    ostringstream oss;
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (mask & (1 << j))
                continue;
            if (reach[mask | (1 << j)]) {
                mask |= (1 << j);
                oss << (j + 1);
                if (i + 1 < N)
                    oss << ' ';
                found = true;
                break;
            }
        }
        if (!found)
            return impossible;
    }
    return oss.str();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> K >> N;

        for (int i = 0; i < MAXK; i++)
            keys[i] = 0;
        for (int i = 0; i < N; i++)
            inside[i].clear();

        for (int i = 0; i < K; i++) {
            int k;
            cin >> k;
            keys[k]++;
        }
        for (int i = 0; i < N; i++) {
            int num;
            cin >> needed[i] >> num;
            for (int j = 0; j < num; j++) {
                int k;
                cin >> k;
                inside[i].push_back(k);
            }
        }
        cout << "Case #" << t << ": " << solve() << endl;
    }
}

