
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int solve(string s) {
    int value;
    int count = 0;
    int inviteds = 0;
   
    for (int i = 0; i < s.size(); i++) {
        value = s[i] - '0';
        
        if (value > 0 && i > count) {
           inviteds += i - count;
           count += i - count;
        }
        
        count += value;
    }
    
    return inviteds;
}

int main (void) {
    int t, n;
    string s;
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    cin >> t;    
    
    for (int cs = 1; cs <= t; cs++) {
        cin >> n >> s;
        
        cout << "Case #" << cs << ": ";
        cout << solve(s) << endl;
    }
    
    return 0;
}
