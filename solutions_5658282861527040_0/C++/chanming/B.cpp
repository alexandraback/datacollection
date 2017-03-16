#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int _;
    cin >> _;
    for (int __ = 1; __ <= _; ++__){
        printf("Case #%d: ", __);
        int ans = 0;
        int A, B, K;
        cin >> A >> B >> K;
        for (int i = 0; i < A; ++i){
            for (int j = 0; j < B; ++j){
                if ((i & j) < K)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}
