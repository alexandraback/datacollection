#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        int A,B,K;
        cin >> A >> B >> K;
        long long ans = 0;
        for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            if ((i & j) < K) ans++;
        printf("Case #%d: ",o);
        cout << ans << endl;
    }
}
