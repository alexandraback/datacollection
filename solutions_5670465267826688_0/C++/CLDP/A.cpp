#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int C[5][5] = {{0, 0, 0, 0, 0},
                     {0, 1, 2, 3, 4},
                     {0, 2, -1, 4, -3},
                     {0, 3, -4, -1, 2},
                     {0, 4, 3, -2, -1}};

int x[10010];


int cal(int A, int B) {
    int sign = 1;
    if (A < 0) sign = -sign;
    if (B < 0) sign = -sign;
    return sign * C[abs(A)][abs(B)];
}

int Qcal(int N, long long B) {
    int T = 1;
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < N; ++j) T = cal(T, x[j]);
        if (T == 1) {
            if (i == 0) return 1;
            B %= i;
            break;
        }
    }
    T = 1;
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < N; ++j) T = cal(T, x[j]);
    }
    return T;
}

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N;
        long long X;
        cin >> N >> X;
        string P;
        cin >> P;
        for (int i = 0; i < N; ++i) {
            switch (P[i]) {
                case 'i' : x[i] = 2; break;
                case 'j' : x[i] = 3; break;
                case 'k' : x[i] = 4; break;
            }
        }
        int temp = x[0];
        for (int i = 1; i < N; ++i) temp = cal(temp, x[i]);
        
        set<int> S;
        int B = 1, j = 0, t2 = 1;
        int flag = 2;
        while (X) {
            if (S.find(B) != S.end()) break;
            if (flag == 5) break;
            S.insert(B);
            while (j < N) {
                t2 = cal(t2, x[j]);
                if (t2 == flag) {
                    ++flag;
                    t2 = 1;
                    S.clear();
                }
                ++j;
            }
            j = 0;
            B = cal(B, temp);
            --X;
        }
        if (flag != 5) {
            cout << "Case #" << times << ": NO" << endl;
            continue;
        } 
        
        if (X > 0) {
            while (j < N) {
                t2 = cal(t2, x[j]);
                ++j;
            }
        }
        --X;
        
        int QQ = 1;
        if (X > 0) t2 = cal(t2, Qcal(N, X));
        
        if (t2 == 1)
            cout << "Case #" << times << ": YES" << endl;
        else
            cout << "Case #" << times << ": NO" << endl;
    }
    return 0;
}
