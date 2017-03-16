#include<iostream>

using namespace std;

long long pow (long long a, int n) {
    long long result = 1;
    while (n) {
        if (n & 1)
            result *= a;
        a *= a;
        n >>= 1;          
    }
    return result;
}

int main () {
    int T; cin >> T;
    for (int step=1; step<=T; step++) {
        long long r,t; cin >> r >> t;
        long long result = 0;
        long long begin = 0, end = 1;
        while (2*end*(r + end - 1) + end < t)
            end *= 2;
        while (begin < end) { 
            long long middle = begin + (end - begin)/2;
            if (2*(middle+1)*(r + middle) + middle + 1 < t)
                begin = middle + 1;
            else if (2*(middle+1)*(r + middle) + middle + 1 == t) {
                 begin = middle+1;
                 break;
            }    
            else end = middle;         
        }
        cout << "Case #" << step << ": " << begin << endl;
    }
    return 0;
}
