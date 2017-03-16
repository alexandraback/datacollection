#include <bits/stdtr1c++.h>
#define FILE "B-small-attempt0"
#define MAXN 1005


using namespace std;

long long a, b, k;

set<pair<long long, long long> > w;

int main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);

    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;

    for(int t1 = 1; t1 <= t; ++t1) {
        w.clear();

        cin >> a >> b >> k;

        cout << "Case #" << t1 << ": ";

        for(long long i = 0; i < a; ++i)
            for(long long j = 0; j < b; ++j)
                if((i & j) < k)
                    w.insert(make_pair(i, j));

        cout << w.size() << '\n';
    }

}
