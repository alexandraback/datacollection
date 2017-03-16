#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int Case , _;
string s;
void solve(){
    cin >> s;
    int m = unique(s.begin() , s.end()) - s.begin();
    if (s[s.length() - 1] == '+') m--;
    printf("Case #%d: %d\n" , ++Case, m);
}
int main(){
    freopen("B-large.in" , "r" , stdin);
    freopen("B.out" , "w" , stdout);
    cin >> _;
    Case = 0;
    while(_--) solve();
}
