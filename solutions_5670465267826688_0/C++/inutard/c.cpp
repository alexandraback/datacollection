#include <bits/stdtr1c++.h>

using namespace std;

typedef complex<int> pt;
struct mat2 {
    pt a[2][2];
    mat2() {}
    mat2(pt p, pt q, pt r, pt s) {
        a[0][0] = p; a[0][1] = q;
        a[1][0] = r; a[1][1] = s;
    }
    bool operator==(mat2& o) const {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (a[i][j] != o.a[i][j]) return false;
            }
        }
        return true;
    }
};

mat2 operator*(mat2 a, mat2 b) {
    pt arr[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arr[i][j] += a.a[i][k]*b.a[k][j];
            }
        }
    }
    return mat2(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
}

pt I(0, 1);
mat2 i(I, 0, 0, -I),
     j(0, 1, -1, 0),
     k(0, I, I, 0);
map<char, mat2> q({{'i', i}, {'j', j}, {'k', k}});

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        int L, X; cin >> L >> X;
        string s; cin >> s;
        
        mat2 base(1, 0, 0, 1);
        for (char c : s) {
            base = base*q[c];
        }
        
        mat2 curr(1, 0, 0, 1);
        int cnt = 0, idx = 0, iters = 0;
        mat2 nxt[3] = {i, j, k};
        while (cnt < 3) {
            if (idx == L) {
                idx = 0;
                iters++, X--;
            }
            if (X == 0 || iters > 10) break;
            
            curr = curr * q[s[idx++]];
            if (curr == nxt[cnt]) {
                cnt++;
                curr = mat2(1, 0, 0, 1);
            }
        }
        
        bool yes = (cnt == 3);
        
        mat2 ans(1, 0, 0, 1);
        while (X > 0 && idx < L) ans = ans*q[s[idx++]];
        X--;
        
        for (long long bs = 1; bs <= X; bs*=2) {
            if (X & bs) {
                ans = ans*base;
            }
            base = base*base;
        }
        yes = yes && ans.a[0][0] == 1 && ans.a[1][1] == 1;
        
        cout << "Case #" << ca << ": " << (yes ? "YES" : "NO") << endl;
    }
	return 0;
}