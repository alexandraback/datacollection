#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int get(unordered_map<int, int> &occ, int num) {
    if (occ.find(num) == occ.end()) {
        occ[num] = 0;
    }

    return occ[num];
}


vector<vector<int>> pos;
vector<vector<int>> res;
unordered_map<int, int> occ;
bool select[64] = {false};
int rescnt = 0;
void dfs(int num, int bound, int cnt, int K) {
    if (num == bound) {
        if (cnt > rescnt) {
            rescnt = cnt;
            res.clear();
            for (int i = 0; i < bound; i++) {
                if (select[i]) {
                    res.push_back(pos[i]);
                }
            }
        }
        return;
    } else {
        int j = pos[num][0];
        int p = pos[num][1];
        int s = pos[num][2];
        if (get(occ, j * 1000000 + p * 10000) < K &&
            get(occ, j * 1000000 + s) < K &&
            get(occ, p * 10000 + s) < K) {
            occ[j * 1000000 + p * 10000] = occ[j * 1000000 + p * 10000] + 1;
            occ[p * 10000 + s] = occ[p * 10000 + s] + 1;
            occ[j * 1000000 + s] = occ[j * 1000000 + s] + 1;
            select[num] = true;

            dfs(num + 1, bound, cnt + 1, K);
            
            occ[j * 1000000 + p * 10000] = occ[j * 1000000 + p * 10000] - 1;
            occ[p * 10000 + s] = occ[p * 10000 + s] - 1;
            occ[j * 1000000 + s] = occ[j * 1000000 + s] - 1;
            select[num] = false;
        }

        dfs(num + 1, bound, cnt, K);
    }
}

int main(int argc, char *argv[])
{
    int T = 0;
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        int J = 0, P = 0, S = 0;
        int K = 0;
        cin >> J >> P >> S >> K;
        int label[32] = {0};
        for (int i = 0; i < J; i++) {
            label[i] = i;
        }
        for (int i = J; i < J + P; i++) {
            label[i] = i - J;
        }
        for (int i = J + P; i < J + P + S; i++) {
            label[i] = i - J - P;
        }

        pos.clear();
        for (int i = 0; i < J; i++) {
            for (int j = J; j < J + P; j++) {
                for (int k = J + P; k < J + P + S; k++) {
                    vector <int> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    pos.push_back(v);
                }
            }
        }

        if (K >= S) {
            res = pos;
        } else {
            memset(select, false, sizeof(select));
            rescnt = 0;
            occ.clear();
            dfs(0, pos.size(), 0, K);
        }
        cout << "Case #" << cas << ": " << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << label[res[i][0]] + 1 << " " << label[res[i][1]] + 1 << " " << label[res[i][2]] + 1 << endl;
        }
    }
    return 0;
}

    
