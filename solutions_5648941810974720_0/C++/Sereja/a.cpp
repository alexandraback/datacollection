#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>

using namespace std;

/*
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
"ONE", "TWO", "THREE", "FOUR", "FIVE", "SEVEN", "EIGHT", "NINE"
"ONE", "TWO", "THREE", "FOUR", "FIVE", "SEVEN", "NINE"
"ONE", "TWO", "THREE", "FIVE", "SEVEN", "NINE"
"ONE", "TWO", "THREE", "SEVEN", "NINE"
"ONE", "THREE", "SEVEN", "NINE"
"ONE", "SEVEN", "NINE"
"SEVEN", "NINE"
"SEVEN" */

int order[10] = {0, 6, 8, 4, 5, 2, 3, 1, 9, 7};

int z[111];
string s;
const string cdigits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> digits[10];
vector<int> ans;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cdigits[i].size(); j++) {
            digits[i].push_back(cdigits[i][j] - 'A');
        }
    } 
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);        
    int testCases;
    cin >> testCases;    
    for (int testCase = 1; testCase <= testCases; testCase++) {
        cout << "Case #" << testCase << ": ";
        
       cin >> s;
       memset(z, 0, sizeof(z));
       for (int i = 0; i < s.size(); i++) {
           z[s[i] - 'A']++;
       }
       
       ans.clear();
       for (int i = 0; i < 10; i++) {
           int ok = 1;
           while (ok) {
               for (int j = 0; j < digits[order[i]].size(); j++) {
                   z[digits[order[i]][j]]--;
                   if (z[digits[order[i]][j]] < 0) {
                       ok = 0;
                   }
               }
               if (!ok) {
                   for (int j = 0; j < digits[order[i]].size(); j++) {
                       z[digits[order[i]][j]]++;                        
                   }
               } else {
                   ans.push_back(order[i]);
               }
           }
       }
       for (int i = 0; i < 10; i++) {
           if (z[i] != 0) {
               return 123;
           }
       }
       sort(ans.begin(), ans.end());
       for (int i = 0; i < ans.size(); i++) {
           cout << ans[i];
       }
       cout << endl;
    } 
    return 0;
}