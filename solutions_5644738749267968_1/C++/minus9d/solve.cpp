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
        int N;
        cin >> N;
        vector<double> naomi(N);
        vector<double> ken(N);
        REP(n, N){
            cin >> naomi[n];
        }
        REP(n, N){
            cin >> ken[n];
        }

        int score_war = 0;
        set<double> ken_set(ALL(ken));
        for (auto n : naomi){
            double k_pick = 1e3;
            for( auto k : ken_set ){
                if ( k > n && k < k_pick ){
                    k_pick = k;
                }
            }
            if (k_pick == 1e3){
                k_pick = *ken_set.begin();
            }
            
            if (n > k_pick) ++score_war;
            ken_set.erase(k_pick);
        }

        sort(ALL(naomi));
        sort(ALL(ken));
        deque<double> naomi_d(ALL(naomi));
        deque<double> ken_d(ALL(ken));

        int score_d_war = 0;
        while(!naomi_d.empty()){
            if (naomi_d[0] < ken_d[0]){
                // erase head
                naomi_d.pop_front();
                // erase tail
                ken_d.pop_back();
            }
            else{
                naomi_d.pop_front();
                ken_d.pop_front();
                ++score_d_war;
            }
        }

        cout << "Case #" << (test+1) << ": " << score_d_war << " " << score_war << endl;
    }

    return 0;
}
