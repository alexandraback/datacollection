#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool plim[10100000];

bool palim(long long a) {
    vector<int> p;
    while (a > 0) {
        p.push_back(a % 10);
        a = a / 10;      
    }
    for (int i = 0; i < p.size(); ++i)
     if (p[i] != p[p.size() - 1 - i]) return false;
    return true;
}


bool check(long long a) {
    long long b = (long long)sqrt(a);
    if (b * b != a) return false;
    if (!palim(b)) return false;
    if (!palim(a)) return false;
    
    return true;
}


int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int tt;
    cin >> tt;
    
    vector<long long> ans;
    
    for (long long i = 1; i <= 10000000; ++i) {
        if (palim(i) && palim(i*i)) ans.push_back(i*i);
    }
    
    int len = ans.size();
    
    long long a, b;
    for (int ttt = 1; ttt <= tt; ++ttt) {
        cin >> a >> b;    
        int i = 0, j;
        while (i < len && ans[i] < a) ++i;
        j = i;
        while (j < len && ans[j] <= b) ++j;
        cout << "Case #" << ttt << ": " << j-i << endl;
    }
    
    
    return 0;    
}
