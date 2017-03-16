#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#define INF 1000000007
using namespace std;
long long gao(int x) {
    int v[10];
    memset(v, 0, sizeof(v));
    int cnt = 1;
    while(true) {
        long long now = (long long)cnt * (long long)x;
        while(now) {
            v[now % 10] = 1;
            now /= 10;
        }
        int flag = 1;
        for(int i = 0; i < 10; i++) {
            if(v[i] == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) return (long long)cnt * (long long)x;
        cnt++;
    }
}
int main() {
    int T, cas = 0, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); 
        if(n == 0) {
            printf("Case #%d: INSOMNIA\n", ++cas);
            continue;
        }
        long long ans = gao(n);
        printf("Case #%d: %lld\n", ++cas, ans);
    }
	return 0;
}
