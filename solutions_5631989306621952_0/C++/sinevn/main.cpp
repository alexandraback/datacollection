#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream fi("a.in");
    ofstream fo("a.out");
    
    int t;
    fi >> t;
    
    for (int i(0); i<t; i++) {
        string s;
        fi >> s;
        
        vector<char> v(s.begin(), s.end());
        for (int j(1); j<v.size(); j++) {
            if (v[j] >= v[0]) {
                char x = v[j];
                for (int k = j - 1; k >= 0; k--) {
                    v[k + 1] = v[k];
                }
                v[0] = x;
            }
        }
        
        fo << "Case #" << i+1 << ": ";
        for (int j(0); j<v.size(); j++) {
            fo << v[j];
        }
        fo << endl;
   }
    
    fi.close();
    fo.close();
    return 0;
}