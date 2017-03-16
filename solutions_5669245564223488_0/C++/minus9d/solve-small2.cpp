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
        vector<string> strs(N);
        REP(n, N){
            cin >> strs[n];
            strs[n].erase( unique(ALL(strs[n])), strs[n].end() );
        }


        int char_num = 0;
        string tmp;
        REP(i, N) {
            tmp += strs[ i ];
        }
        sort(ALL(tmp));
        tmp.erase( unique(ALL(tmp)), tmp.end() );
        char_num = tmp.size();

        vector<int> shuff(N);
        REP(i, N){
            shuff[i] = i;
        }

        sort(ALL(strs));

        int ret = 0;
        do {
            string cmb;
            REP(i, N) {
                cmb += strs[ shuff[i] ];
            }

            cmb.erase( unique(ALL(cmb)), cmb.end() );

            if (char_num == SIZE(cmb)) ++ret;
        } while (next_permutation(ALL(shuff)));
        
        cout << "Case #" << (test+1) << ": " << ret << endl;
    }

    return 0;
}
