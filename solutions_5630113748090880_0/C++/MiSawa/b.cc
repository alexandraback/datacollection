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

void solve(){
    int n;
    vector<vector<int>> vs;
    const int case_id = GCJ::get_input([&]{
        cin >> n;
        rep(_, 2 * n - 1){
            vector<int> tmp(n);
            rep(i, n) cin >> tmp[i];
            vs.emplace_back(tmp);
        }
    });
    auto bck = vs;
    sort(all(vs));
    vector<int> res;
    for(int c = 0; res.size() < n; ++c){
        sort(begin(vs), end(vs), [&](const vector<int> &a, const vector<int> &b){
            return tie(a[c], b) > tie(b[c], a); });
        if(vs.size() == 1 or vs.back()[c] != vs[vs.size()-2][c]){
            res.emplace_back(vs.back()[c]);
            vs.pop_back();
        }else{
            vector<int> a = vs.back(); vs.pop_back();
            vector<int> b = vs.back(); vs.pop_back();
            multiset<int> ms;
            rep(k, n) ms.emplace(a[k]);
            rep(k, n) ms.emplace(b[k]);
            rep(k, 2*n-1) ms.erase(ms.find(bck[k][c]));
            assert(ms.size() == 1);
            res.emplace_back(*ms.begin());
        }
    }

    GCJ::queue_output(case_id, [=]{
        int first = true;
        for(auto &x : res){
            if(!first) cout << " ";
            first = false;
            cout << x;
        }
        cout << endl;
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
