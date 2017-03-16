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
            std::cerr << "output " << case_id << std::endl;
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
        std::cerr << "input " << case_id << std::endl;
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

void solve(){
    int K, c, s;
    const int case_id = GCJ::get_input([&]{
        cin >> K >> c >> s;
    });
    vector<vector<ZZ>> res;
    {
        int pos = 0;
        rep(i, K){
            if(pos == res.size()) res.emplace_back(vector<ZZ>());
            res[pos].emplace_back(i);
            if(res[pos].size() == c) ++pos;
        }
        if(res.size() > s){
            GCJ::queue_output(case_id, [=]{
                cout << "IMPOSSIBLE" << endl;
            });
            return;
        }
    }
    GCJ::queue_output(case_id, [=]{
        int first = true;
        for(auto &t : res){
            ZZ now = 0;
            for(auto &c : t) now = (now * K + c);
            if(!first) cout << " ";
            first = false;
            cout << now + 1;
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
