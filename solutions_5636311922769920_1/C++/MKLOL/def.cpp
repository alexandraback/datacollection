#include<bits/stdc++.h>
using namespace std;
long long K,C,S;
long long build(int x, int y) {
long long rez = 0;
    long long pw = 1;
    for(int i = x-1;i<= y-1;++i){
        rez += pw * i;
        pw *= K;
    }
    return rez + 1;
}
int main() {
    freopen("test3.in","r",stdin);
    freopen("test3.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        cin >> K >> C >> S;
        printf("Case #%d: ",tt);
        if((K+C-1)/C > S) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        C = min(C,K);
        for(int i=1;i<=K;i+=C) {
           cout << build(i,min(K,i+C-1)) << " ";
        }
        printf("\n");
    }
}
