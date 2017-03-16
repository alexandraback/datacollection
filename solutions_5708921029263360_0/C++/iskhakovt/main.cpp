#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cassert>
#include <map>
#include <set>

int const WAIT = 5;

using namespace std;

typedef unsigned long long ull;

struct Triple {
    int a, b, c;
    Triple(int a, int b, int c) : a(a), b(b), c(c) {}
};

int get(map<pair<int, int>, int> const &dict, int a, int b) {
    auto it = dict.find({a, b});
    return it != dict.end() ? it->second : 0;
}

clock_t start;

vector<Triple> solve(int j, int p, int s, int k) {
    vector<Triple> ret;
    map<pair<int, int>, int> jp, ps, js;
    
    int last_s = 0;
    
    for (int jacket = 0; jacket != j; ++jacket) {
        for (int pants = 0; pants != p; ++pants) {
            int curr_last_s = last_s;
            
            for (int _shirts = 0; _shirts != s; ++_shirts) {
                int shirts = (_shirts + curr_last_s + 1) % s;
                
                int jp_cnt = get(jp, jacket, pants);
                int ps_cnt = get(ps, pants, shirts);
                int js_cnt = get(js, jacket, shirts);
                
                if (jp_cnt != k && ps_cnt != k && js_cnt != k) {
                    ret.push_back(Triple(jacket, pants, shirts));
                    
                    jp[{jacket, pants}] = jp_cnt + 1;
                    ps[{pants, shirts}] = ps_cnt + 1;
                    js[{jacket, shirts}] = js_cnt + 1;
                    
                    last_s = shirts;
                }
            }
        }
    }
    
    return ret;
}

vector<Triple> solve2(int j, int p, int s, int k) {
    vector<Triple> ret;
    map<pair<int, int>, int> jp, ps, js;
    
    for (int jacket = 0; jacket != j; ++jacket) {
        vector<pair<int, int>> used(s);
        for (int i = 0; i != s; ++i) used[i] = {0, i};
        
        for (int pants = 0; pants != p; ++pants) {
            
            sort(used.begin(), used.end());
            
            for (int _shirts = 0; _shirts != s; ++_shirts) {
                int shirts = used[_shirts].second;
                
                int jp_cnt = get(jp, jacket, pants);
                int ps_cnt = get(ps, pants, shirts);
                int js_cnt = get(js, jacket, shirts);
                
                if (jp_cnt != k && ps_cnt != k && js_cnt != k) {
                    ret.push_back(Triple(jacket, pants, shirts));
                    
                    jp[{jacket, pants}] = jp_cnt + 1;
                    ps[{pants, shirts}] = ps_cnt + 1;
                    js[{jacket, shirts}] = js_cnt + 1;
                    
                    ++used[_shirts].first;
                }
            }
        }
    }
    
    return ret;
}

int j, p, s, k;
set<pair<pair<int, int>, int>> all;
map<pair<int, int>, int> jp, ps, js;
vector<Triple> best, local;

void solve_() {
    if (((double)clock() - start) / CLOCKS_PER_SEC > WAIT) {
        return;
    }
    
    for (int jacket = 0; jacket != j; ++jacket) {
        for (int pants = 0; pants != p; ++pants) {
            for (int shirts = 0; shirts != s; ++shirts) {
                
                int jp_cnt = get(jp, jacket, pants);
                int ps_cnt = get(ps, pants, shirts);
                int js_cnt = get(js, jacket, shirts);
                
                if (all.count({{jacket, pants}, shirts})) continue;
                
                if (jp_cnt != k && ps_cnt != k && js_cnt != k) {
                    
                    
                    local.push_back(Triple(jacket, pants, shirts));
                    
                    jp[{jacket, pants}] = jp_cnt + 1;
                    ps[{pants, shirts}] = ps_cnt + 1;
                    js[{jacket, shirts}] = js_cnt + 1;
                    all.insert({{jacket, pants}, shirts});
                    
                    solve_();
                    
                    local.pop_back();
                    
                    jp[{jacket, pants}] = jp_cnt;
                    ps[{pants, shirts}] = ps_cnt;
                    js[{jacket, shirts}] = js_cnt;
                    all.erase({{jacket, pants}, shirts});
                }
            }
        }
    }
    
    if (local.size() > best.size()) {
        best = local;
    }
}

vector<Triple> stupid2(int _j, int _p, int _s, int _k) {
    jp.clear();
    ps.clear();
    js.clear();
    all.clear();
    
    j = _j;
    p = _p;
    s = _s;
    k = _k;
    
    solve_();
    
    return best;
}

vector<Triple> stupid(int j, int p, int s, int k) {
    vector<Triple> ret;
    
    ull all = 1ULL << (ull)(j * p * s);
    
    for (int mask = 0; mask != all; ++mask) {
        if (((double)clock() - start) / CLOCKS_PER_SEC > WAIT) {
            break;
        }
        
        bool ok = true;
        vector<Triple> local;
        map<pair<int, int>, int> jp, ps, js;
        
        for (int jacket = 0; ok && jacket != j; ++jacket) {
            for (int pants = 0; ok && pants != p; ++pants) {
                for (int shirts = 0; ok && shirts != s; ++shirts) {
                    if (!((1ULL << (shirts + pants * s + jacket * p * s)) & mask)) continue;
                    
                    int jp_cnt = get(jp, jacket, pants);
                    int ps_cnt = get(ps, pants, shirts);
                    int js_cnt = get(js, jacket, shirts);
                    
                    if (jp_cnt != k && ps_cnt != k && js_cnt != k) {
                        local.push_back(Triple(jacket, pants, shirts));
                        
                        jp[{jacket, pants}] = jp_cnt + 1;
                        ps[{pants, shirts}] = ps_cnt + 1;
                        js[{jacket, shirts}] = js_cnt + 1;
                    } else {
                        ok = false;
                    }
                }
            }
        }
        
        if (ok && local.size() > ret.size()) {
            ret = local;
        }
    }
    
    return ret;
}

void stress() {
    for (int a = 1; a <= 2; ++a) {
        for (int b = 1; b <= 3; ++b) {
            for (int c = 1; c <= 3; ++c) {
                for (int k = 1; k <= 5; ++k) {
                    int fir = solve(a, b, c, k).size();
                    int sec = stupid(a, b, c, k).size();
                    
                    if (fir != sec) {
                        cout << "WA" << a << ' ' << b << ' ' << c << ' ' << k << ' ' << fir << ' ' << sec << '\n';
                    }
                }
            }
        }
    }
}

int main() {
    //cout << solve(1, 3, 3, 2).size() << '\n';
    
    //stress();
    //return 0;
    
    int tests;
    cin >> tests;
    
    for (int test = 0; test != tests; ++test) {
        //cerr << test + 1 << '\n';
        
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        
        auto res = solve(j, p, s, k);
        auto sec = solve2(j, p, s, k);
        if (sec.size() > res.size()) res = sec;
        
        cout << "Case #" << test + 1 << ": " << res.size() << '\n';
        for (auto const &outfut : res) {
            cout << outfut.a + 1 << ' ' << outfut.b + 1 << ' ' << outfut.c + 1 << '\n';
        }
    }
    
    return 0;
}