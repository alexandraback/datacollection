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
#include <bits/stdc++.h>
#include <sys/time.h>
#ifdef _OPENMP
#include <omp.h>
#endif
using namespace std;
#define BEGIN_SOLVER struct solver {
#define END_SOLVER };

const string starter = " "; // "\n"
#define cout ss

void initializer()
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////
BEGIN_SOLVER //////////////   Coding from here   /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int k, l, s;
map<char, int> cnt;
string a, b;

void solve()
{
        cout << fixed << setprecision(12);
        cnt.clear();
        for(auto &e: a) cnt[e]++;
        for(auto &e: b) {
                if(!cnt[e]) {
                        cout << 0. << endl;
                        return;
                }
        }
        
        int rap = 0;
        for (int i = 1; i < l; i++) {
                if(b.substr(i,l-i) == b.substr(0,l-i)) {
                        rap = l-i;
                        break;
                }
        }
        int p = l, ma = 1;
        while(p < s) {
                p += l-rap;
                if(p <= s) ma++;
        }
        double dp[128][128] = {}, ans = 0;
        dp[0][0] = 1;
        for (int i = 0; i < s; i++) {
                for (int j = 0; j < l; j++) {
                        double p = 1.*cnt[b[j]]/k;
                        dp[i+1][j+1] = dp[i][j]*p;
                        dp[i+1][0] += dp[i][j]*(1-p);
                }
                dp[i+1][rap] += dp[i+1][l];
                ans += dp[i+1][l];
        }
        cout << ma-ans << endl;
}

void input()
{
        cin >> k >> l >> s;
        cin >> a >> b;
}

void init()
{
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


double sec()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec + tv.tv_usec * 1e-6;
}
void print_status(int c, int C, double t0, double t1, int nth)
{
        static const int L = 5;
        if (C > L && c % (C / L) != 0) return;
        else if (c - (nth - 1) / 2 <= 0) fprintf(stderr, "[ case: %d / %d ]\n", c, C);
        else {
                double t = sec();
                fprintf(stderr, "[ case: %d / %d | time: %.3f / %.3f ]\n",
                        c, C, t - t0, (t1 - t0) + (t - t1) / (c - (nth - 1) / 2) * C);
        }
}

int main(int argc, char **argv)
{
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
