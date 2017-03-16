#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int solve(const VI& next)
{
    int n = next.size();
    VI rec(n*n, 0);
    int best = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> used(n);
        int j = i;
        int ret = 0;
        int prev = i, prev2;
        while (true) {
            prev2 = prev;
            prev = j;
            ret++;
            used[j] = true;
            j = next[j];
            if (used[j]) {
                if (j == prev2) {
                    int id = prev2 * n + prev;
                    //int rid = prev * n + prev2;
                    rec[id] = max(rec[id], ret);
                } else if (j == i) {
                    best = max(best, ret);
                }
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            int id = i * n + j;
            int rid = j * n + i;
            assert(rec[id] == 0 && rec[rid] == 0 || rec[id] >= 2 && rec[rid] >= 2);
            sum += max(0, rec[id] + rec[rid] - 2);
        }
    return max(best, sum);
}

int main(int argc, const char* argv[]) {
    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        VI a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            a[i]--;
        }
        cout << "Case #" << t << ": " << solve(a) << endl;
    }
    return 0;
}
