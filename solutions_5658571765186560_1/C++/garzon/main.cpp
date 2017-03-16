#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int a, t, x, r, c;
bool res;

const char *flag [] = { "GABRIEL", "RICHARD" };
const bool RICHARD = true, GABRIEL = false;

bool checkArea() {
    return (r >= x || c >=x) && (((r*c)%x) == 0);
}

bool check() {
    if(x>=7) return RICHARD;
    if(x==1) return GABRIEL;
    if(!checkArea()) return RICHARD;
    if(x==2) return GABRIEL;
    if(x==3) {
        if(r==1 || c==1) return RICHARD;
        return GABRIEL;
    }
    // x=4,5,6
    if(r<=2 || c<=2) return RICHARD;
    if(x==4) return GABRIEL;
    // x=5, 6
    if(x==5) {
        if(r==3 || c==3) {
            if (r*c/3 < 10) return RICHARD;
        }
        return GABRIEL;
    }
    // x=6
    if(r>=7 || c>=7) return GABRIEL;
    int tmp = r*c/6;
    // tmp = 3,4,5,6, r or c=6
    if(tmp>=5) return GABRIEL;
    if(tmp==3) return RICHARD;
    return GABRIEL;
}

int main() {
    cin >> t;
    for(a=0; a<t; a++) {
        cin >> x >> r >> c;
        cout << "Case #" << a+1 << ": " << flag[check()] << endl;
    }
    return 0;
}

