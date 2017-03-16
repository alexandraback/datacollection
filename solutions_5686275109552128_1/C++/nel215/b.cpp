#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int solve(vector<int> P){
    int ans = *max_element(ALL(P));

    for(int thres=*max_element(ALL(P)); thres>=1; thres--){
        int tmp = 0;
        REP(i, P.size()){
            tmp += (P[i]-1)/thres;
        }
        ans = min(ans, tmp+thres);
    }

    return ans;
}

int main(){
    int T;
    cin >> T;
    REP(testCase, T){
        int D;
        cin >> D;
        vector<int> P(D);
        REP(i, D)cin >> P[i];
        cout << "Case #" << testCase+1 << ": " << solve(P) << endl;
    }
}
