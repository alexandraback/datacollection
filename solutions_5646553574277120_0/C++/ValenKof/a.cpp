#include <bits\stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl
#define PATH "C:\\Users\\valenkof\\Desktop\\cpp\\"

template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline int sz(const T& x) { return (int) x.size(); }

// SOLUTION BEGINS HERE


int ans;
vector<int> x;
vector<bool> have_x;
vector<int> take;
int v;

void gen(int current, int taken) {
    if (current == v + 1) {
        int old_size = sz(x);
        copy(all(take), back_inserter(x));
        
        
        vector<bool> curr(v + 1, false);
        int inc_count = 0;
        forn (mask, (1 << sz(x))) {
            int sum = 0;
            forn (i, sz(x)) {
                if (mask & (1 << i)) {
                    sum += x[i];
                }
            }
            if (sum <= v) {
                if (curr[sum] == false) {
                    curr[sum] = true;
                    inc_count++;
                }
            }
        }        
        x.resize(old_size);        
        
        if (inc_count == v + 1) {
            mn(ans, taken);
        }
        
        return;
    }
    
    gen(current + 1, taken);
    if (!have_x[current] && taken + 1 < ans) {
        take.pb(current);
        gen(current + 1, taken + 1);
        take.pop_back();
    }    
}

void solve() {
    int c, d;
    cin >> c >> d >> v;
    have_x.assign(v + 1, false);
    x.resize(d);
    forn (i, d) {
        cin >> x[i];
        have_x[x[i]] = true;
    }
    
    ans = 5;
    take.clear();
    gen(1, 0);
    
    // vector<int> can;
    // debug(d);
    // forn (mask, (1 << d)) {
        // int sum = 0;
        // forn (i, d) {
            // if (mask & (1 << i)) {
                // sum += x[i];
            // }
        // }
        // can.pb(sum);
        // debug(sum);
    // }
    // sort(all(can));
    // can.erase(unique(all(can)), can.end());
    
    // vector<bool> used(v + 1, false);
    // for (int num : can) {
        // if (num <= v) {
            // used[num] = true;
        // }
    // }
    
    
    // vector<int> can_fix;
    
    
    
    
    // bool all_used = true;
    // forn (i, v + 1) {
        // all_used = all_used && used[i];
    // }
    // if (all_used) {
        // cout << 0 << endl;
        // return;
    // }
    
    
    
    cout << ans << endl;
    
}

int main() {
    // freopen(PATH"in.txt", "r", stdin);
    freopen(PATH"C-small-attempt0.in", "r", stdin);
    freopen(PATH"C.txt", "w", stdout);
    int t;
    cin >> t;
    forn (i, t) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
    return 0;
}