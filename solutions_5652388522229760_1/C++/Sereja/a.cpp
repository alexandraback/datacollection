#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>

using namespace std;

bool seen[10];

int solve(int x) {
    memset(seen, false, sizeof(seen));
    for (int i = 1; i <= 1000; i++) {
        int y = i * x;
        while (y > 0) {
            seen[y % 10] = true;
            y /= 10;
        }
        bool ok = true;
        for (int j = 0; j < 10; j++) {
            if (!seen[j]) {
                ok = false;
            }
        }
        if (ok) {
            return i * x;
        }
    }    
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": ";
        
        int x;
        cin >> x;
        int rez = solve(x);
        if (rez < 0) {
            cout << "INSOMNIA" << endl;
        } else {
            cout << rez << endl;
        }
    } 
    return 0;
}