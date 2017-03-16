#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int mat[10][10];

void run() {
    int n, m;
    cin >> n >> m;
    vector<string> zip(n);
    REP(i,n) cin >> zip[i];
    memset(mat, 0, sizeof(mat));
    REP(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++mat[a][b], ++mat[b][a];
    }

    if (n == 1) {
        cout << zip[0] << endl;
        return;
    }

    vector<int> mm;
    string res = "";
    REP(i,n) mm.push_back(i);
    do {
        int tmp[10][10];
        memcpy(tmp, mat, sizeof(mat));
        string t = "";
        bool valid = true;
        vector<int> que;
        que.push_back(mm[0]);
        REP(i,n) {
            int b = mm[(i + 1) % n];
            bool isok = false;
            RFOR(j,que.size()-1,0) {
                int a = que[j];
                if (tmp[a][b] == 1) {
                    isok = true;
                    break;
                } else {
                    que.pop_back();
                }
            }
            if (!isok) {
                valid = false;
                break;
            }
            t += zip[mm[i]];
            que.push_back(mm[(i + 1) % n]);
        }
        if (!valid) continue;
        if (res == "" || t < res) res = t;
    } while (next_permutation(mm.begin(), mm.end()));

    cout << res << endl;
}

int main() {
    int nk;
    cin >> nk;
    FOR(c,1,nk) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
