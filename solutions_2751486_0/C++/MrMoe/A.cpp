#include<iostream>
#include<string>
using namespace std;


int count(const char * s, int l, int n) {
    if (l < n)
        return 0;
    
    int max = 0;
    
    int number = 0;
    for (int i=0; i<l; i++) {

        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            if (number > max) {
                max = number;
            }
            number = 0;
            if ((l-i+number) < n)
                return max;
            break;
            
            default: number++;
        }
        if (max >= n) {
            return max;
        }
    }
    return (number > max) ? number : max;
}

int main() {
    int T;
    cin >> T;
    
    for (int t=0; t<T; t++) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        
        int L = s.length();
        const char * S = s.c_str();
        
        int value = 0;
        
        for (int l=L; l>0; l--) {
            for (int i=0; i<l; i++) {
                if (count(S+i, l-i, n) >= n) {
                    //cout << i << " " << (l-i) << endl;
                    value++;
                }
            }
        }
        
        cout << "Case #" << (t+1) << ": " << value << endl;
    }
    
}
