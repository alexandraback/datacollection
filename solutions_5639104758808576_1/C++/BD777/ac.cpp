#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

#define bug puts("here");
#define lson o<<1
#define rson o<<1|1

using namespace std;

const int maxn = 1086;

char a[maxn];

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;
    for(int kase=1;kase <=T;kase++) {
        int imax;
        cin >> imax >> a;
        int ans = 0;
        int now = 0;
        for(int i=0;i<=imax;i++) {
            if(now < i) {
                ans += i - now;
                now = i;
            }
            now += a[i] - '0';
        }
        printf("Case #%d: %d\n",kase,ans);
    }
}
