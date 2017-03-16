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

#define foreach(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int cb(int x)
{
    int ret = 0;
    while (x) {
        ret++;
        x &= (x-1);
    }
    return ret;
}

int solve(const VI& next)
{
    int n = next.size();
    int best = 0;
    for (int i = 0; i < (1 << n); i++) {
        int r = cb(i);
        if (r <= best || r < 2)
            continue;
        VI a;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                a.push_back(j);
        }

        do {
            bool good = true;
            for (int j = 0; j < r; j++) {
                int bff = next[a[j]];
                if (a[(j+1) % r] != bff && a[(j+r-1) % r] != bff) {
                    good = false;
                    break;
                }
            }
            if (good) {
                best = r;
                foreach (it, a)
                    cerr << ((*it) + 1) << ' ';
                cerr << endl;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));

    }
    return best;
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
