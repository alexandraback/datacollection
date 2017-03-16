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
        } else if(x == 4){
            impossible = r < 3 || r*c < 12;
        }
        cout << "Case #" << tc << ": " << (impossible ? "RICHARD" : "GABRIEL") << endl;
    }
}


