#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <set>

using namespace std;

string s[2111];
string w[2111];


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);        
    int testCases;
    cin >> testCases;    
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": ";
        
        set<string> Ss;
        set<string> Ww;
        
        int n;
        
        cin >> n;
        for (int i = 0; i < n; i++) {            
            cin >> s[i] >> w[i];
            Ss.insert(s[i]);
            Ww.insert(w[i]);
        }
        
        int best = 0;        
        for (int i = 0; i < (1 << n); i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) {
                    int ok = 0;
                    for (int l = 0; l < n; l++) { 
                        if (i & (1 << l)) {
                            if (s[l] == s[j]) {
                                ok = 1;
                            }
                        }                        
                    }
                    if (ok) {
                       ok = 0;
                       for (int l = 0; l < n; l++) { 
                            if (i & (1 << l)) {
                                if (w[l] == w[j]) {
                                    ok = 1;
                                }
                            }                        
                        } 
                        if (ok) {
                            temp++;
                        }
                    }
                }
            }
            best = max(best, temp);            
        }
        
        
        cout << best << endl; // n - max(Ss.size(), Ww.size()) << endl;               
        
        //cout << n - max(Ss.size(), Ww.size()) << endl;
    } 
    return 0;
}