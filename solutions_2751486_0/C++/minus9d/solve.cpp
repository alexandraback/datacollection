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

bool isV(char ch){
    if (ch == 'a'
        || ch == 'e'
        || ch == 'i'
        || ch == 'o'
        || ch == 'u'){
        return true;
    }
    else{
        return false;
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        string str;
        int N;
        int len;

        cin >> str;
        cin >> N;
        len = str.size();

        ll ret = 0;
        for(int i = 0; i < len; ++i){
            for(int j = i; j < len; ++j){

                int succ = 0;
                bool con = false;
                int best_succ = 0;
                for(int k = i; k <= j; ++k){
                    if (k == i){
                        if (!isV(str[k])){
                            con = true;
                            ++succ;
                        }
                    }
                    else{
                        if (!isV(str[k])){
                            con = true;
                            ++succ;
                        }
                        else{
                            con = false;
                            best_succ = max(succ, best_succ);
                            succ = 0;
                        }
                    }
                }
                if (con = true){
                    best_succ = max(succ, best_succ);
                }
                
                if (best_succ >= N){
                    //printf("i, j = %d, %d. ok. succ = %d\n", i, j, best_succ);
                    ++ret;
                }
            }
        }

        cout << "Case #" << (test+1) << ": " << ret << endl;
    }

    return 0;
}
