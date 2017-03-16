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

const int INF = 1000;

int get_max_num(string keyboard, string goal, int s) {
    set<char> used;
    for (char c : keyboard) {
        used.insert(c);
    }
    for (char c : goal) {
        if (!used.count(c)) {
            return 0;
        }
    }
    int large = 0;
    for (int check = sz(goal) - 1; check > 0; --check) {
        bool same = true;
        for (int i = 0; i < check; ++i) {
            if (goal[i] != goal[sz(goal) - check + i]) {
                same = false;
                break;
            }
        }
        if (same) {
            large = check;
            break;
        }
    }
    int len = sz(goal);
    int ans = 1;
    while (len + sz(goal) - large <= s) {
        len += sz(goal) - large;
        ans += 1;
    }
    return ans;
}

int calc_go(const string& goal, const string& have) {
    for (int suffix = min(sz(goal), sz(have)); suffix > 0; --suffix) {
        bool same = true;
        forn (i, suffix) {
            if (goal[i] != have[sz(have) - suffix + i]) {
                same = false;
                break;
            }
        }
        if (same) {
            return suffix;
        }
    }
    return 0;
}

void solve() {
    int k, l, s;
    cin >> k >> l >> s;
    string keyboard;
    cin >> keyboard;
    string goal;
    cin >> goal;
    
    int max_num = get_max_num(keyboard, goal, s);

    map<char, int> used;
    for (char c : keyboard) {
        used[c]++;
    }    
    
    const long double ONE = 1;
    
    vector<vector<int   >> go_stat(l + 1, vector<int>(sz(used)));
    vector<long double> go_prop;
    for (auto p : used) {
        go_prop.pb(ONE * p.second / k);
    }

    for (int old = 0; old <= l; ++old) {
        int index = 0;
        for (auto p : used) {            
            string curr = goal.substr(0, old);
            curr += p.first;
            go_stat[old][index] = calc_go(goal, curr);
            index++;
        }
    }

    
    
    const long double ZERO = 0;
    vector<vector<vector<long double>>> dp(s + 1, 
        vector<vector<long double>>(max_num + 1,
            vector<long double>(l + 1, ZERO)));
    dp[0][0][0] = 1;
    forn (len, s) {
        forn (collected, max_num + 1) {
            forn (suffix, l + 1) {
                long double curr = dp[len][collected][suffix];
                if (curr == ZERO) continue;
                forn (i, sz(go_prop)) {
                    int next_suffix = go_stat[suffix][i];
                    int next_collected = collected + (next_suffix == l);
                    dp[len + 1][next_collected][next_suffix] += curr * go_prop[i];                    
                }                
            }
        }
    }
    
    // debug(max_num);
    
    long double ans = 0.0;
    forn (collected, max_num + 1) {
        forn (suffix, l + 1) {
            
            // debug(collected);
            // debug(suffix);
            // debug((double) dp[s][collected][suffix]);
            
            
            ans += dp[s][collected][suffix] * (max_num - collected);
        }
    }
    
 
    // debug(max_num);
    // if (max_num == 0) {
        cout << fixed << setprecision(12) << (double) ans << endl;
        // return;
    // }
    // cout << endl;
}

int main() {
    // freopen(PATH"in.txt", "r", stdin);
    freopen(PATH"B-small-attempt0.in", "r", stdin);
    freopen(PATH"B.txt", "w", stdout);
    int t;
    cin >> t;
    forn (i, t) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
    return 0;
}