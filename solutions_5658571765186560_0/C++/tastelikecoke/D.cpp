#include <iostream>
using namespace std;
int main(){
    int cases = 0;
    cin >> cases;
    for(int t=0;t<cases;t++){
        int x, r, c;
        cin >> x >> r >> c;
        bool rich = false;
        if(c < r){
            int temp = c;
            c = r;
            r = temp;
        }
        if(x == 1) rich = true;
        if(x == 2){
            if(r*c % 2 == 0) rich = true;
        }
        if(x == 3){
            if(r*c == 9 or r*c == 12 or r*c == 6){
                rich = true;
            }
        }
        if(x == 4){
            if(r==4 and c==4) rich = true;
            if(r==3 and c==4) rich = true;
        }
        if(rich) cout << "Case #" << t+1 << ": GABRIEL" << endl;
        else     cout << "Case #" << t+1 << ": RICHARD" << endl;
    }
}