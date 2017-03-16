#include <iostream>
using namespace std;

#define MAXN 1024

struct level {
    int a, b;
    bool va, vb;
} n[MAXN];

int main() {
    int N, i, S, maxb, RES, t, T;
    bool flag;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> N;
        for (i=0; i<N; i++) {
            cin >> n[i].a;
            cin >> n[i].b;
            n[i].va = n[i].vb = true;
        }
    
        S = RES = 0;
        do {
            flag = false; maxb = -1;
            for (i=0; i<N && !flag; i++) {
                if (n[i].vb == true && n[i].b <= S) {
                    if (n[i].va == true) {n[i].va = false; S++;}
                    n[i].vb = false; S++;
                    flag = true;
                    RES++;
                }
                if (n[i].va == true && n[i].a <= S && (maxb == -1 || n[i].b > n[maxb].b)) maxb = i;
            }
            if (!flag && maxb!=-1) {n[maxb].va = false; S++; flag = true; RES++;}
        } while (flag);
    
        flag = true;
        for (i=0; i<N && flag; i++) if (n[i].va == true || n[i].vb == true) flag = false;
        cout << "Case #" << t << ": ";
        if (!flag) cout << "Too Bad" << endl;
        else cout << RES << endl;
    }

    return 0;
}
