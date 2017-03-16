#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;

void solve(){
    double D;
    int N, A;
    cin >> D >> N >> A;
    vector<double> t, x, a;
    for(int i=0; i<N; i++){
        double d;
        cin >> d;
        t.push_back(d);
        cin >> d;
        x.push_back(d);
    }

    for(int i=0; i<A; i++){
        double d;
        cin >> d;
        a.push_back(d);
    }
    if(N == 1 || x[0] > D){
        for(int i=0; i<A; i++){
            cout << sqrt(2*D/a[i]) << '\n';
        }
        return ;
    }
    double v = (x[1]-x[0])/(t[1]-t[0]);
    double tim = (D-x[0])/v;
    for(int i=0; i<A; i++){
        double d = a[i]/2*tim*tim;
        if(d > D){
            cout << tim << '\n';
        }
        else{
            cout << sqrt(2*D*a[i]) << '\n';
        }
    }
}

int main(){
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": " << '\n';
        solve();
    }
    return 0;
}
