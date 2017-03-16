#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

int main() {
    int N;
    cin >> N;
    for(int kase=1; kase<=N; kase++) {
        int x, r, c;
        cin >> x >> r >> c;
        if(r>c) swap(r,c);
        cout << "Case #" << kase << ": ";
        //cerr << x << " " << r << " " << c << "          ";
        if(x>=7) {
            //cerr << "x>=7           ";
            cout << "RICHARD" << endl;
            continue;
        }
        if((r*c)%x) {
            //cerr << "cannot fit:    ";
            cout << "RICHARD" << endl;
            continue;
        }
        if(x >= 2*r+1 || x > c) {
            //cerr << "x>2r+1 or x>c: ";
            cout << "RICHARD" << endl;
            continue;
        }
        if((x == 4 || x== 6) && r == 2) {
            //cerr << "4 and 2:       ";
            cout << "RICHARD" << endl;
            continue;
        }
        if(x <= 4) {
            //cerr << "x<4            ";
            cout << "GABRIEL" << endl;
            continue;
        }
        cout << "GABRIEL" << endl;
    }
    return 0;    
}
