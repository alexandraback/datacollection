#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int tn;
string A, B;

/*string to__string (int x) {
    if (x == 0) return "0";
    string ret = "";
    while (x > 0) {
        ret = string('0' + (x % 10), 1) + ret;
        x /= 10;
    }
    return ret;
}*/

bool ok (string a, string b) {
    for(int i = 0; i < a.length(); ++i) if (a[i] != '?' && a[i] != b[i]) return false;
    return true;
}

int main () {
    
    cin >> tn;
    for(int ti = 1; ti <= tn; ti++) {
        
        cin >> A >> B;
        string ox, oy;
        int mx = 0;
        for(int i = 1; i <= A.length(); i++) mx = mx * 10 + 9;
        int opt = 10000000;
        for(int x = 0; x <= mx; x++) for(int y = 0; y <= mx; y++) {
            string X = to_string(x);
            string Y = to_string(y);
            while (X.length() < A.length()) X = "0" + X;
            while (Y.length() < B.length()) Y = "0" + Y;
            
            if (!ok(A, X)) continue;
            if (!ok(B, Y)) continue;
        
            if (abs(x-y)<opt) {
                opt = abs(x-y);
                ox=X;
                oy=Y;
            }
        }
        cout << "Case #" << ti << ": " << ox << " " << oy << endl;
    }
    
    return 0;
}