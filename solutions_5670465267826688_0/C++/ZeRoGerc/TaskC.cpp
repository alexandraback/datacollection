#include <iostream>
#include <string>

using namespace std;

int T, it = 0, n;
string s;
int a[10100];

const char mul[5][5] {
    {0,  0,  0,  0,  0},
    {0,  1,  2,  3,  4},
    {0,  2,  -1, 4,  -3},
    {0,  3,  -4, -1, 2},
    {0,  4,  3,  -2, -1}
};



int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    cin >> T;
    
    int l, x;
    for (int I = 0; I < T; I++) {
        cin >> l >> x;
        string ss;
        cin >> ss;
        s = "";
        for (int i = 0; i < x; i++) {
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
        
        int cur = 1, temp, l = n + 1, r = -1;
        for (int i = 0; i < n; i++) {
            temp = mul[abs(cur)][a[i]];
            if (cur < 0) {
                temp = -temp;
            }
            cur = temp;
            if (cur == 2) {
                l = i;
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
                r = i;
                break;
            }
        }
        
        if (r - l > 1) {
            cur = 1;
            for (int i = 0; i < n; i++) {
                temp = mul[abs(cur)][a[i]];
                if (cur < 0) {
                    temp = -temp;
                }
                cur = temp;
            }
            
            if (cur == -1) {
                printf("Case #%d: YES\n", I + 1);
            } else {
                printf("Case #%d: NO\n", I + 1);
            }
        } else {
            printf("Case #%d: NO\n", I + 1);
        }
    }
}