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

int solve(const string &S){
    int add = 0;
    int sum = 0;
    REP(i, S.size()){
        int S_i = S[i] - '0';
        if(S_i==0)continue;
        if(sum + add < i)add += i - sum;
        sum += S_i;
    }
    return add;
}

int main(){
    int T;
    cin >> T;

    REP(i, T){
        int S_max;
        string S;
        cin >> S_max >> S;
        int ans = solve(S);
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
}
