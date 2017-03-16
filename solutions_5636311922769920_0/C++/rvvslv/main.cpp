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
        int k, c, s;
        cin >> k >> c >> s;
        
        cout << "Case #" << CT << ":";
        
        if (s * c < k) {
            cout << " " << IMPOSSIBLE << endl;
            continue;
        }
        
        int a = 0;
        bool done = false;
        for (int i = 0; i < s; i ++) {
            long long n = 0;
            for (int j = 0; j < c; j ++) {
                n *= k;
                n += a;
                a ++;
                if (a == k) {
                    done = true;
                    a = 0;
                }
            }
            cout << " " << (n + 1);
            if (done)
                break;
        }
        
        cout << endl;
    }
    
    
    return 0;
}
