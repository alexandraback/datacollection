/*
 * =============================================================================
 *
 *       Filename:  CounterCulture.cpp
 *
 *    Description:  Counter Culture
 *
 *        Created:  05/02/2015 01:05:27 PM
 *       Compiler:  gcc/g++
 *
 *         Author:  Lawrence Wu (llwu), llwu@mit.edu
 *   Organization:  Massachusetts Institute of Technology
 *
 * =============================================================================
 */

#include <iostream>
using namespace std;

long long places[16];

long long solve(long long x)
{
    long long ans = 0;
    while(true) {
        int digits[16];
        int len = 0;
        for(long long i = x; i; i /= 10) { digits[len] = i % 10; len++; }
        if(digits[0] == 0) { ans +=  9; x -= 9; continue; }
        else if(digits[0] != 1) { ans += digits[0] - 1; x -= digits[0] - 1; }
        else if(len == 1) return ans + 1;
        else {
            long long a = 0, b = 0;
            for(int i = 1; i <= (len-1)/2; i++) b += digits[i]*places[i];
            for(int i = len-2; i > (len-1)/2; i--) a += digits[i]*places[len-1-i];
            long long rev = 0;
            for(int i = 0; i < len; i++) rev += digits[len - 1 - i]*places[i];
            if(a == 0 && b == 0 && rev == x) { ans += 10; x -= 10; }
            else if(b != 0) {ans += b; x -= b; }
            else { ans += 1; x = rev; }
        }
    }
}

int main()
{
    places[0] = 1;
    for(int i = 1; i < 16; i++) places[i] = 10*places[i-1];
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        long long N;
        cin >> N;
        cout << "Case #" << i << ": " << solve(N) << '\n';
    }
    return 0;
}
