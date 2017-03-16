#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int kasus,ketik,panjang;
double p[100001];

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d",&ketik,&panjang);
        p[0] = 1.0;
        for (int i=1;i<=ketik;++i) {
            double sem;
            scanf("%lf",&sem);
            p[i] = p[i-1] * sem;
        }
        
        double best = (double)(panjang + 2);
        for (int i=0;i<ketik;++i) {
            double perlu = (double)(i) + (double)(1+panjang-ketik+i);
            perlu += (1.0-p[ketik-i]) * (double)(panjang+1);
            best = min(best, perlu);
        }
        
        printf("Case #%d: %.6lf\n",l,best);
    }
    return 0;
}
