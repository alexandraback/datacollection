#include <bits/stdc++.h>
namespace GCJ{//{{{
    std::mutex log_mutex;
    struct {
        using Entry = std::pair<int, std::function<void(void)>>;
        std::vector<Entry> queue;
        void emplace_back(int case_id, std::function<void(void)> f){
            static std::mutex output_mutex;
            std::lock_guard<std::mutex> lock(output_mutex);
            queue.emplace_back(case_id, f);

            log_mutex.lock();
            // std::cerr << "output " << case_id << std::endl;
            log_mutex.unlock();
        }
        void output(){
            std::sort(std::begin(queue), std::end(queue), [](const Entry &a, const Entry &b){
                    return a.first < b.first;
                    });
            for(auto &e : queue){
                const int id = e.first;
                std::cout << "Case #" << id << ": ";
                // std::cout << "Case #" << id << ":" << std::endl;
                e.second();
            }
            queue.clear();
        }
    } output_queue;

    template<class F>
    int get_input(F func){
        static std::mutex input_mutex;
        static int current_casenum = 0;

        input_mutex.lock();
        const int case_id = ++current_casenum;
        func();
        input_mutex.unlock();

        log_mutex.lock();
        // std::cerr << "input " << case_id << std::endl;
        log_mutex.unlock();

        return case_id;
    }
    template<class F>
    void queue_output(const int case_id, F func){
        output_queue.emplace_back(case_id, func);
    }
}//}}}

#include <gmpxx.h>
using ZZ = mpz_class;
using QQ = mpq_class;

#define all(x) begin(x),end(x)
#define rall(x) (x).rbegin(),(x).rend()
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define repsz(i,v) rep(i,(v).size())
#define aur auto&
#define bit(n) (1LL<<(n))
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second

using namespace std;
typedef long long ll;
//#define int long long
template<class C>int size(const C &c){ return c.size(); }
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}

struct UnionFind{ //{{{
    vector<int> par;
    int n, cnt;
    UnionFind(const int &x=0){init(x);}
    void init(const int &x){par.assign(cnt = n = x, -1);}
    inline int find(const int &x){ return par[x]<0 ? x : par[x] = find(par[x]); }
    inline bool same(const int &x, const int &y){ return find(x) == find(y); }
    inline bool unite(int x, int y){
        if((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline int count() const { return cnt; }
    inline int count(int x){ return -par[find(x)]; }
};
//}}}

template<typename T> struct Zipper{//{{{
    map<T, int> zip;
    vector<T> unzip;
    template<typename It> inline void add(It b, It e){ while(b != e) add(*b++); }
    inline void add(const T &x){//{{{
        if(zip.count(x)) return;
        zip[x] = unzip.size();
        unzip.emplace_back(x);
    }//}}}
    inline void compile(){//{{{
        int i = 0;
        for(auto &x : zip) unzip[x.second = i++] = x.first;
    }//}}}
    inline const int operator[](const T &x){//{{{
        add(x);
        return zip[x];
    }//}}}
    inline const T operator()(const int &i) const { return unzip[i]; }
    inline int size() const { return zip.size(); }
    typename vector<T>::const_iterator begin(){ return unzip.begin(); }
    typename vector<T>::const_iterator end(){ return unzip.end(); }
    T ub1(T x){ return zip.upper_bound(x)->first; }
    T lb1(T x){ return zip.lower_bound(x)->first; }
    T ub2(T x){ return zip.upper_bound(x)->second; }
    T lb2(T x){ return zip.lower_bound(x)->second; }
};//}}}

int max_depth(int u, int p, vector<vector<int>> &g){
    int res = 0;
    for(auto &v : g[u]) if(v-p) chmax(res, max_depth(v, u, g));
    return res + 1;
}

void solve(){
    int n;
    vector<int> f;
    vector<vector<int>> ggg;
    const int case_id = GCJ::get_input([&]{
        cin >> n;
        f.resize(n);
        ggg.resize(n);
        rep(i, n) cin >> f[i];
        rep(i, n) --f[i];
        rep(i, n) ggg[f[i]].emplace_back(i);
    });
    UnionFind uf(n);
    UnionFind alluf(n);
    rep(u, n) alluf.unite(u, f[u]);
    rep(u, n){
        vector<int> used(n);
        for(int v = u; ; v = f[v]){
            if(used[v] && v == u){
                rep(i, n) if(used[i]) uf.unite(i, f[i]);
                break;
            }
            if(used[v]) break;
            used[v] = true;
        }
    }
    Zipper<int> zip;
    rep(u, n) if(uf.find(u) == u) zip.add(u);
    vector<vector<int>> g(zip.size());
    rep(u, n) if(uf.find(u) != uf.find(f[u])) g[zip[uf.find(f[u])]].emplace_back(zip[uf.find(u)]);
    vector<int> weight(zip.size());
    rep(u, n) ++weight[zip[uf.find(u)]];
    int res = 0;
    repsz(i, g) chmax(res, weight[i]);

    vector<int> max_paths(n);

    vector<int> paths;
    repsz(u, g) if(weight[u] == 2){
        vector<int> us;
        rep(i, n) if(zip[uf.find(i)] == u) us.emplace_back(i);
        int m0 = 1, m1 = 1;
        for(auto &c : ggg[us[0]]) if(uf.find(c) != uf.find(us[0]))
            chmax(m0, 1 + max_depth(zip[uf.find(c)], u, g));
        for(auto &c : ggg[us[1]]) if(uf.find(c) != uf.find(us[1]))
            chmax(m1, 1 + max_depth(zip[uf.find(c)], u, g));
        chmax(max_paths[alluf.find(us[0])], m0 + m1);
    }
    chmax(res, accumulate(all(max_paths), 0));
    GCJ::queue_output(case_id, [=]{
        cout << res << endl;
    });
}

signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    const int max_thread = 1;
    int T; cin >> T;
    for(int i = 0; i < T; i += max_thread){
        const int K = min(T - i, max_thread);
        std::vector<std::thread> threads(K);
        for(auto &th : threads) th = std::thread(solve);
        for(auto &th : threads) th.join();
        GCJ::output_queue.output();
    }
    return 0;
}
// vim:set foldmethod=marker commentstring=//%s:
