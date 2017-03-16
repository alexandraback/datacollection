#include <iostream>
#include <map>
#include <vector>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

struct hashf {
    size_t operator()(long long t) const
    {
        return t % 19920613;
    }
};

const int L = 48;

vector<long long> a;
hash_map<long long, long long, hashf> v;
long long ans1, ans2;
bool ans;

void dfs(int h, int k, long long s, long long t)
{
    if (ans) return;
    if (!k) {
        long long &vs = v[s];
        if (!vs)
            vs = t;
        else {
            ans = true;
            ans1 = vs;
            ans2 = t;
            return;
        }
    }
    else
    for (int i = h; i <= L - k; ++i)
        dfs(i + 1, k - 1, s + a[i], t | (1LL << i));
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    int t2, n;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        cin >> n;
        map< int, vector<long long> > f;
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            f[x % 10].push_back(x);
        }
        a.clear();
        for (int i = 0; i < 10; ++i)
            if (f[i].size() > L) {
                for (int j = 0; j < L; ++j)
                    a.push_back(f[i][j]);
                break;
            }
        sort(a.begin(), a.end());
        v.clear();
        ans = false;
        for (int i = 1; i <= L; ++i)
            dfs(0, i, 0, 0);
        printf("Case #%d:\n", t1);
        for (int i = 0; i < L; ++i)
            if ((ans1 & (1LL << i)) && !(ans2 & (1LL << i)))
                cout << " " << a[i];
        printf("\n");
        for (int i = 0; i < L; ++i)
            if ((ans2 & (1LL << i)) && !(ans1 & (1LL << i)))
                cout << " " << a[i];
        printf("\n");
        cerr << t1 << " " << int(ans) << endl;
    }

    return 0;
}
