#include<bits/stdc++.h>

using namespace std;

int f(int a, int b) {
    return a / b;
}

int g(int a, int b) {
    if(a == b) return a;
    return (a-1)/b + b;
}

int main(){
    int T;
    cin >> T;
    for(int _t=1;_t<=T;_t++) {
        int R, C, W;
        cin >> R >> C >> W;
        cout << "Case #" << _t << ": " << (R-1)*f(C, W)+g(C, W) << endl;
    }
}

