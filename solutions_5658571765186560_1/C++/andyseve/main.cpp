#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int S[200004];
int mul(int a, int b){
    if(a == 1 || b == 1 || a == -1 || b == -1) return a * b;
    if(a < 0) return -mul(-a,b);
    if(b < 0) return -mul(a,-b);
    if(a == b) return -1;
    if(a == 2 && b == 3) return 4; if(a == 3 && b == 2) return -4;
    if(a == 3 && b == 4) return 2; if(a == 4 && b == 3) return -2;
    if(a == 4 && b == 2) return 3; if(a == 2 && b == 4) return -3;
    return 0;
}


int main()
{
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _T;
    cin >> _T;
    for(int T = 0; T < _T; T++){
        int X, R, C;
        cin >> X >> R >> C;
        if(X > 6){
            cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        if(X > max(R,C)){
            cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        if((R * C) % X){
            cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        if(X == 6){
            if(min(R,C) > 4) cout << "Case #" << T+1<< ": " << "GABRIEL" << "\n";
            else cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        if(X == 5){
            if(min(R,C) > 3) cout << "Case #" << T+1<< ": " << "GABRIEL" << "\n";
            else if(min(R,C) == 3 && max(R,C) > 5) cout << "Case #" << T+1<< ": " << "GABRIEL" << "\n";
            else cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        if(X == 4){
            if(min(R,C) > 2) cout << "Case #" << T+1<< ": " << "GABRIEL" << "\n";
            else cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        if(X == 3){
            if(min(R,C) > 1) cout << "Case #" << T+1<< ": " << "GABRIEL" << "\n";
            else cout << "Case #" << T+1<< ": " << "RICHARD" << "\n";
            continue;
        }
        cout << "Case #" << T+1<< ": " << "GABRIEL" << "\n";
    }
    return 0;
}
