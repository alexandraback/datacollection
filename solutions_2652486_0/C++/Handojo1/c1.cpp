#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int kasus,n,m,k,lima[10],tiga[10],dua[10];

int main() {
    scanf("%d",&kasus);
    scanf("%d %d %d %d",&kasus,&n,&m,&k);
    
    printf("Case #1:\n");
    for (int l=1;l<=kasus;++l) {
        memset(lima,0,sizeof(lima));
        memset(tiga,0,sizeof(tiga));
        memset(dua,0,sizeof(dua));
        for (int i=1,sem;i<=k;++i) {
            scanf("%d",&sem);
            while (sem % 5 == 0) {
                sem /= 5;
                ++lima[i];
            }
            
            while (sem % 3 == 0) {
                sem /= 3;
                ++tiga[i];
            }

            while (sem % 2 == 0) {
                sem /= 2;
                ++dua[i];
            }            
        }
        
        int m5 = 0,m3 = 0;
        for (int i=1;i<=k;++i) {
            m3 = max(m3,tiga[i]);
            m5 = max(m5,lima[i]);
        }
        
        int sisa = n-m3-m5;
        if (sisa) {
            for (int j=0;j<=sisa;++j) {
                //yang angka dua
                bool flag = true;
                for (int i=1;i<=k&&flag;++i) {
                    if (dua[i] > 2*(sisa-j)+j) flag = false;
                    if (dua[i] == 1 && !j) flag = false;
                }
                
                if (flag) {
                    for (int i=1;i<=j;++i) printf("2");
                    for (int i=1;i<=sisa-j;++i) printf("4");
                    break;
                }
            }
        }
        for (int i=1;i<=m3;++i) printf("3");
        for (int i=1;i<=m5;++i) printf("5");
        printf("\n");
    }
    return 0;
}
