#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 
#include <sstream>
using namespace std; 

typedef long long llong; 

llong r, t; 

void solve(int cas) {
    
    llong a = 1;
    llong b = t/(2*r);   
    
    while (a < b) {
        llong n = (a + b + 1) / 2; 
        if (r+n <= (t/n+1)/2) {
           a = n; 
        }
        else {
           b = n - 1; 
        }
    }
    cout << "Case #" << cas << ": " << a << endl; 
}

int main() {
    int T; 
    cin >> T; 
    for (int i = 0; i < T; i++) {
        cin >> r >> t; 
        solve(i + 1); 
    }
    //system("pause"); 
}
