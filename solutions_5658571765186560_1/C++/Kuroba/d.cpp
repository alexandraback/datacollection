#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, a, b;

bool GabeWin(int x, int r, int c){
    int lo = min(r,c);
    int hi = max(r,c);
    int len;
    if (x>hi || r*c%x > 0) return false;
    if (lo>x) return true;
    if (x == 1) return true;
    if (x == 2) return true;
    if (x == 3){
        len = 2;
        if (lo < len) return false;
        if (lo>x) return true;
        return true;
    }
    if (x==4){
        len = 2;
        if (lo<=2) return false;
        if (lo>x) return true;
        else return true;
    }
    // =================================================
    if (x==5){
        len = 3;
        if (lo<3) return false;
        if (lo>5) return true;
        if (hi < 5) return false;
        if (lo == 3 && hi == 5) return true; //??
        if (lo == 4 && hi == 5) return true; //??
        if (lo == 5 && hi == 5) return true;
        if (lo == 3) return true; //??
        if (lo == 4) return true; //??
        if (lo == 5) return true;
        return true;

    }
    // =================================================
    if (x==6){
        len = 3;
        if (lo<3) return false;
        if (lo>6) return true;


        if (hi == 5) return false;
        if (lo == 4 && hi == 4) return false;
        if (lo == 3 && hi == 4) return false;

        if (lo == 6 && hi == 6) return true;
        if (lo == 5 && hi == 6) return true;
        if (lo == 4 && hi == 6) return true;
        if (lo == 3 && hi == 6) return false;

        if (lo == 6) return true;
        if (lo == 5) return true;
        if (lo == 4) return true;
        if (lo == 3) return false;

        return true;

    }
    // =================================================

    if (x > 6) return false;

    return true;

}
int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    cin >> T;
    for (int i = 1; i<=T; i++){
        printf("Case #%d: ", i);
        int x, r, c;
        cin >> x >> r >> c;
        if (GabeWin(x,r,c)) cout << "GABRIEL" << endl;
        else cout << "RICHARD" << endl;

    }

}
