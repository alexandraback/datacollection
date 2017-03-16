#include<bits/stdc++.h>
using namespace std;
long long v[1010100];
long long s1[1010100],N,M;

int ok = 0;
set<int> S;
void make(int x) {
    while(x) {
        int d = x % 10;
        x=x/10;
        S.insert(d);
    }
}
int main() {
    freopen("test3.in","r",stdin);
    freopen("test3.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        int K,C,S;
        cin >> K >> C >> S;
        printf("Case #%d: ",tt);
        for(int i=1;i<=K;++i) {
            printf("%d ", i);
        }
        printf("\n");
    }
}
