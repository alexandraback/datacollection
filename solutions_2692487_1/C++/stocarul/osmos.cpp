#include <cstdio>
#include <vector>
#include <algorithm>
#define infile "osmos.in"
#define outfile "osmos.out"
#define ll long long

using namespace std;

vector <int> v;
int n, res;
ll sz;

void read() {
    scanf("%lld %d", &sz, &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
}

void solve() {

    res = v.size();
    sort(v.begin(), v.end());

    int crt = 0;

    for (unsigned i = 0; i < v.size(); ++i) {

        while((ll)v[i] >= sz) {
            sz += sz-1;
            crt++;

            if (crt >= res) {
                break;
            }
        }

        sz += v[i];

        res = min<int>(res, crt + v.size() - i - 1);
    }

}

void write(int t) {
    printf("Case #%d: %d\n", t, res);
    v.clear();
}

int main() {
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; ++i) {
        read();
        solve();
        write(i+1);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
