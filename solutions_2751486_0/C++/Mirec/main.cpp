#include <iostream>

using namespace std;

inline 
bool isConsonant( char ch ) {
    return 
        ch != 'a' &&
        ch != 'e' &&
        ch != 'i' &&
        ch != 'o' &&
        ch != 'u';
}

int main(int argc, char **argv) {
    int t, T, n, i, j, value;
    int position, consecutiveStart;
    int currentCount;
    char ch;
    string s;
    s.reserve(1024000);
    
    cin >> T;
    
    for( t = 1; t <= T; t++ ) {
        cin >> s >> n;
        
        value = 0;
        currentCount = 0;
        for( i = 0; i < s.size(); i++ ) {
            if( isConsonant(s[i] ) ) {
                currentCount++;
                if( currentCount == n) {
                    consecutiveStart = i-n+1;
                    break;
                }
            } else {
                currentCount = 0;
            }
        }
        
        for(;i<s.size();i++ ) {
            if( isConsonant(s[i] ) ) {
                currentCount++;
                if( currentCount >= n) {
                    consecutiveStart = i-n+1;
                }
            } else {
                currentCount = 0;
            }
            value += consecutiveStart+1;
        }
        cout << "Case #" << t <<": " << value << endl;
    }
    
    return 0;
}
