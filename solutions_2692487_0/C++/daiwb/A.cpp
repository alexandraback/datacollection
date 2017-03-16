#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

int A, N;
int mm[15];
int ret;

void dfs(int idx, int cur, int cost) {
    if (cost >= ret) return;

    if (idx == N) {
        ret = cost;
        return;
    }
    
    if (cur > mm[idx]) {
        dfs(idx + 1, cur + mm[idx], cost);
        return;
    }

    dfs(idx + 1, cur, cost + 1);

    if (cur > 1) {
        int tmp = cur, num = cost;
        while (true) {
            tmp += tmp - 1;
            ++num;
            if (tmp > mm[idx]) {
                dfs(idx + 1, tmp + mm[idx], num);
                break;
            }
        }
    }
}

void run() {
    cin >> A >> N;
    REP(i,N) cin >> mm[i];
    sort(mm, mm + N);
    ret = N;
    dfs(0, A, 0);
    cout << ret << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
