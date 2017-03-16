#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int x, r, c; cin >> x >> r >> c;
        if(r > c) swap(r, c);
        bool impossible;
        if((r*c)%x != 0){
            impossible = true;
        } else if(x == 1 || x == 2){
            impossible = false;
        } else if(x == 3){
            impossible = min(r, c) == 1;
        } else if(4 <= x && x < 7){
            impossible = r < x-1 || r*c < x*(x-1);
        } else {
            impossible = true;
        }
        cout << "Case #" << tc << ": " << (impossible ? "RICHARD" : "GABRIEL") << endl;
    }
}


