/* In the name of ALLAH, most gracious, most merciful */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define LESS 0
#define EQUAL 1
#define GREATER 2

int getFlag(int oldFlag, int idx, int n, int bit){
    if(oldFlag == LESS) return LESS;
    assert(oldFlag != GREATER);
    int bInpOS = (bool) (n & (1 << idx));
    if(bit > bInpOS) return GREATER;
    if(bit < bInpOS) return LESS;
    return EQUAL;
}

int A, B, K;

long long dp[36][3][3][3];

long long solve(int idx, int flagA, int flagB, int flagK){
    if(flagA == GREATER) return 0;
    if(flagB == GREATER) return 0;
    if(flagK == GREATER) return 0;
    if(idx < 0) return 1;
    long long & ret = dp[idx][flagA][flagB][flagK];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ret += solve(idx - 1,
                         getFlag(flagA, idx, A, i),
                         getFlag(flagB, idx, B, j),
                         getFlag(flagK, idx, K, i & j)
                    );
        }
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
#endif    
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, n, t = 1;
    
    cin >> T;
    while(T--){
        memset(dp, -1, sizeof dp);
        cin >> A >> B >> K;
        --A, --B, --K;
        cout << "Case #" << t++ << ": ";
        cout << solve(30, EQUAL, EQUAL, EQUAL) << endl;;
    }
    
    return 0;
}