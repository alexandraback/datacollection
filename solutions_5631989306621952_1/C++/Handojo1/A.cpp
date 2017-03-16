#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
bool pakai[2005];
int N,panjang,idx,isi[2005];
char kata[2005];

int main() {
    scanf("%d",&N);
    for (int l=1;l<=N;++l) {
        scanf("%s",kata);
        panjang = strlen(kata);
        idx = 0;
        memset(pakai,0,sizeof(pakai));
        
        for (int i=panjang-1;i>-1;--i) {
            while (idx > 0 && kata[isi[idx]] < kata[i]) {
                pakai[isi[idx]] = false;
                --idx;
            }
            
            ++idx;
            pakai[i] = true;
            isi[idx] = i;
        }
        
        for (int i=0;i<panjang;++i) if (!pakai[i]) {
            ++idx;
            isi[idx] = i;
        }
        
        printf("Case #%d: ",l);
        for (int i=1;i<=panjang;++i) printf("%c",kata[isi[i]]);
        printf("\n");
    }
    return 0;
}