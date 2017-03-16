#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<double> solve(vector<int> &v) {
    int N = v.size();
    int X = 0;

    for(int i=0;i<N;i++) X += v[i];

    vector<double> r(N);
    double s = 0;
    int cnt = 0;
    for(int i=0;i<N;i++) {
        r[i] = (2.*X/N - v[i])/X;
        if(r[i] < 0) {
            s -= r[i];
        } else {
            cnt++;
        }
    }

    double a = s/cnt;
    for(int i=0;i<N;i++) {
        if(r[i] < 0) {
            r[i] = 0;
        } else {
            r[i] -= a;
        }
    }

    s = 0;
    for(int i=0;i<N;i++) s+=r[i];

    return r;
}

int main() {
    int T;

    cin >> T;
    for(int cs=1; cs<=T; cs++) {
        int N;
        cin >> N;

        vector<int> v(N);
        vector<double> r;

        for(int i=0;i<N;i++) cin >> v[i];
        r = solve(v);
        
        printf("Case #%d:", cs);
        for(int i=0;i<N;i++) printf(" %f", r[i]*100);
        puts("");
    }

    return 0;
}
