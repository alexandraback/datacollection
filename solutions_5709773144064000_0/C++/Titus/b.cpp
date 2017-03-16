#include <iostream>
#include <vector>
#include <algorithm>
#include <float.h>

using namespace std;

void solve(){
    cout.precision(7);
    cout << fixed;
    double C, F, X;
    cin >> C >> F >> X;


    int earn = 2;
    double best = X/2;
    for(int i=1;; ++i){
        double time = 0;
        for(int j=0; j<i; ++j){
            time += C/(2+j*F);
        }
        time += X/(2+i*F);
        if(time < best) best = time;
        else{
            cout << best;
            return;
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << '\n';
    }
}
