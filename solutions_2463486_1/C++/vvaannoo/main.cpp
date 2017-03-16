#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <set>
using namespace std;
int k = 0;

bool isPal(long long x) {
    if(x < 1) return false;    
    long long p = 0, y = x, d = 1;
    do {
        p *= 10;
        p += y % 10;
    } while (y /= 10);
    return x == p;
}

long long nextPal(long long a) {
    a++;
    int A, B, n = 0;
    int x = a;
    do{
        n++;
    }while(x/=10);
    x = (n >> 1);
    A = a / pow10(x);
    do{
        x = A;
        B = (n&1) ? x / 10 : x;
        do{
            if(B) x = x * 10 + B%10;
        }while(B/=10);
        A++;
    }while(x < a);
    return x;
}

int main() {
    freopen("C-large-1.in", "r", stdin);
    freopen("C-large-1.out", "w", stdout);
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int ans = 0;
        long long a, b, A, B;
        cin >> a >> b;
        A = sqrt(a-1);
        do{
            A = nextPal(A);
            B = A * A;
            if(B > b) break;
            if (isPal(B)) {
                ans++;
            }
        }while(true);
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
