#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;

typedef tuple<int, int, int> TUPLE;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    cin >> T;
    rep(t, T) {
        int J, P, S, K;
        cin >> J >> P >> S >> K;

        vector<TUPLE> ans;
        map<TUPLE, int> cnt;    // cnt[(j, p, -1)] = num of (j, p)
        rep(j, J) {
            rep(p, P) {
                rep(s, S) {
                    auto now = make_tuple(j, p, s);
                    if (cnt[make_tuple(j, p, -1)] == K) continue;
                    if (cnt[make_tuple(j, -1, s)] == K) continue;
                    if (cnt[make_tuple(-1, p, s)] == K) continue;

                    ans.emplace_back(now);
                    cnt[make_tuple(j, p, -1)]++;
                    cnt[make_tuple(j, -1, s)]++;
                    cnt[make_tuple(-1, p, s)]++;

                    // cout << j + 1 << " " << p + 1 << " " << s + 1 << endl;
                    // for (auto x : cnt) {
                    //     int jj, pp, ss;
                    //     tie(jj, pp, ss) = x.first;
                    //     cout << jj + 1 << " " << pp + 1 << " " << ss + 1 << " " << x.second << endl;
                    // }
                    // cout << endl;
                }
            }
        }

        cout << "Case #" << t + 1 << ": " << ans.size() << endl;
        for (auto a : ans) {
            int j, p, s;
            tie(j, p, s) = a;
            cout << j + 1 << " " << p + 1 << " " << s + 1 << endl;
        }
    }

}
