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
// tr << ( vector, map, pair, tuple, etc... ) << endl//{{{
template <typename T, typename U>
struct sfinae_helper{typedef void type;};
template <typename T, typename U = void>
struct Print{ static ostream &pp(ostream &os, const T &x){ return os << x; } };
struct trace{//{{{
    ostream& os;
    trace(ostream& os): os(os) { }
    template<typename T>
        trace& operator<<(const T& x){ Print<T>::pp(os, x); return *this;}
    trace &operator<<(ostream& f(ostream&)){ f(os); return *this; }
    operator ostream &(){ return os; }
} tr(cout);//}}}
// string//{{{
template <> struct Print<string, void>{ static ostream &pp(ostream &os, const string &x){ return os << x; } };
//}}}
// Container//{{{
template <typename T> struct Print<T, typename sfinae_helper<T, typename T::iterator>::type>{
    static ostream &pp(ostream &os, const T &v){
        trace(os) << '[';
        for(const auto &x : v) trace(os) << x << ", ";
        return trace(os) << ']';
    }
};//}}}
// Pair//{{{
template <typename T> struct Print<T, typename sfinae_helper<T, typename T::first_type>::type>{
    static ostream &pp(ostream &os, const T &x){
        return trace(os) << '(' << x.first << ", " << x.second << ')';
    }
};//}}}
// Tuple//{{{
template<class T, size_t N> struct TuplePrint{
    static ostream &print(ostream &os, const T &x){
        TuplePrint<T, N-1>::print(os, x) << ", ";
        return trace(os) << get<N-1>(x);
        //return Print<decltype(get<N-1>(x))>::pp(os, get<N-1>(x));
    }
};
template<class T> struct TuplePrint<T, 1>{
    static ostream &print(ostream &os, const T &x){
        return trace(os) << get<0>(x);
    }
};
template <typename... Args>//Tuple
struct Print<tuple<Args...>>{
    static ostream &pp(ostream &os, const tuple<Args...> &x){
        os << "(";
        return TuplePrint<decltype(x), sizeof...(Args)>::print(os, x) << ")";
    }
};//}}}
//}}}


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
    const int case_id = GCJ::get_input([&]{
        cin >> n;
        f.resize(n);
        rep(i, n) cin >> f[i];
        rep(i, n) --f[i];
    });

    vector<int> v(n);
    iota(begin(v), end(v), 0);
    int res = 0;
    do{
        REP(k, 1, n+1){
            bool ng = false;
            rep(i, k) if(v[(i+1)%k] != f[v[i]] and v[(i+k-1)%k] != f[v[i]]) ng = true;
            if(!ng) chmax(res, k);
        }
    }while(next_permutation(all(v)));

    GCJ::queue_output(case_id, [=]{
        cout << res << endl;
    });
}

signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    const int max_thread = 4;
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
