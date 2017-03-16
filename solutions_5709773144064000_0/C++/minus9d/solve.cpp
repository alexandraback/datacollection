#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        double C, F, X;
        cin >> C >> F >> X;

        if (X <= C){
            cout << "Case #" << (test+1) << ": ";
            printf("%.9lf\n", (double)X/2.0);
            continue;
        }
        
        int factory_num = 0;
        double time_to_buy_factory = 0.0;

        double sum_time = -1.0;
        double sum_time_prev = -1.0;

        while(1){
            if(factory_num > 0){
                time_to_buy_factory += (double)C / (2.0 + F * (factory_num - 1));
            }

            sum_time = time_to_buy_factory + (double)X/(2.0 + F * factory_num);

            if (factory_num == 0){
                sum_time_prev = sum_time;
            }
            
            ++factory_num;

            if(sum_time > sum_time_prev) break;

            sum_time_prev = sum_time;
        }
        
        cout << "Case #" << (test+1) << ": ";
        printf("%.9lf\n", sum_time_prev);
    }

    return 0;
}
