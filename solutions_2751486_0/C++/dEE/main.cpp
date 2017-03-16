//
//  main.cpp
//  TestCppCode
//

#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

bool is_palindrome(long long n) {
    int len = (int)log10(n) + 1;
    char num[len];
    sprintf(num, "%lld", n);
    int mid = len>>1;
    for (int i=0; i<mid; i++) {
        if (num[i] != num[len-1-i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        string s; int n;
        cin >> s >> n;
        int size = (int)s.size();
        int isVowel[size];
        for (int i=0; i<size; i++) isVowel[i] = (s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u');
        int count = 0;
        for (int i=0; i<size; i++) {
            for (int j=i; j<size; j++) {
                int temp = 0, max = INT_MIN;
                for (int k=i; k<=j; k++) {
                    if (!isVowel[k]) temp++;
                    else temp = 0;
                    if (temp > max) max = temp;
                }
                if (max >= n) count++;
            }
        }
        printf("Case #%d: %d\n", t, count);
    }
}