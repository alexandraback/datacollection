#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define I 2
#define J 3
#define K 4

using namespace std;

inline int mul(int a, int b) {
    bool negative = a*b < 0;
    a = abs(a);
    b = abs(b);
    int ans;
    switch (a) {
        case 1:
            switch (b) {
                case 1: ans =  1; break;
                case I: ans =  I; break;
                case J: ans =  J; break;
                case K: ans =  K; break;
            }
            break;
        case I:
            switch (b) {
                case 1: ans =  I; break;
                case I: ans = -1; break;
                case J: ans =  K; break;
                case K: ans = -J; break;
            }
            break;
        case J:
            switch (b) {
                case 1: ans =  J; break;
                case I: ans = -K; break;
                case J: ans = -1; break;
                case K: ans =  I; break;
            }
            break;
        case K:
            switch (b) {
                case 1: ans =  K; break;
                case I: ans =  J; break;
                case J: ans = -I; break;
                case K: ans = -1; break;
            }
            break;
    }
    return negative ? -ans : ans;
}


int main() {
    
    cin.tie(0);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        
        int L, X;
        cin >> L >> X;
        cin.ignore();
        int s[L]; // it is enough to try 48 repetitions
        for (int i = 0; i < L; i++) {
            char c;
            cin >> c;
            s[i] = c - 'k' + K;
        }
        
        int goal = I;
        int val = 1;
        for (int i = 0; i < L*X; i++) {
            val = mul(val, s[i%L]);
            if (val == goal) {
                val = 1;
                goal++;
            }
        }
        
        cout << "Case #" << tc << ": " << (goal == K+1 && val == 1 ? "YES" : "NO") << endl;
    }

    return 0;
}
