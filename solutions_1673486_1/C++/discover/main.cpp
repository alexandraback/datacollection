#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define sz size()
typedef long long ll;
const int N = 100000 + 11;

int n,m;
double p[N];
double del[N];
//double solve(){
//    for (int i = 0; i <= m; ++i) del[i] = 0;
//    int top = 1 << m;
//    for (int i = 0; i < top; ++i){
//        double tp = 1.0;
//        for (int j = 0; j < m; ++j)
//            if (i >> j & 1)tp *= (1.0 - p[j]);
//            else  tp *= p[j];
//        //cout <<"~~"<< tp << endl;
//        for (int j = 0; j <= m; ++j){
//            int flag = -1;
//            for (int k = 0; k + j < m; ++k){
//                if (i >> k & 1) flag = k;
//            }
//            if(flag == -1) {// cout << j <<"~~" << endl;
//                del[j] += tp*(2*j + n - m + 1);
//                //cout << ": " << (2*j + n - m + 1) << endl;
//            }
//            else {
//                del[j] += tp * (2*j + n - m + n + 2);
//                //cout << ": " << (2*j + n - m +n +  2) << endl;
//            }
//        }
//    }
//    double res = n + 2;
//    for (int i = 0; i <= m; ++i){
//       // printf("%.6lf\n",del[i]);
//        res = min(res,del[i]);
//    }
//    return res;
//}

double dp[N];
double solve2(){
    dp[0] = 1.0 - p[0];
    double tmp = p[0];
    for (int i = 1; i < m; ++i){
        dp[i] = tmp * (1.0 - p[i]);
        tmp *= p[i];
    }
    dp[m] = tmp;
    memset(del,0,sizeof(del));
    for (int i = 0; i <= m; ++i){
        for (int j = 0; j <= m; ++j){
            if (i >= m - j) del[j] += dp[i]*(2*j + n - m + 1);
            else  del[j] += dp[i] *(2*j + n - m + n + 2);
        }
    }
    double res = n + 2;
    for (int i = 0; i <= m; ++i){
       // printf("%.6lf\n",del[i]);
        res = min(res,del[i]);
    }
    return res;
}

int main() {
   freopen("in","r",stdin);
    freopen("out","w",stdout);
    int cas, tcas = 0;
    cin >> cas;
    for(tcas = 1; tcas <= cas; ++tcas){
        cin >> m>>n;
        for (int i = 0; i < m; ++i) scanf("%lf",p+i);
        printf("Case #%d: %.6lf\n",tcas, solve2());
    }
}
