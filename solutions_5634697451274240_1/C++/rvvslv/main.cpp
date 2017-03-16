#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const string path = "/Users/mac/Documents/cpp/Code Jam/";

const int INF = 1000000000;

const int N = 200;
const int M = 10000;

int main() {
    ifstream cin(path + "in");
    ofstream cout(path + "out");
    
    int T;
    cin >> T;
    for (int CT = 1;  CT <= T; CT ++) {
        string s;
        cin >> s;
        
        int res = 0;
        
        string t;
        
        char prev = ' ';
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != prev)
                t += s[i];
            prev = s[i];
        }
        
        if (t[t.size() - 1] == '+')
            t = t.substr(0, t.size() - 1);
        
//        cout << t << endl;
        
        while (t.size() > 0) {
            if (t[0] == '+') {
                if (t.size() == 1)
                    break;
                
                t = t.substr(1, t.size() - 1);
//                cout << " .First " << t << endl;
                res ++;
                continue;
            }
            for (int i = 0; i < t.size(); i ++)
                t[i] = (t[i] =='+') ? '-' : '+';
            t = t.substr(0, t.size() - 1);
//            cout << " .Rev " << t << endl;
            res ++;
        }
        
        
        cout << "Case #" << CT << ": " << res << endl;
    }
    
    
    return 0;
}
