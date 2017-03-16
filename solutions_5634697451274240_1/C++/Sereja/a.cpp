#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>

using namespace std;

int solve(string s) {
   s += '+';
   int ans = 0;
   for (int i = 0; i + 1 < s.size(); i++) {
       if (s[i] != s[i + 1]) {
           ans++;
       }
   }
   return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": ";
        
        string s;
        cin >> s;
        
        cout << solve(s) << endl;
    } 
    return 0;
}