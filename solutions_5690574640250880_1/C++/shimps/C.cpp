#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> fun(int R, int C, int M) {
    if (R == 1) {
        vector<string> res(1,string(C,'.'));
        res[0][0] = 'c';
        while(M) {
            res[0][C-1] = '*';
            M--;
            C--;
        }
        return res;
    }
        if (M == 0) {
        vector<string> res(R,string(C,'.'));
        res[0][0] = 'c';
        return res;
    }
    if (M == R*C - 1) {
        vector<string> res(R,string(C,'*'));
        res[0][0] = 'c';
        return res;
    }
    if (R == 2) {
        if (M % 2) return vector<string>();
        if (M == R*C - 2) return vector<string>();
        vector<string> res(2,string(C,'.'));
        res[0][0] = 'c';
        while(M) {
            res[0][C-1] = '*';
            res[1][C-1] = '*';
            M -= 2;
            C--;
        }
        return res;
    }
    if (M == R*C - 4) {
        vector<string> res(R,string(C,'*'));
        res[0][0] = 'c';
        res[0][1] = res[1][0] = res[1][1] = '.';
        return res;
    }
    if (M == R*C - 6) {
        vector<string> res(R,string(C,'*'));
        res[0][0] = 'c';
        res[0][1] = res[1][0] = res[1][1] = res[2][0] = res[2][1] = '.';
        return res;
    }
    if (M == R*C - 8) {
        vector<string> res(R,string(C,'*'));
        res[0][0] = 'c';
        res[0][1] = res[0][2] = res[1][0] = res[1][1] = res[1][2] = res[2][0] = res[2][1] = '.';
        return res;
    }
    if (M == R*C - 2 || M == R*C - 3 || M == R*C - 5 || M == R*C - 7) return vector<string>();
    if (M <= (R*C) - (3*R)) {
        vector<string> res(R,string(C,'.'));
        res[R-1][C-1] = 'c';
        int mi = M;
        for(int i=0;i<C;i++) for(int j=0;j<R;j++) {
            res[j][i] = '*';
            M--;
            if (M == 0) {
                if (mi % R == R - 1) swap(res[j][i],res[0][i+1]);
                return res;
            }
        }
    }
    if (M <= (R*C) - (2*R) - 2) {
        vector<string> res(R,string(C,'.'));
        res[R-1][C-1] = 'c';
        for(int i=0;i<C;i++) for(int j=0;j<R;j++) {
            res[j][i] = '*';
            M--;
            if (M == 0) return res;
        }
    }
    if (M == (R*C) - (2*R) - 1) {
        vector<string> res(R,string(C,'.'));
        res[R-1][C-1] = 'c';
        for(int i=0;i<C;i++) for(int j=0;j<R;j++) {
            res[j][i] = '*';
            M--;
            if (M == 0) {
                swap(res[R-3][C-3],res[0][C-2]);
                swap(res[R-2][C-3],res[0][C-1]);
                return res;
            }
        }
    }
    vector<string> res(R,string(C,'.'));
    res[R-1][C-1] = 'c';
    for(int i=0;i<C-2;i++) for(int j=0;j<R;j++) {
        res[j][i] = '*';
        M--;
    }
    if (M == 0) return res;
    if (M%2) {
        res[R-1][C-3] = '.';
        res[R-2][C-3] = '.';
        res[R-3][C-3] = '.';
        M += 3;
    }
    for(int i=0;i<R;i++) {
        res[i][C-2] = '*';
        res[i][C-1] = '*';
        M -= 2;
        if (M == 0) break;
    }
    return res;
}

void do_case(int cn) {
    int R, C, M;
    cin >> R >> C >> M;
    int f = 0;
    if (R > C) {
        swap(R,C);
        f = 1;
    }
    vector<string> res = fun(R,C,M);
    if (res.size() == 0) {
      cout << "Case #" << cn << ":" << endl;
      cout << "Impossible" << endl;
      return;
    }
    if (f) {
        vector<string> tres = res;
        res = vector<string> (C,string(R,'.'));
        for(int i=0;i<C;i++) for(int j=0;j<R;j++) res[i][j] = tres[j][i];
        swap(R,C);
    }
    cout << "Case #" << cn << ":" << endl;
    for(int i=0;i<R;i++) cout << res[i] << endl;
}

int main() {
    int T;
    cin >> T;
    for(int cn = 1; cn <= T; cn++) {
        do_case(cn);
    }
    return 0;
}
