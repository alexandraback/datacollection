#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const string path = "/Users/mac/Documents/cpp/Code Jam/";

const int N = 100000;

int p[N];
int pc = 0;

int isPrime(long long x) {
    for (int i = 0; i < pc && (long long)p[i] * p[i] <= x; i ++)
        if (x % p[i] == 0)
            return p[i];
    return -1;
}

long long interpret(long long x, int base) {
    long long r = 0;
    long long c = 1;
    while (x) {
        if (x % 2)
            r += c;
        c *= base;
        x /= 2;
    }
    return r;
}

int main() {
    ifstream cin(path + "in");
    ofstream cout(path + "out");
    
    p[pc ++] = 2;
    
    for (int i = 3; pc < N; i += 2) {
        if (isPrime(i) == -1)
            p[pc ++] = i;
    }
    
    int T;
    cin >> T;
    for (int CT = 1;  CT <= T; CT ++) {
        long long n, j;
        cin >> n >> j;
        
        cout << "Case #" << CT << ": " << endl;
        
        long long x = (1ll << n) - 1;
        
        vector<int> res;
        
        for (; ; x -= 2) {
            int d = isPrime(x);
            if (d != -1) {
                res.clear();
                res.push_back(d);
                bool ok = true;
                for (int i = 3; i <= 10; i ++) {
                    
                    int d = isPrime(interpret(x, i));
                    //cout << x << " - " << i << " = " << interpret(x, i) << " / " << d << endl;
                    if (d == -1) {
                        ok = false;
                        break;
                    }
                    res.push_back(d);
                }
                if (ok) {
                    j --;
                    string r;
                    long long t = x;
                    while (t) {
                        r = ((t % 2) ? '1' : '0') + r;
                        t /= 2;
                    }
                    cout << r;
                    for (int i = 2; i <= 10; i ++)
                        cout << " " << res[i - 2];
                    cout << endl;
                    if (j == 0)
                        break;
                }
            }
        }
    }
    
    
    return 0;
}
