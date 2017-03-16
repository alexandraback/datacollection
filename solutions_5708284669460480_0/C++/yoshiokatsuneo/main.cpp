//
//  main.cpp
//  googlecodejam2015
//
//  Created by Yoshioka Tsuneo on 2015/04/11.
//  Copyright (c) 2015年 Yoshioka Tsuneo. All rights reserved.
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

// #define MULTI_THREAD

#ifdef MULTI_THREAD
#include <thread>
#endif

#define decltype(X) __typeof(X)
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(it, c) for(decltype((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define ALL(c) (c).begin(), (c).end()

#define EPS 0.000001
using namespace std;

typedef long long ll;


double testcase_itr(int K, int L, int S, string letters, string target)
{
    // solution start
    int overlap = 0;
    
    vector<int> ccounts(26,0);
    for(int k=0;k<K;k++){
        ccounts[letters[k]-'A'] ++;
    }
    for(int l=0;l<L;l++){
        if(ccounts[target[l]-'A']==0){
            return 0;
        }
    }
    
    vector<double> probs(26, 0.0);
    for(int ci=0;ci<26;ci++){
        probs[ci] = (1.0 * ccounts[ci]) / (1.0 * K);
        //cout << "probs[" << ci << "]=" << probs[ci] << endl;
    }
    
    for(int i=1;i<L;i++){
        string left = target.substr(0, (L-i));
        string right = target.substr(i, (L-i));
        if(left==right){
            overlap = (L-i);
            break;
        }
    }
    int worst = ((S - overlap)) / ((L - overlap));
    // cout << "overlap=" << overlap << ", worst=" << worst << endl;
    
    vector< vector<double> > nextlens(L+2, vector<double>(26,0));
    for(int i=0;i<=L;i++){
        for(int j=0;j<26;j++){
            string s = target.substr(0,i);
            s += (char)('A'+j);
            // cout << "i=" << i << ", j=" << j << ", s=" << s << endl;
            for(int k=0;k<(i+1);k++){
                int l2 = (i+1)-k;
                string s2 = s.substr(k, l2);
                string s3 = target.substr(0, l2);
                // cout << "s2=" << s2 << ", s3=" << s3 << endl;
                if(s2 == s3){
                    nextlens[i][j] = (i+1)-k;
                    // cout << "nextlens[" << i << "][" << j << "]=" << nextlens[i][j] << endl;
                    break;
                }
            }
        }
    }
    
    vector< vector< vector<double> > > dp(S+1, vector< vector<double> >(worst+2, vector<double>(L+1, 0.0) ) );
    dp[0][0][0] = 1.0;
    for(int i=0;i<S;i++){
        for(int j=0;j<=worst;j++){
            for(int len=0;len<=L;len++){
                for(int ci=0;ci<26;ci++){
                    int nextlen = nextlens[len][ci];
                    double p =dp[i][j][len] * probs[ci];
                    if(p>0){
                        //cout << "i=" << i << ", j=" << j << ", len=" << len << ", ci=" << ci << ", nextlen=" << nextlen << ", p=" << p << endl;
                        if(len == L){
                            dp[i+1][j+1][nextlen] += p;
                            //cout << "#: dp[" << i+1 << "][" << j+1 << "][" <<nextlen<< "]=" << dp[i+1][j+1][nextlen] << endl;
                        }else{
                            dp[i+1][j][nextlen] += p;
                            //cout << "x: dp[" << i+1 << "][" << j << "][" << nextlen << "]=" << dp[i+1][j][nextlen] << endl;
                        }
                    }
                }
            }
        }
    }
    
    double estimate = 0;
    for(int j=0;j<=worst;j++){
        for(int len=0;len<L;len++){
            estimate += (dp[S][j][len] * j);
        }
        estimate += (dp[S][j][L] * (j+1));
    }
    // cout << "estimate=" << estimate << endl;
    
    double remain = worst - estimate;
    
    // solution end
    
    return remain;
}
void testcase(istream &in)
{
    int T;
    in >> T;
    for(int i=0;i<T;i++){
        int K, L, S;
        string letters, target;
        in >> K >> L >> S;
        in >> letters;
        in >> target;
        auto ret = testcase_itr(K, L, S, letters, target);
        cout << "Case #" << i+1 << ": " << ret << endl;
    }
}

#ifdef MULTI_THREAD
void testcase_multi(istream &in);
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
        ifstream in(fname, ifstream::in);
        if(!in){
            cout << "File open error:" << fname << endl;
            exit(1);
        }
#ifdef MULTI_THREAD
        testcase_multi(in);
#else
        testcase(in);
#endif
        /*
         int result = testcase(in);
         cout << result << endl;
         */
    }else{
#ifdef MULTI_THREAD
        testcase_multi(cin);
#else
        testcase(cin);
#endif
        /*
         int result = testcase(cin);
         cout << result << endl;
         */
        
    }
    return 0;
}

#ifdef MULTI_THREAD
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
semaphore sem(6);
vector< pair<bool, double> > g_results;

void testcase_for_multithread(int t, int M, int N, vector<string> X)
{
    g_results[t].second = testcase_itr(C, F, X);
    g_results[t].first = true;
    // sleep(rand()/(RAND_MAX/3.0));
    sem.notify();
}

void testcase_multi(istream &in)
{
    int T;
    in >> T;
    
    vector<thread> threads;
    g_results.resize(T);
    int cur_result = 0;
    for(int t=0;t<T;t++){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result++;
        }
        
        int M, N;
        in >> M >> N;
        vector<string> ma;
        for(int i=0;i<M;i++){
            string line;
            in >> line;
            ma.push_back(line);
        }
        threads.push_back(thread(testcase_for_multithread, t, M, N, ma ));
        
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
    
}
#endif



