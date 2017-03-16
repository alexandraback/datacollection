#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

int t;


bool check(string s, int k) {
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != '?' && (s[i]-'0' != (k%10)))
            return 0;
        k /= 10;
    }
    return 1;
}

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<": ";
        string c, j;
        cin >> c >> j;
        
        int l = c.length();
        
        int p[4] = {1, 10, 100, 1000};
        int mindist = 100000;
        int aa, bb;

        for (int a = 0; a < p[l]; a++)
            for (int b = 0; b < p[l]; b++) {
                //cout << a << " " << b << endl; 
                
                if (check(c, a) && check(j, b)) {
                    if (abs(a-b) < mindist) {
                        aa = a;
                        bb = b;
                        mindist = abs(a-b);
                    }
                }
            }
        
        //cout << l << endl; 
        std::cout << std::setfill('0') << std::setw(l) <<  aa <<" "  << std::setfill('0') << std::setw(l) << bb << endl;   
    }

    return 0;
}
