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

int main(){
    int dp[11][11];
    memset(dp,-1,sizeof(dp));
    for(int w=1; w<=10; w++){
        for(int c=w; c<=10; c++){
            if(c==w){
                dp[w][c] = w;
            }else if(c-w<w){
                dp[w][c] = w+1;
            }else{
                dp[w][c] = dp[w][c-w]+1;
            }
        }
    }
    int T;
    cin >> T;
    REP(testCase,T){
        int R,C,W;
        cin >> R >> C >> W;
        cout << "Case #" << testCase+1 << ": " << dp[W][C] << endl;

    }
    return 0;
}
