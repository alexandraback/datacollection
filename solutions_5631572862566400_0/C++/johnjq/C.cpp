#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
const int MAX_N = 50;

void preprocess() {

}

int v[MAX_N+1];
bool solve(vector<int> x) {
    const int n = x.size();
    sort(x.begin(), x.end());
    do {
        bool okay = true;
        for (int i = 0; i < n; ++i) {
            const int j = i == 0 ? n-1 : i-1;
            const int k = i == n-1 ? 0 : i+1;
            if (x[j] != v[x[i]] && x[k] != v[x[i]]) {
                okay = false;
                break;
            }
        }
        if (okay)
            return true;
    } while (next_permutation(x.begin(), x.end()));
    return false;
}

void process_testcase(const int testcase, const int should_run) {
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
        cin>>v[i];
    if (should_run) {
        printf("Case #%d: ", testcase);
        int ans = 1;
        vector<int> x;
        for (int try_with = n; try_with >= 2; --try_with) {
            for (int stt = (1<<n)-1; stt >= 0; --stt) if (__builtin_popcount(stt) == try_with) {
                x.clear();
                for (int i = 0; i < n; ++i)
                    if (stt & (1<<i))
                        x.push_back(i+1);
                if (solve(x)) {
                    ans = try_with;
                    goto out;
                }
            }
        }
out:
        printf("%d", ans);
        puts("");
    }
}
