#include <cstdio>
#include <iostream>
using namespace std;
double f(int n, int l, int y){
    double ret = 0, dp = 1;
    for(int i = 0; i <= y; ++i){
        ret += dp;
        dp = dp *n / (i+1);
    }
    for(int i = 0; i < n; ++i)
        ret /= 2;
    ret = 1-ret;
    if(ret<0) ret = 0;
    return ret;
}

double solve(int n, int x, int y){
    int level = (x+y)/2;
    int yy = 2*level*level - level;
    int xx = 2*(level+1)*(level+1) - (level+1);
    if(n>=xx) return 1;
    if(n<=y) return 0;
    if(y==level*2){
        if(n<xx) return 0;
        else return 1;
    }
    return f(n - yy, level, y);
}

int main(){
//    int ta, tb, tc;
//    while(cin >> ta >> tb >> tc){
//        cout << f(ta, tb, tc) << endl;
//    }
    int T; cin >> T;
    for(int kase = 1; kase <= T; ++kase){
        int n, x, y;
        cin >> n >> x >> y;
        if(x<0) x = -x;
        double ans = solve(n, x, y);
        printf("Case #%d: ", kase);
        //cout << ans << endl;
        printf("%f\n", ans);
    }
}
