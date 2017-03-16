#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <utility>
#include <iomanip>

using namespace std;

typedef long long LL;
template<typename T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<typename T> inline T Sqr(const T& x) { return x * x; }


struct TElem {
    LL Value;
    LL Min;
    LL LowerBound;
    int L;
    int R;
};

const LL inf = 1000000000LL * 1000000000LL;

const int maxn = 1 << 21;

TElem t[2 * maxn];

void Fill(int v, int l, int r) {
    t[v].Value = 0;
    t[v].Min = 0;
    t[v].LowerBound = 0;
    t[v].L = l;
    t[v].R = r;
    if (v < maxn) {
        Fill(v * 2, l, (l + r) / 2);
        Fill(v * 2 + 1, (l + r) / 2 + 1, r);
    }
}

inline LL GetMin(int v) {
    return max(t[v].Min, t[v].LowerBound);
}

void Relax(int v) {
    if (v < maxn) {
        t[v*2].LowerBound = max(t[v*2].LowerBound, t[v].LowerBound);
        t[v*2+1].LowerBound = max(t[v*2+1].LowerBound, t[v].LowerBound);
        t[v].Min = min(GetMin(v*2), GetMin(v*2+1));
    }
}

void SetMin(int v, int l, int r, LL value) {
    if (l <= t[v].L && r >= t[v].R) {
        t[v].LowerBound = max(t[v].LowerBound, value);
    } else if (l > t[v].R || r < t[v].L) {
        return;
    } else {
        Relax(v);
        SetMin(v*2, l, r, value);
        SetMin(v*2+1, l, r, value);
    }
}

LL GetMin(int v, int l, int r) {
    if (l <= t[v].L && r >= t[v].R) {
        return GetMin(v);
    } else if (l > t[v].R || r < t[v].L) {
        return inf;
    } else {
        Relax(v);
        return min(GetMin(v*2, l, r), GetMin(v*2+1, l, r));
    }
}

struct TAttack {
    LL L, R;
    LL S;
};

void Solution() {
    int N;    
    cin >> N;
    vector<LL> coords;
    vector<LL> e(N), w(N), d(N), n(N), s(N), delta_d(N), delta_p(N), delta_s(N);
    map< int, vector< pair<int, int> > > attacks;
    for (int i = 0; i < N; ++i) {
        cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
        for (int j = 0; j < n[i]; ++j) {
            attacks[d[i] + delta_d[i] * j].push_back(make_pair(i, j));
            coords.push_back(w[i] + delta_p[i] * j);
            coords.push_back(e[i] + delta_p[i] * j);
        }
    } 
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    Fill(1, 0, maxn - 1);

    int ans = 0;
    for (map<int, vector<pair<int, int> > >::iterator it = attacks.begin(); it != attacks.end(); ++it) {
        const vector< pair<int, int> >& v = it->second;
        vector<TAttack> all;
        for (int i = 0; i < v.size(); ++i) {
            TAttack a;
            a.L = w[v[i].first] + delta_p[v[i].first] * v[i].second;
            a.R = e[v[i].first] + delta_p[v[i].first] * v[i].second;
            a.S = s[v[i].first] + delta_s[v[i].first] * v[i].second;
            a.L = lower_bound(coords.begin(), coords.end(), a.L) - coords.begin();
            a.R = (lower_bound(coords.begin(), coords.end(), a.R) - coords.begin()) - 1;
            if (a.L <= a.R) {
                all.push_back(a);
            }
        }
        for (int i = 0; i < all.size(); ++i) {
            if (GetMin(1, all[i].L, all[i].R) < all[i].S) {
                ++ans;
            }
        }
        for (int i = 0; i < all.size(); ++i) {
            SetMin(1, all[i].L, all[i].R, all[i].S);
        }
    }    
    cout << ans << endl;
}

void Stupid() {
    vector<int> t1(20000, 0);
    
    int N;    
    cin >> N;
    vector<LL> e(N), w(N), d(N), n(N), s(N), delta_d(N), delta_p(N), delta_s(N);
    map< int, vector< pair<int, int> > > attacks;
    for (int i = 0; i < N; ++i) {
        cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
        w[i] += 10000;
        e[i] += 10000;
        for (int j = 0; j < n[i]; ++j) {
            attacks[d[i] + delta_d[i] * j].push_back(make_pair(i, j));
        }
    } 

    int ans = 0;
    for (map<int, vector<pair<int, int> > >::iterator it = attacks.begin(); it != attacks.end(); ++it) {
        const vector< pair<int, int> >& v = it->second;
        vector<TAttack> all;
        for (int i = 0; i < v.size(); ++i) {
            TAttack a;
            a.L = w[v[i].first] + delta_p[v[i].first] * v[i].second;
            a.R = e[v[i].first] + delta_p[v[i].first] * v[i].second;
            a.S = s[v[i].first] + delta_s[v[i].first] * v[i].second;
            if (a.L <= a.R) {
                all.push_back(a);
            }
        }
        for (int i = 0; i < all.size(); ++i) {
            LL mn = inf;
            for (int j = all[i].L; j < all[i].R; ++j) {
                mn = min<LL>(mn, t1[j]);
            }
            if (mn < all[i].S) {
                ++ans;
            }
        }
        for (int i = 0; i < all.size(); ++i) {
            for (int j = all[i].L; j < all[i].R; ++j) {
                t1[j] = max<LL>(t1[j], all[i].S);
            }
        }
    }    
    cout << ans << endl;
}

struct Timer {
    map<string, float> starts;
    void Tic(const string& name) { starts[name] = clock(); }
    float Toc(const string& name) { return (clock() - starts[name]) / CLOCKS_PER_SEC; }
} timer;

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    timer.Tic("global");
    int testsNumber;
    cin >> testsNumber;
    for (int curTest = 1; curTest <= testsNumber; ++curTest) {
        cout << "Case #" << curTest << ": ";
        cerr << "Case #" << setw(2) << setfill('0') << curTest << ": running...";
        timer.Tic("test");
        Stupid();
        cerr << "done! Elapsed time is " << setprecision(3) << timer.Toc("test") << endl;
    }
    cerr << endl << "Total elapsed time is " << setprecision(3) << timer.Toc("global") << endl;

    return 0;
}
