#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, a, b;

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    cin >> T;
    for (int i = 1; i<=T; i++){
        printf("Case #%d: ", i);
        cin >> a;
        int tot = 0;
        int pre = 0;
        for (int i = 0; i<=a; i++){
            char k;
            cin >> k;
            int b = (int)(k - '0');
            if (pre >= i) pre+=b;
            else {
                tot += i - pre;
                pre = i+b;
            }
        }
        cout << tot << endl;
    }

}
