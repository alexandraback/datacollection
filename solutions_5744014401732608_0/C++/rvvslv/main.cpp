#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const string path = "/Users/mac/Documents/cpp/Code Jam/";

const string IMPOSSIBLE = "IMPOSSIBLE";

int main() {
    ifstream cin(path + "in");
    ofstream cout(path + "out");
    
    int T;
    cin >> T;
    for (int CT = 1;  CT <= T; CT ++) {
        int n;
        long long m;
        cin >> n >> m;
        
        vector<long long> a(n, 0);
        
        vector< vector<int> > r(n);
        for (int i = 0; i < n; i ++) {
            vector<int> tmp(n, 0);
            r[i] = tmp;
        }
        
        bool ok = false;
        a[n - 1] = a[n - 2] = 1;
        r[n - 2][n - 1] = 1;
        
        if (m == 1)
            ok = true;
        
        for (int i = n - 3; i >= 0; i --) {
            a[i] = a[i + 1] * 2;
            
            long long t = a[i];
            
            if (a[i] > m) {
                a[i] = m;
                t = m;
            } else {
                t --;
                r[i][n - 1] = 1;
            }
            
            if (a[i] >= m)
                ok = true;
            
            int k = 1;
            while (t > 0) {
                if (t % 2 == 1) {
                    r[i][n - 1 - k] = 1;
                }
                k ++;
                t /= 2;
            }
        }
        
        cout << "Case #" << CT << ": " << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        
        if (ok) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++)
                    cout << r[i][j];
                cout << endl;
            }
        }
    }
    
    
    return 0;
}
