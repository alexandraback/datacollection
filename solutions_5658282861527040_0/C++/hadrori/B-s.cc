/*
  template for C++11 in GCJ
  
  using multi thread
  use only cout for output
  ///////////////////////
  //do not use "printf"//
  ///////////////////////
 
  compile option
  -fopenmp -O2
  ./a.out -p -> parallel
  ./a.out -s -> show status
 */
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <vector>
#include <future>
#include <chrono>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <climits>
#ifdef _OPENMP
#include <omp.h>
#endif

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef complex<double> point;
typedef vector<point> graph;
typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
typedef long long ll;

#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define repit(i,u) for(auto i = (u).begin(); i != end(u); i++)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define my_unique(u) (u).erase(unique(all(u)),end(u))
#define dump(x) cerr << #x << " = " << x << endl;

#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fst first
#define snd second
#define BEGIN_SOLVER struct solver {
#define END_SOLVER };

const int inf = 1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

template<class T> inline T sq(T x) { return x * x;}
template<class T> inline T mypow(T x, int e) { return e == 0? 1: e%2? x * pow(x,e-1): pow(x*x,e/2);}
template<class T> inline void chmax(T &x, T y) { if(x < y - eps) x = y;}
template<class T> inline void chmin(T &x, T y) { if(x > y + eps) x = y;}
inline bool eq(double x, double y) { return abs(x - y) < eps;}
inline int pow2(int e) { return 1LL << e;}
inline int lcm(int x, int y) { return x * y / __gcd(x,y);}
inline signed to_int(string s) { return atoi(s.c_str());}
inline ll to_long(string s){ stringstream ss; ss << s; ll ret; ss >> ret; return ret;}
inline ll to_bin(string s){ ll t = 0; for(int i = 0; i < s.size(); i++) t |= (ll)(s[i]-'0')<<i; return t;}
// 4 directions
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
// 8 directions
const int ddi[] = {-1,-1,-1,0,1,1,1,0};
const int ddj[] = {-1,0,1,1,1,0,-1,-1};

const string starter = " "; // "\n"
#define cout ss
// cout << setprecision(10)

void initializer(){
}
//////////////////////////////////////////////////////////////////////////////////////////////////
BEGIN_SOLVER //////////////   Coding from here   /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int A, B, K;

void solve(){
    int ans = 0;
    rep(a,A) rep(b,B)
        if((a&b) < K) ans++;
    cout << ans << endl;
}

void input(){
    cin >> A >> B >> K;
}

void init(){
}

stringstream ss;
string output_s;
solver(){
    output_s = "";
    ss.str("");
}

void output(){
    output_s = starter;
    output_s += ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
END_SOLVER //////////////   Do not edit from here   //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////




double sec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}
void print_status(int c, int C, double t0, double t1, int nth) {
    static const int L = 5;
    if (C > L && c % (C / L) != 0) return;
    else if (c - (nth - 1) / 2 <= 0) fprintf(stderr, "[ case: %d / %d ]\n", c, C);
    else {
        double t = sec();
        fprintf(stderr, "[ case: %d / %d | time: %.3f / %.3f ]\n",
                c, C, t - t0, (t1 - t0) + (t - t1) / (c - (nth - 1) / 2) * C);
    }
}

int main(int argc, char **argv){
    bool parallel = false, status = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) parallel = status = true;
        else if (strcmp(argv[i], "-s") == 0) status = true;
        else {
            fprintf(stderr, "usage: %s [-p] [-s]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    double t0 = sec();
    initializer();
    double t1 = sec();
    if (status) fprintf(stderr, "[ init: %.3f ]\n", t1 - t0);

    int T; cin >> T;
    if (!parallel) {
        if (status) fprintf(stderr, "[ mode: single thread ]\n");
        for (int t = 0; t < T; t++) {
            if (status) print_status(t, T, t0, t1, 1);
            printf("Case #%d:", t+1);
            solver *s = new solver();
            assert(s != NULL);
            s->init();
            s->input();
            s->solve();
            s->output();
            printf("%s", s->output_s.c_str());
            delete s;
        }
    }
    else{
#ifdef _OPENMP
        int nth = omp_get_max_threads();
        vector<string> out(T);
        vector<bool> done(T);
        int solve_c = 0, out_t = 0;
        omp_lock_t lock;
        omp_init_lock(&lock);
#pragma omp parallel for schedule(dynamic, 1)
        for (int t = 0; t < T; t++) {
            solver *s = new solver();
            assert(s != NULL);
            int my_c;
            omp_set_lock(&lock);
            {
                while (out_t < T && done[out_t]) {
                    printf("Case #%d:", out_t+1);
                    printf("%s", out[out_t].c_str());
                    out_t++;
                }
                if (status) print_status(solve_c, T, t0, t1, nth);
                my_c = solve_c++;
                s->init();
                s->input();
            }
            omp_unset_lock(&lock);
            
            s->solve();
            s->output();
            
            omp_set_lock(&lock);
            {
                out[my_c] = s->output_s;
                done[my_c] = true;
            }
            omp_unset_lock(&lock);
            delete s;
        }
        omp_destroy_lock(&lock);

        while (out_t < T) {
            assert(done[out_t]);
            printf("Case #%d:", out_t+1);
            printf("%s", out[out_t].c_str());
            out_t++;
        }
#else
        cerr <<"error: compile with -fopenmp !!\n";
#endif
    }
    return 0;
}
