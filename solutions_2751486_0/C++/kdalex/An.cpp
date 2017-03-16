#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> s;
        cin >> n;
        int cnt = 0;
        for(int l = 0; l < s.size(); l++) {
            for(int r = l; r < s.size(); r++) {
                int cntt = 0, b = -1;
                for(int j = l; j <= r; j++) {
                    if(s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'i' || s[j] == 'u') {
                        if(cntt >= n) {
                            break;
                        }
                        cntt = 0;
                        b = -1;
                    } else {
                        if(!cntt) {
                            b = j;    
                        }
                        cntt++;
                    }
                }
                if(cntt >= n)
                    cnt++;
            }
        }
        cout << "Case #" << i + 1 << ": " << cnt << endl;
    }
    return 0;
}