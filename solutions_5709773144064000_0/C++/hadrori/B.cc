#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <complex>

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);

double C, F, X;

void init(){
}

void input(){
    cin >> C >> F >> X;
}

void solve(){
    double ans = X / 2.0;
    double sum = 0;
    for(int t = 1; ; t++){
        sum += C / (2.0+F*(t-1));
        double res = X / (2.0+F*t);
        if(sum + res > ans) break;
        ans = sum + res;
    }
    printf("%.7f\n", ans);
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        init(); input();
        solve();
    }
    return 0;
}
