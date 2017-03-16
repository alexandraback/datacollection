#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int k, n, start_key[200], chest_key[200];
vector<int> key[200];
bool f[1048576];
vector<int> status[21];
vector<int> path[1048576];

bool isValid(int st, int next_step) {
    //cout << "isValid " << st << " " << next_step << endl;
    int cnt[200];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < k; i++) {
        cnt[start_key[i]]++;
    }
    for (int i = 0; i < path[st].size(); i++) {
        int x = path[st][i];
        for (int j = 0; j < key[x].size(); j++) {
            cnt[key[x][j]]++;
        }
        cnt[chest_key[x]]--;
    }
    return cnt[chest_key[next_step]] > 0;
}

bool compare(int cur_st, int next_step, int next_st) {
    for (int i = 0; i < path[cur_st].size(); i++) {
        if (path[cur_st][i] != path[next_st][i]) {
            return path[cur_st][i] < path[next_st][i];
        }
    }
    return false;
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("d_out.txt", "w", stdout);
    
    int t;
    cin >> t;
    for (int task = 1; task <= t; task++) {
        cin >> k >> n;
        for (int i = 0; i <= n; i++) {
            status[i].clear();
        }
        // initialize status   
        for (int st = 0; st < (1 << n); st++) {
            int tmp = st, cnt = 0;
            while (tmp) {
                cnt += (tmp & 1);
                tmp >>= 1;
            }
            status[cnt].push_back(st);
            path[st].clear();
        }
        for (int i = 0; i < k; i++) {
            cin >> start_key[i];
        }
        for (int i = 0; i < n; i++) {
            int tot;
            cin >> chest_key[i] >> tot;
            key[i].clear();
            for (int j = 0; j < tot; j++) {
                int number;
                cin >> number;
                key[i].push_back(number);
            }
        }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 0; i <= n - 1; i++) {
            /*
            cout << "tot=" << i << " ";
            for (int index = 0; index < status[i].size(); index++) {
                cout << status[i][index] << " ";
            }
            cout << endl;
            */
            for (int index = 0; index < status[i].size(); index++) {
                int cur_st = status[i][index];
                if (f[cur_st]) {
                    for (int j = 0; j < n; j++) {
                        if ((cur_st & (1 << j)) == 0 && isValid(cur_st, j)) {
                            int next_st = cur_st | (1 << j);
                            //cout << cur_st << " next " << next_st << endl;
                            if (!f[next_st] || (f[next_st] && compare(cur_st, j, next_st))) {
                                path[next_st].resize(path[cur_st].size());
                                memcpy(&path[next_st][0], &path[cur_st][0], sizeof(int) * path[cur_st].size());
                                path[next_st].push_back(j);
                            }
                            f[next_st] = 1;
                        }
                    }
                }
            }
        }
        if (f[(1 << n) - 1]) {
            cout << "Case #" << task << ":";
            for (int i = 0; i < path[(1 << n) - 1].size(); i++) {
                cout << " " << path[(1 << n) - 1][i] + 1;
            }
            cout << endl;
        } else {
            cout << "Case #" << task << ": IMPOSSIBLE" << endl;
        }   
    }
    
    return 0;
}
