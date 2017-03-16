#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool isPalindrom(long n) {
    vector <short> c;
    while (n) {
        c.push_back(n % 10);
        n /= 10;
    }
    
    for (int i = 0; i < c.size()/2; ++i)
        if (c[i] != c[c.size() - 1 - i])
            return false;
    
    return true;
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    short arr[1007] = {0};
    for (long i = 1; i*i <= 1000; ++i)
        if (isPalindrom(i) && isPalindrom(i * i))
            arr[i * i] = 1;
    
    long T;
    cin >> T;

    for (long t = 0; t < T; ++t) {
        long a, b, ans = 0;
        cin >> a >> b;
        for (long i = a; i <= b; ++i)
            ans += arr[i];
        
        printf ("Case #%ld: %ld\n", t+1, ans);
    }
    
}