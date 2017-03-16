#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

typedef long long LL;

int main() {
    int T;
    cin>>T;
    for (int loop = 1; loop<=T; ++loop) {
        printf("Case #%d: ",loop);
        int K,C,S;
        cin>>K>>C>>S;
        
        int ptr = 0,cnt = 0;
        set<LL> dic;
        while (ptr<K) {
            LL x = 0,i;
            for (i = 0; ptr<K && i<C; ++i,++ptr) {
                x = x*K+ptr;
            }
            if (ptr==K && i<C) {
                for (; i<C; ++i) x = x*K;
            }
            dic.insert(x+1);
            ++cnt;
            if (cnt==S) break;
        }
        if (ptr<K) printf("IMPOSSIBLE\n");
        else {
            set<LL>::iterator sii;
            for (sii = dic.begin(); sii!=dic.end(); ++sii) {
                printf(" %lld",*sii);
            }
            printf("\n");
        }
    }
    return 0;
}