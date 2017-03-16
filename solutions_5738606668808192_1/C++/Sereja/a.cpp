#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>

#define div divisor

using namespace std;

int q[100];
int div[100];
int n, amount;

void gen(int where) {
    if (where == n) {        
        for (int systm = 2; systm <= 10; systm++) {
            bool ok = false;
            for (int d = 2; d <= 1000; d++) {
                int ost = 0;
                for (int l = 1; l <= n; l++) {
                    ost = (ost * systm + q[l]) % d;
                }
                if (ost == 0) {
                    ok = true;
                    div[systm] = d;
                    break;
                }                
            }
            if (!ok) {
                break;
            }
            if (systm == 10) {
                for (int i = 1; i <= n; i++) {
                    cout << q[i];
                }
                for (int i = 2; i <= 10; i++) {
                    cout << " " << div[i];
                }
                cout << endl;
                
                amount--;
                if (amount == 0) {
                    exit(0);
                }
            }
        }
        return;
    } 
    q[where] = 0;
    gen(where + 1);
    q[where] = 1;
    gen(where + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": " << endl;
           
        cin >> n >> amount;
        
        q[1] = 1;
        q[n] = 1;
        gen(2);
    } 
    return 0;
}