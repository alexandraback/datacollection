#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream cin("A-large.in.txt");
//    ofstream cout("/Users/mac/topcoder/res.txt");
    
    int N;
    cin >> N;
    
    for (int CT = 0; CT < N; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        int a, n;
        
        vector<int> m;
        
        cin >> a >> n;
        for (int i = 0; i < n; i ++) {
            int t;
            cin >> t;
            m.push_back(t);
        }
        
        int r = n;
        
        if (a == 1) {
            cout << r << endl;
            continue;
        }
        
        sort(m.begin(), m.end());
        
        int p = 0;
        for (int i = 0; i < m.size(); i ++) {
            //cout << "Step " << i << ": " << a << " want " << m[i] << endl;
            while (a <= m[i]) {
                a += a - 1;
                p ++;
            }
            a += m[i];
            if (p + m.size() - i - 1 < r)
                r = p + m.size() - i - 1;
        }
        
        cout << r << endl;
    }
    return 0;
}