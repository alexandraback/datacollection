#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

bool pakai[1005];
int kasus,banyak,ken[1005],naomi[1005];
double baca;

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&banyak);
        for (int i=0;i<banyak;++i) {
            scanf("%lf",&baca);
            naomi[i]= (int)(baca*100000.0+0.01);
        }
        sort(naomi,naomi+banyak);
        
        for (int i=0;i<banyak;++i) {
            scanf("%lf",&baca);
            ken[i]= (int)(baca*100000.0+0.01);
        }
        sort(ken,ken+banyak);
        
        memset(pakai,0,sizeof(pakai));
        int j2 = 0;
        for (int i=0;i<banyak;++i) {
            bool flag = false;
            for (int j=0;j<banyak && !flag;++j) {
                if (!pakai[j] && ken[j] > naomi[i]) {
                    flag = true;
                    pakai[j] = true;
                }
            }
            
            if (!flag) {
                ++j2;
                for (int j=0;j<banyak && !flag;++j) {
                    if (!pakai[j]) {
                        flag = true;
                        pakai[j] = true;
                    }
                }
            }
        }
        
        int j1 = 0;
        int kiri = 0;
        if (ken[banyak-1] == 100000) {
            for (int i=1;i<banyak;++i) naomi[i-1] = naomi[i];
            --banyak;
        }
        int kanan = banyak;
        
        for (int i=0;i<banyak;++i) {
            if (naomi[i] > ken[kiri]) {
                ++j1;
                ++kiri;
            } else {
                --kanan;
            }
        }
        
        printf("Case #%d: %d %d\n",l,j1,j2);
    }
    return 0;
}
