#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    string s;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> s;
        int l = s.length();
        int r = 0;
        
        for (int j = 1; j < l; j++) {
            if (s[j-1] != s[j]) r++;
        }
        if (s[l-1] == '-') r++;
        
        cout << "Case #" << i+1 << ": " << r << endl;
    }
    return 0;
}
