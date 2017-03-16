#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
int T;
long long A,B,K;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        cin>>A>>B>>K;
        long long ans = 0;
        for(int i = 0; i < A; i++) {
            for(int j = 0; j < B; j++) {
                if((i & j) < K) {
                    ans++;
                }
            }
        }
        printf("Case #%d: %I64d\n", ++cas, ans);
    }
    return 0;
}
