#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

bool isConsonant(char s) {
    if ( s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string s; 
        int n;
        cin >> s >> n;
        int beginString = 0;
        int start, end;
        int result = 0;
        bool br = false;
        for (int j = 0; j < s.size(); j++) {
            int k = 0;
            for (k = 0; k < n; k++) {
                if ( j + k == s.size() ) {
                    br = true; break;
                }
                if (isConsonant(s[j+k]) == false)
                    break;
            }
            if(br) break;
            if (k == n) {
                start = j;
                end = j + n;
                int left = start - beginString;
                int right = s.size() - end;
                beginString = j + 1;
                result = result + 1 + left + right + left*right;
            } 
        }
        cout << "Case #" << i << ": " << result << endl;
    }
   
}







