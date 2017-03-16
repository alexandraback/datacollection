#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream fi("b.in");
    ofstream fo("b.out");
    
    int t;
    fi >> t;
    
    for (int i(0); i<t; i++) {
        int n;
        fi >> n;
        vector<int> count(2500, 0);
        for (int j(0); j<n; j++) {
            for (int k(0); k<n; k++) {
                int x;
                fi >> x;
                count[x]++;
            }
        }
        for (int j(0); j<n - 1; j++) {
            for (int k(0); k<n; k++) {
                int x;
                fi >> x;
                count[x]++;
            }
        }
        vector<int> missing;
        for (int j(0); j < 2500; j++) {
            if ((count[j] & 1) == 1) {
                missing.push_back(j);
            }
        }
        if (missing.size() == n) {
            sort(missing.begin(), missing.end());
        }
        fo << "Case #" << i + 1 << ": ";
        for (int j(0); j<n; j++) {
            fo << missing[j] << " ";
        }
        fo << endl;
        
   }
    
    fi.close();
    fo.close();
    return 0;
}