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
#define END 5

using namespace std;

inline long long mul(long long a, long long b) {
    bool negative = a*b < 0;
    a = abs(a);
    b = abs(b);
    long long ans;
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
    
    long long TC;
    cin >> TC;
    for (long long tc = 1; tc <= TC; tc++) {
        
        long long L, X;
        cin >> L >> X;
        cin.ignore();
        long long s[L];
        for (long long i = 0; i < L; i++) {
            char c;
            cin >> c;
            s[i] = c - 'k' + K;
        }
        
        long long goal = I;
        long long val = 1;
        for (long long i = 0; i < X; i++) {
            
            // if we haven't made a 'k' in 48 repetitions we will never make it
            if (i == 48 && goal != END) break;
            
            // if we haven't made a '1' in the start in 64 repetitions we will never make it
            if (i == 64 && val != 1) break;
            
            if (goal == END && val == 1) {
                long long cycle = 1;
                while (cycle < 20) {
                    for (long long j = 0; j < L; j++) {
                        val = mul(val, s[j]);
                    }
                    if (val == 1) break;
                    cycle++;
                }
                if (cycle < 20) {
                    long long remaining = X-i;
                    if (remaining % cycle != 0) {
                        goal = 0;
                    }
                } else {
                    goal = 0;
                }
                break;
            }
            
            for (long long j = 0; j < L; j++) {
                val = mul(val, s[j]);
                if (val == goal) {
                    val = 1;
                    goal++;
                }
            }
        }
        
        cout << "Case #" << tc << ": " << (goal == END && val == 1 ? "YES" : "NO") << endl;
    }

    return 0;
}
