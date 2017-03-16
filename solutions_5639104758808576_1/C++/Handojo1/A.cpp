#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int T,N;
char kata[1005];

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d",&N);
        scanf("%s",kata);
        int jawab = 0;
        int aktif = 0;
        for (int i=0;i<=N;++i) {
            if (kata[i] != '0' && aktif < i) {
                jawab += (i-aktif);
                aktif = i;
            }
            aktif += (kata[i]-'0');
        }
        
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
