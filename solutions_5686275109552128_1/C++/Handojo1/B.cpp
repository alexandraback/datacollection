#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int T,N,isi[1005],maks;

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d",&N);
        scanf("%d",&isi[0]);
        maks = isi[0];
        for (int i=1;i<N;++i) {
            scanf("%d",&isi[i]);
            maks = max(maks,isi[i]);
        }
        
        int jawab = maks;
        for (int i=1;i<maks;++i) {
            int total = i;
            for (int j=0;j<N;++j) {
                total += (isi[j]-1)/i;
            }
            jawab = min(jawab,total);
            //printf("%d: %d\n",i,total);
        }
        
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
