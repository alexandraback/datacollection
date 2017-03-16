#include <iostream>
#include <cstdio>

using namespace std;

int t, test, a, b, res, g[7];

int main(){
//    freopen("C-large.in", "rt", stdin);
//    freopen("C-large.out", "wt", stdout);
    cin >> t;
    for (test = 1; test <= t; test++){
        cin >> a >> b;
        res = 0;
        int cnt = 0, x, y, t1 = a, t2 = 1, t1_, t2_, p;
        while (t1){
            cnt++;
            t1 /= 10;
            t2 *= 10;
        }
        t1 = 10;
        t2 /= 10;
        for (int i = a; i <= b; i++){
            t1_ = t1;
            t2_ = t2;
            p = 0;
            for (int j = 1; j < cnt; j++){
                x = i % t1_;
                y = i / t1_ + x * t2_;
                if (i < y && y <= b){
                    bool ok = true;
                    for (int k = 1; k <= p; k++)
                        if (g[k] == y){
                            ok = false;
                            break;
                        }
                    if (ok){
                        res ++;
                        g[++p] = y;
                    }
                }
                t1_ *= 10;
                t2_ /= 10;
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
