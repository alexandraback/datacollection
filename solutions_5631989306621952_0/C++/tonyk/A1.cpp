#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    int t;
    string s;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> s;
        char c;
        deque<char> d;
        int len = s.length();
        
        for (int j = 0; j < len; j++) {
            if (j == 0) d.push_back(s[j]);
            else {
                if (s[j] >= d[0]) d.push_front(s[j]);
                else d.push_back(s[j]);
            }
        }
        
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < len; j++) {
            cout << d[j];
        }
        cout << endl;
    }
    
    return 0;
}
