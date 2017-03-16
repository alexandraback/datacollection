#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define LL long long

int T;
LL B, M;
int ans[55][55];

int main() {
    freopen("B-large.in.txt", "r", stdin);
    freopen("B.out", "w", stdout);
    cin>>T;
    for (int ca = 1; ca <= T; ++ ca) {
        cin>>B>>M;
        cout<<"Case #"<<ca<<": ";
        if (M > (1LL << (B-2))) {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        memset(ans, 0, sizeof(ans));
        ans[0][B-1]=1;
        M -- ;
        for (int i = 0; i < B - 1; ++ i) {
            for (int j = 0; j < B - 1; ++ j)
                if (i < j)
                    ans[i][j] = 1;
            if (i > 0)
                ans[i][B-1] = ((M & (1LL << (i - 1))) > 0);
        }
        for (int i = 0; i < B; ++ i) {
            for (int j = 0; j < B; ++ j)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
    return 0;
}
