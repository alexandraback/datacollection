#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX(a,b) a = max(a,b)

using namespace std;

int dp[105][105],sudah[105][105];
int biasa[50],kaget[50],isi[105];
int kasus,banyak,sure,batas;

int proses(int urut, int sisa) {
    if (urut == banyak) return 0;
    
    if (!sudah[urut][sisa]) {
        sudah[urut][sisa] = true;
        if (sisa) {
            dp[urut][sisa] = proses(urut+1,sisa-1) + (kaget[isi[urut]] >= batas);
        }
        
        MAX(dp[urut][sisa],proses(urut+1,sisa) + (biasa[isi[urut]] >= batas));
    }
    
    return dp[urut][sisa];
}

int main() {
    for (int i=0;i<=10;++i) {
        for (int j=i;j<=i+2;++j) {
            for (int k=j;k<=i+2;++k) {
                if (k==i+2) MAX(kaget[i+j+k],k);
                else MAX(biasa[i+j+k],k);
            }
        }
    }
    
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d %d",&banyak,&sure,&batas);
        for (int i=0;i<banyak;++i) scanf("%d",&isi[i]);
        memset(sudah,0,sizeof(sudah));
        memset(dp,0,sizeof(dp));
        int jawab = proses(0,sure);
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
