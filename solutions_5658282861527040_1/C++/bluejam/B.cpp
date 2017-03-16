#include <string> 
#include <algorithm> 
#include <cfloat> 
#include <climits> 
#include <cmath> 
#include <complex> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <functional> 
#include <iostream> 
#include <map> 
#include <memory> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <utility> 
#include <vector> 

#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(x) (x).begin(),(x).end() 
using namespace std;
const double eps = 1e-10;

//input data
int A, B, K;
long long dp[2][2][2][40];

long long recur(int a, int b, int k, int d){
    long long res = 0;
    if(dp[a][b][k][d] != -1) return dp[a][b][k][d];
    if(d == 0) return 1;
    // less than ... 0
    // equals and digit is 0 ... 1
    // equals and digit is 1 ... 2
    int aa = (((A >> (d-1)) & 1) + 1) * a,
        bb = (((B >> (d-1)) & 1) + 1) * b,
        kk = (((K >> (d-1)) & 1) + 1) * k;
    // A = B = 1
    if((aa == 0 || aa == 2) && (bb == 0 || bb == 2) && (kk == 0 || kk == 2)){
        res += recur(aa / 2, bb / 2, kk / 2, d-1);
    }
    // A = 1, B = 0
    if(aa == 0 || aa == 2){
        res += recur(aa / 2, b && bb == 1, k && kk == 1, d-1);
    }
    // A = 0, B = 1
    if(bb == 0 || bb == 2){
        res += recur(a && aa == 1, bb / 2, k && kk == 1, d-1);
    }
    // A = B = 0
    res += recur(a && aa == 1, b & bb == 1, k && kk == 1, d-1);
    return (dp[a][b][k][d] = res);
}
void solve(int caseNum){
    //solve problem here
    A--; B--; K--;
    memset(dp, -1, sizeof(dp));
    long long res = recur(1, 1, 1, 31);
    cout << "Case #" << caseNum << ": " << res << endl;
}

int main(){
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        //input test case here
        cin >> A >> B >> K;

        solve(t);
    }
    return 0;
}
