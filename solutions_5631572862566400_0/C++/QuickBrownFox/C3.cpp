#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

mutex mtx;

struct Parameters {
    int n;
    int graph[11][11];
    int res;
    void get() {
        n = getint();
        for (int i = 0; i < n; ++i) {
            int to = getint() - 1;
            graph[i][to] = 1;
        }
    }
    void put(int test_case) {
        printf("Case #%d: ", test_case);
        cout << res << endl;
    }
};

struct CaseSolver {
    int graph[11][11];
    void solve(Parameters& par) {
        int i, j;
        int n = par.n;
        for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) graph[i][j] = par.graph[i][j];
        int res = 0;
        for (int h = 0; h < 1 << n; ++h) {
            int t = __builtin_popcount(h);
            if (t <= res) continue;
            vector<int> order;
            for (int i = 0; i < n; ++i) if (h >> i & 1) order.push_back(i);
            do {
                int ok = 1;
                for (int i = 0; i < order.size(); ++i) {
                    int who = order[i];
                    int pre = order[(i - 1 + order.size()) % order.size()];
                    int aft = order[(i + 1) % order.size()];
                    if (graph[who][pre] or graph[who][aft]) continue;
                    ok = 0;
                    break;
                }
                if (ok) { res = t; break; }
            } while (next_permutation(order.begin(), order.end()));
        }
        par.res = res;

        return;
    }
    void set(vector<Parameters>& pars, int& case_count) {
        unique_lock<mutex> lck(mtx);
        if (case_count >= (int)pars.size()) return;
        Parameters& par = pars[case_count];
        cerr << " case : " << case_count << " run in " << this_thread::get_id() << endl;
        case_count++;
        lck.unlock();
        solve(par);
        set(pars, case_count);
    }
};

int main () {
    const int test_case = getint();
    const int thread_count = thread::hardware_concurrency();
    cerr << "number of threads = " << thread_count << endl;
    vector<Parameters> pars(test_case);
    vector<CaseSolver> sols(thread_count);
    for (auto& p: pars) p.get();
    int case_count = 0;
    vector<thread> threads(thread_count);
    for (int i = 0; i < thread_count; i++) {
        threads[i] = thread(&CaseSolver::set, &sols[i], ref(pars), ref(case_count));
    }
    for (auto& t: threads) if (t.joinable()) t.join();
    for (int i = 0; i < test_case; i++) pars[i].put(i + 1);
    return 0;
}
