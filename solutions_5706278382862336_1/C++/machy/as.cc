#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef long long LL;

int solve(LL P, LL Q){
    while(P % 2 == 0 && Q % 2 == 0){
        P /= 2; Q /= 2;
    }
    if(P == 1 && Q == 1) return 0;
    if(P == 0) return 1000*1000;
    if(Q % 2 != 0) return -1;
    Q /= 2;
    LL res = 1000*1000;
    for(LL d1 = 1; d1 <= 4 || d1*d1 <= Q; d1++){
        if(Q % d1 == 0){
            LL d2 = Q / d1;
            for(LL n1 = 0; n1 <= d1; n1++){
                if((P - n1 * d2) % d1 == 0){
                    LL n2 = (P - n1 * d2) / d1;
                    if(n2 > d2 || n2 < 0) continue;
                    LL a1 = solve(n1, d1);
                    if(a1 == -1) continue;
                    LL a2 = solve(n2, d2);
                    if(a2 == -1) continue;
                    res = min(res, min(a1 + 1, a2 + 1));
                }
            }
        }
    }
    if(res == 1000*1000) return -1;
    return res;
}

int main(){
    int T;
    int N, L;

    cin >> T;
    for(size_t t = 1; t <= T; t++){
        char c;
        LL P, Q;
        cin >> P >> c >> Q;
        int res = solve(P, Q);
        cout << "Case #" << t << ": ";
        if(res == -1){
            cout << "impossible" << endl;
        }else{
            cout << res << endl;
        }
    }
    return 0;
}

