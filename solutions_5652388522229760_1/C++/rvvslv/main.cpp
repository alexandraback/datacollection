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

int rem = 10;
bool d[10];

void init() {
    rem = 10;
    fill(d, d + 10, false);
}

void digitize(long long a) {
    while (a > 0) {
        if (!d[a % 10]) {
            rem --;
            d[a % 10] = true;
        }
        a /= 10;
    }
}

int main() {
    ifstream cin(path + "in");
    ofstream cout(path + "out");
    
    int T;
    cin >> T;
    for (int CT = 1;  CT <= T; CT ++) {
        int n;
        cin >> n;
        
        long long x = 0;
        init();
        
        for (int i = 0; i < 1000000; i ++) {
            x += n;
            
            digitize(x);
            
            if (rem == 0)
                break;
        }
        
        if (rem > 0)
            cout << "Case #" << CT << ": INSOMNIA" << endl;
        else
            cout << "Case #" << CT << ": " << x << endl;
    }
    
    
    return 0;
}
