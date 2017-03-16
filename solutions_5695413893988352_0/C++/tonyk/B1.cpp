#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool sol_ok (int x, string &s) {
    //cout << x << " " << s << endl;
    char xs[3];
    int ll = s.length();
    for (int i = ll - 1; i >= 0; i--) {
        xs[i] = '0' + (x % 10);
        x /= 10;
    }
    
    /*
    string xs = to_string(x);
    while (xs.length() < s.length()) {
        xs = "0" + xs;
    }
    */
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '?' && s[i] != xs[i]) {
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        string c, j;
        cin >> c >> j;
        
        int len = c.length();
        int pot = 1;
        for (int jj = 0; jj < len; jj++) {
            pot *= 10;
        }
        
        int csol = -1;
        int jsol = -1;
        for (int jj = 0; jj < pot; jj++) {
            for (int k = 0; k < pot; k++) {
                if (sol_ok(jj, c) && sol_ok(k, j)) {
                    //cout << "sol_ok" << endl;
                    if (csol == -1) {
                        csol = jj;
                        jsol = k;
                    } else if (abs(jj - k) < abs(csol - jsol)) {
                        csol = jj;
                        jsol = k;
                    } else if (abs(jj - k) == abs(csol - jsol)) {
                        if (jj < csol) {
                            csol = jj;
                            jsol = k;
                        } else if (k < jsol) {
                            csol = jj;
                            jsol = k;
                        }
                    }
                }
            }
        }
        
        string cs = to_string(csol);
        string js = to_string(jsol);
        while (cs.length() < len) cs = "0" + cs;
        while (js.length() < len) js = "0" + js;
        
        cout << "Case #" << i+1 << ": " << cs << " " << js << endl;
        
    }
    return 0;
}
