#include <bits/stdc++.h>
namespace GCJ{//{{{
    std::mutex log_mutex;
    struct {
        using Entry = std::pair<int, std::function<void(void)>>;
        std::vector<Entry> queue;
        void emplace_back(int case_id, std::function<void(void)> f){
            static std::mutex output_mutex;
            output_mutex.lock();
            queue.emplace_back(case_id, f);
            output_mutex.unlock();
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
    long long n;
    const int case_id = GCJ::get_input([&]{
        cin >> n;
            });
    if(n == 0){
        GCJ::queue_output(case_id, [&]{
            cout << "INSOMNIA" << endl;
                });
        return;
    }
    vector<char> used(10, 0);
    long long now = 0;
    for(; *min_element(all(used)) == 0; now += n){
        for(long long tmp = now; tmp; tmp /= 10) used[tmp%10] = 1;
    }
    GCJ::queue_output(case_id, [=]{
        cout << now - n << endl;
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
