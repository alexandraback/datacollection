#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;

int T, kk;
int K, A, B, ans;

int main(){
    cin >> T;
    kk = 0;
    while (T--){
        kk ++;
        cin >> A >> B >> K;
        ans = 0;
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < B; ++j)
                if ((i & j) < K) ans ++;
        printf("Case #%d: %d\n", kk, ans);
    }

    return 0;


}
