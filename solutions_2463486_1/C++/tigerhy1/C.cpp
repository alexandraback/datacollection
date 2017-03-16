#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;

 
typedef long long llong; 
vector<llong> v; 
const llong MAX = 10000000; 

bool palindrome(llong x) {
   vector<int> a; 
   llong tmp = x; 
   while (tmp > 0) {
       a.push_back(tmp % 10);
       tmp /= 10;  
   }
   bool flag = true; 
   int len = a.size(); 
   for (int i = 0; i < len / 2; i++) {
       if (a[i] != a[len - 1 -i]) {
           flag = false; 
           break; 
       }
   } 
   return flag; 
}

void init() {
    v.clear(); 
    v.push_back(0); 
    for (llong i = 1; i <= 10000000; i++) {
        if (palindrome(i) && palindrome(i*i)) {
            v.push_back(i*i); 
            //cout << i << " " << i*i << endl; 
        }        
    }    
   // cout << "size = " << v.size() << endl; 
}

//get total count of <= x
int get_count(llong x) {
    int a = 0; 
    int b = v.size() - 1; 
    
    while (a < b) {
        int m = (a + b + 1) / 2; 
        if (x < v[m]) {
            b = m - 1; 
        }
        else if (x > v[m]) {
            a = m; 
        }
        else {
            a = m; 
            break; 
        }
    }
    return a + 1;  
}

int solve(llong from, llong to, int t) {
    int x = get_count(from - 1);
    int y = get_count(to);
    int res = y - x; 
    cout << "Case #" << t << ": " << res << endl;
    //cout << x << " " << y << endl; 
}

int main() {
    int T; 
    llong a, b; 
    cin >> T; 
    init(); 
    for (int i = 0; i < T; i++) {
        cin >> a; 
        cin >> b; 
        solve(a, b, i + 1);         
    }
}









