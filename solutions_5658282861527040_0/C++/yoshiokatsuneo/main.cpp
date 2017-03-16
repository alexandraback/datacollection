//
//  main.cpp
//  googlecodejam
//
//  Created by Yoshioka Tsuneo on 4/12/14.
//  Copyright (c) 2014 Yoshioka Tsuneo. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stdexcept>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cassert>
#include <unistd.h>
#include <string.h>

#include <stack>

#include <thread>

#define decltype(X) __typeof(X)
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(it, c) for(decltype((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define ALL(c) (c).begin(), (c).end()

#define EPS 0.000001
using namespace std;

typedef long long ll;

#include <mutex>
#include <condition_variable>
using namespace std;

class semaphore{
private:
    mutex mtx;
    condition_variable cv;
    int count;
    
public:
    semaphore(int count_ = 0):count(count_){;}
    void notify()
    {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void wait()
    {
        unique_lock<mutex> lck(mtx);
        
        while(count == 0){
            cv.wait(lck);
        }
        count--;
    }
};


// #define MYDEBUG

map< pair<ll, pair<ll, ll> > , ll> memo;


ll dfs(ll pos, ll A, ll B, ll K)
{
#ifdef MYDEBUG
    printf("### dfs start: pos=%lld, A=%lld, B=%lld, K=%lld\n", pos, A, B, K);
#endif
    pair<ll, pair<ll, ll>> memo_key =make_pair(A, make_pair(B,K));
    if(memo.count(memo_key)!=0){
#ifdef MYDEBUG
        printf("dfs found memo: pos=%lld, A=%lld, B=%lld, K=%lld : ret=%lld\n", pos, A, B, K, memo[memo_key]);
#endif
        return memo[memo_key];
    }
    if(pos == -1){
        return 1;
    }
    ll total = 0;
    ll divnum = (1<<pos);
#ifdef MYDEBUG
    printf("pos=%lld, divnum=%lld\n", pos, divnum);
#endif
    if(A >= divnum && B>=divnum && K>=divnum){
#ifdef MYDEBUG
        printf("calling dfs1: pos=%lld, divnum=%lld, A=%lld, B=%lld, K=%lld\n", pos, divnum, A, B, K);
#endif
        ll num = dfs(pos-1, A & (divnum-1), B & (divnum-1), K-divnum);
        total += num;
    }

    if(A >= divnum){
#ifdef MYDEBUG
        printf("calling dfs0-1: pos=%lld, divnum=%lld, A=%lld, B=%lld, K=%lld\n", pos, divnum, A, B, K);
#endif
        ll num = dfs(pos-1, A & (divnum-1), min(B, divnum-1), min(K, divnum-1));
        total += num;
    }
    if(B >= divnum){
#ifdef MYDEBUG
        printf("calling dfs0-2: pos=%lld, divnum=%lld, A=%lld, B=%lld, K=%lld\n", pos, divnum, A, B, K);
#endif
        ll num = dfs(pos-1, min(A, divnum-1), B & (divnum-1), min(K, divnum-1));
        total += num;
    }
    {
#ifdef MYDEBUG
        printf("calling dfs0-3: pos=%lld, divnum=%lld, A=%lld, B=%lld, K=%lld\n", pos, divnum, A, B, K);
#endif
        ll num = dfs(pos-1, min(A, divnum-1), min(B, divnum-1), min(K, divnum-1));
        total += num;
    }
    memo[memo_key] = total;
#ifdef MYDEBUG
    printf("dfs end: pos=%lld, A=%lld, B=%lld, K=%lld : ret=%lld\n", pos, A, B, K, memo[memo_key]);
#endif
    return total;
}

ll testcase_itr(int A, int B, int K)
{
    memo.clear();
    ll num = dfs(30, A-1, B-1, K-1);
    return num;
}


ll  testcase(istream &in, int t)
{
    int A, B, K;
    in >> A >> B >> K;
    return testcase_itr(A, B, K);
}


// #define MULTI_THREAD

#ifdef MULTI_THREAD
semaphore sem(6);
vector< pair<bool, double> > g_results;

void testcase_for_multithread(int t, double C, double F, double X)
{
    g_results[t].second = testcase_itr(C, F, X);
    g_results[t].first = true;
    // sleep(rand()/(RAND_MAX/3.0));
    sem.notify();
}
#endif

int main(int argc, const char * argv[])
{
    // sleep(1000);
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    string fname = "/dev/stdin";
    if(argc>=2){
        fname = argv[1];
    }
    ifstream in(fname);
    if(!in){
        cout << "File open error:" << fname << endl;
        exit(1);
    }
    int T;
    in >> T;
    
#ifndef MULTI_THREAD
    for(int t=0;t<T;t++){
        auto result = testcase(in, t);
        cout << "Case #" << t+1 << ": " << result << endl;
        // return 0;
    }
#else
    vector<thread> threads;
    g_results.resize(T);
    int cur_result = 0;
    for(int t=0;t<T;t++){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result++;
        }
        double C, F, X;
        
        in >> C >> F >> X;
        
        // thread th(testcase_for_multithread, t, C, F, X );
        threads.push_back(thread(testcase_for_multithread, t, C, F, X ));
    }
    while(cur_result<T){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result ++;
        }
    }
    for(int t=0;t<T;t++){
        threads[t].join();
    }
#endif
    // std::cout << "Hello, World!\n";
    return 0;
}


