//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int MAX = 500000;
double C, F, X, best[MAX+1];

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/B-small-attempt0.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/B-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);
    
    int tt; cin >> tt;
    best[MAX] = MAX;
    for(int t = 1 ; t <= tt ; t++){
        cerr << "case " << t << endl;
        cin >> C >> F >> X;
        for(int i = MAX - 1 ; i >= 0 ; i--){
            double cps = 2+F*i;
            best[i] = X/cps;
            best[i] = min(best[i], C/cps+best[i+1]);
        }
        printf("Case #%d: %.9f\n", t, best[0]);
    }
    
    return 0;
}

