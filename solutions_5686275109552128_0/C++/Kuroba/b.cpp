#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T;
int D, P, a;
int cnt[1005];



int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    cin >> T;

    for (int i = 1; i<=T; i++){
        memset(cnt, 0, sizeof cnt);
        printf("Case #%d: ", i);
        cin >> D;
        P = 0;
        for (int i = 0; i<D; i++){
            cin >> a;
            cnt[a]++;
            P = max(P, a);
        }
        int best = P;

        for (int x = 1; x<P; x++){ // try each value of i as best
            int cuts = 0;

            for (int i = x+1; i<=P; i++){
                cuts += cnt[i]*((i-1)/x);
            }
            //cout << "debug " << x << " " << cuts << endl;
            best = min(best, cuts + x);
        }


        cout << best << endl;

    }

}
