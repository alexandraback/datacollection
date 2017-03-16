#include <iostream>
#include <string>

using namespace std;

long long T, it = 0, n, l, x;
string s, ss;
long long a[80100];

const char mul[5][5] {
    {0,  0,  0,  0,  0},
    {0,  1,  2,  3,  4},
    {0,  2,  -1, 4,  -3},
    {0,  3,  -4, -1, 2},
    {0,  4,  3,  -2, -1}
};

long long findsum() {
    long long cur = 1, temp;
    for (int i = 0; i < l; i++) {
        temp = mul[abs(cur)][a[i]];
        if (cur < 0) {
            temp = -temp;
        }
        cur = temp;
    }
    
    long long cc = cur;
    for (int i = 1; i < x % 4; i++) {
        temp = mul[abs(cur)][abs(cc)];
        if ((cur < 0 && (cc > 0)) || ((cur > 0) && (cc < 0))) {
            temp = -temp;
        }
        cur = temp;
    }
    
    return cur;
}


int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    cin >> T;

    for (int I = 0; I < T; I++) {
        cin >> l >> x;
        cin >> ss;
        
        for (int i = 0; i < l; i++) {
            switch (ss[i]) {
                case '1':
                    a[i] = 1;
                    break;
                case 'i':
                    a[i] = 2;
                    break;
                case 'j':
                    a[i] = 3;
                    break;
                case 'k':
                    a[i] = 4;
                    break;
            }
        }
        
        if (findsum() != -1) {
            printf("Case #%d: NO\n", I + 1);
            continue;
        }
            
        s = "";
        for (int i = 0; i < min(x, 8ll); i++) {
            s += ss;
        }
        
        n = (int)s.size();
        it++;
        
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case '1':
                    a[i] = 1;
                    break;
                case 'i':
                    a[i] = 2;
                    break;
                case 'j':
                    a[i] = 3;
                    break;
                case 'k':
                    a[i] = 4;
                    break;
            }
        }
        
        long long cur = 1, temp, left = l * x, right = -1;
        for (int i = 0; i < n; i++) {
            temp = mul[abs(cur)][a[i]];
            if (cur < 0) {
                temp = -temp;
            }
            cur = temp;
            if (cur == 2) {
                left = i;
                break;
            }
        }
        
        cur = 1;
        for (int i = n - 1; i >= 0; i--) {
            temp = mul[a[i]][abs(cur)];
            if (cur < 0) {
                temp = -temp;
            }
            cur = temp;
            if (cur == 4) {
                right = i;
                break;
            }
        }
        
        if ((l * x - (n - right)) - left > 1) {
            printf("Case #%d: YES\n", I + 1);
        } else {
            printf("Case #%d: NO\n", I + 1);
        }
    }
}