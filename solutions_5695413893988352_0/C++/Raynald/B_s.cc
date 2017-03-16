#include<bits/stdc++.h>

using namespace std;

bool check(int x, string y) {
    int z = x;
    for(int i = y.length() - 1;i >= 0;i --) {
        if (y[i] != '?' && y[i] - '0' != z % 10) return 0;
        z /= 10;
    }
    return 1;
}

int main() {
    int T;
    string C, J;
    int ans_i, ans_j;
    string A, B;

    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> C >> J;
        ans_i=1000;ans_j=0;
        for(int i = 0; i <= 999;i ++) {
            if (C.length() == 1 && i > 9) break;
            if (C.length() == 2 && i > 99) break;
            if(!check(i, C)) continue;
            for(int j = 0;j <= 999;j ++) {
                if (J.length() == 1 && j > 9) break;
                if (J.length() == 2 && j > 99) break;
                if (!check(j, J)) continue;
                if (abs(i - j) < abs(ans_i - ans_j)) {
                    ans_i = i; ans_j = j;
                }
            }
        }
        A = to_string(ans_i);
        while(A.length()< C.length()) A = '0' + A;
        B = to_string(ans_j);
        while(B.length()< J.length()) B = '0' + B;
        cout << "Case #" << testcase << ": " << A << " " << B << endl;
    }
    return 0;
}
