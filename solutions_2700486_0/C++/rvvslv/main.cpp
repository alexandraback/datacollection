#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream cin("B-small-attempt2.in.txt");
//    ofstream cout("/Users/mac/topcoder/res.txt");
    
    int N;
    cin >> N;
    
    for (int CT = 0; CT < N; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        int n, x, y;
        cin >> n >> x >> y;
        if (x < 0)
            x = -x;
        
        int r = -1, k = 0;
        bool isCenter = false;
        for (int i = 1; ; i += 4) {
            r ++;
            k = 2 * r;
            if (n == i) {
                if (x == 0 && y == k) {
                    cout << "1.0" << endl;
                } else {
                    cout << "0.0" << endl;
                }
                isCenter = true;
                break;
            } else {
                if (n < i)
                    break;
            }
            n -= i;
        }
        
        if (isCenter)
            continue;
        
        if (x + y < k) {
            cout << "1.0" << endl;
            continue;
        }
        
        if (x + y > k) {
            cout << "0.0" << endl;
            continue;
        }
        
        if (x == 0) {
            cout << "0.0" << endl;
            continue;
        }
        
        y ++;
        
        if (y > n) {
            cout << "0.0" << endl;
            continue;
        }
        
//        cout << n << " " << y << endl;
        long double res = 1.0, c = 1.0;
        
        for (int i = 1; i <= min(n - y, k); i ++) {
            c = c * (n - i + 1) / i;
            res += c;
        }
        
        for (int i = 0; i < n; i ++)
            res /= 2.0;
            
        cout << res << endl;
    }
    return 0;
}