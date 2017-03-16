#include <iostream>
#include <cassert>

using namespace std;


void remove(string& s, char c, int n) {
    for (int i = 0; i < s.length() && n > 0; i++) {
        if (s[i] == c) {
            s[i] = ' ';
            n--;
        }
    }
}


int main() {
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        string s;
        cin >> s;
        
        int d[10];
        fill(d, d+10, 0);
        
        d[0] = count(s.begin(), s.end(), 'Z');
        remove(s, 'Z', d[0]);
        remove(s, 'E', d[0]);
        remove(s, 'R', d[0]);
        remove(s, 'O', d[0]);
        
        d[2] = count(s.begin(), s.end(), 'W');
        remove(s, 'T', d[2]);
        remove(s, 'W', d[2]);
        remove(s, 'O', d[2]);
        
        d[4] = count(s.begin(), s.end(), 'U');
        remove(s, 'F', d[4]);
        remove(s, 'O', d[4]);
        remove(s, 'U', d[4]);
        remove(s, 'R', d[4]);
        
        d[5] = count(s.begin(), s.end(), 'F');
        remove(s, 'F', d[5]);
        remove(s, 'I', d[5]);
        remove(s, 'V', d[5]);
        remove(s, 'E', d[5]);
        
        d[6] = count(s.begin(), s.end(), 'X');
        remove(s, 'S', d[6]);
        remove(s, 'I', d[6]);
        remove(s, 'X', d[6]);
        
        d[7] = count(s.begin(), s.end(), 'V');
        remove(s, 'S', d[7]);
        remove(s, 'E', d[7]);
        remove(s, 'V', d[7]);
        remove(s, 'E', d[7]);
        remove(s, 'N', d[7]);
        
        d[8] = count(s.begin(), s.end(), 'G');
        remove(s, 'E', d[8]);
        remove(s, 'I', d[8]);
        remove(s, 'G', d[8]);
        remove(s, 'H', d[8]);
        remove(s, 'T', d[8]);
        
        d[9] = count(s.begin(), s.end(), 'I');
        remove(s, 'N', d[9]);
        remove(s, 'I', d[9]);
        remove(s, 'N', d[9]);
        remove(s, 'E', d[9]);
        
        d[1] = count(s.begin(), s.end(), 'O');
        remove(s, 'O', d[1]);
        remove(s, 'N', d[1]);
        remove(s, 'E', d[1]);
        
        d[3] = count(s.begin(), s.end(), 'T');
        remove(s, 'T', d[3]);
        remove(s, 'H', d[3]);
        remove(s, 'R', d[3]);
        remove(s, 'E', d[3]);
        remove(s, 'E', d[3]);
        
        assert(count(s.begin(), s.end(), ' ') == s.length());
        
        cout << "Case #" << t+1 << ": ";
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < d[i]; j++) {
                cout << i;
            }
        }
        cout << endl;
        
    }
}