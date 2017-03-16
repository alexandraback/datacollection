#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool plim[1010];


bool check(long long a) {
    long long b = (long long)sqrt(a);
    if (b * b != a) return false;
    vector<int> p;
    while (b > 0) {
        p.push_back(b % 10);
        b = b / 10;      
    }
    for (int i = 0; i < p.size(); ++i)
     if (p[i] != p[p.size() - 1 - i]) return false;
    
    p.clear();
    
    while (a > 0) {
        p.push_back(a % 10);
        a = a / 10;      
    }
    for (int i = 0; i < p.size(); ++i)
     if (p[i] != p[p.size() - 1 - i]) return false;
    
    return true;
}


int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int tt, a, b;
    cin >> tt;
    
    for (int i = 1; i <= 1000; ++i) plim[i] = check(i);
    
    for (int ttt = 1; ttt <= tt; ++ttt) {
        cin >> a >> b;    
        int ans = 0;
        for (int i = a; i <= b; ++i) 
         if (plim[i]) ++ans; 
        cout << "Case #" << ttt << ": " << ans << endl;
    }
    
    return 0;    
}
