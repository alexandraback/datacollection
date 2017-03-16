#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define what_is(x) cerr << #x << ": " << x << endl;

#define file "f"

using namespace std;

struct outfit {
    int jacket;
    int pants;
    int shirt;

    outfit(int jacket, int pants, int shirt):
            jacket(jacket),
            pants(pants),
            shirt(shirt) {
    }
};
typedef struct outfit outfit_t;

int T, J, P, S, K;
int mx = 0;

vector<outfit_t> outfits;

bool used[27];
bool used1[27];

int jp_count[3][3];
int ps_count[3][3];
int js_count[3][3];

void check_ans() {
    int loc_mx = 0;
    forn(i, outfits.size()) {
        loc_mx += used[i];
    }

    if (loc_mx > mx) {
        mx = loc_mx;
        forn(i, outfits.size()) {
            used1[i] = used[i];
        }
    }
}

void find_mx(int last) {
    if (last == (int)outfits.size()) {
        check_ans();
        return;
    }

    find_mx(last + 1);
    int i = last + 1;
    if (i == (int)outfits.size())
        return;

        int jacket = outfits[i].jacket;
        int pants = outfits[i].pants;
        int shirt = outfits[i].shirt;

        if (jp_count[jacket][pants] < K &&
                ps_count[pants][shirt] < K &&
                js_count[jacket][shirt] < K) {
            jp_count[jacket][pants]++;
            ps_count[pants][shirt]++;
            js_count[jacket][shirt]++;
            used[i] = true;
            find_mx(i);
            used[i] = false;
            jp_count[jacket][pants]--;
            ps_count[pants][shirt]--;
            js_count[jacket][shirt]--;
        }
}

void solve(void) {
    static int test_case = 0;
    cout << "Case #" << ++test_case << ": ";

    outfits.clear();
    for (int j = 0; j < J; j++) {
        for (int p = 0; p < P; p++) {
            for (int s = 0; s < S; s++) {
                outfits.push_back(outfit_t(j, p, s));
            }
        }
    }

    memset(used1, false, outfits.size());
    memset(used, false, outfits.size());
    mx = 0;

    find_mx(-1);

    cout << mx << "\n";
    forn(i, outfits.size()) {
        if (used1[i])
            cout << outfits[i].jacket + 1 << " " << outfits[i].pants + 1 << " " << outfits[i].shirt + 1 << "\n";
    }
}

int main(void) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin >> T;
    forn(t, T) {
        cin >> J >> P >> S >> K;
        solve();
    }

}
