#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

bool sudah[10000001];
int kasus,bawah,atas;

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d",&bawah,&atas);
        long long jawab = 0;
        int kali = 1;
        while (bawah / kali > 9) kali *= 10;
        
        memset(sudah,0,sizeof(sudah));
        for (int i=bawah;i<=atas;++i) {
            int sem = i;
            long long temu = 0;
            while (!sudah[sem]) {
                sudah[sem] = true;
                if ((sem >= bawah)&&(sem <= atas)) ++temu;
                sem = (sem / 10) + ((sem % 10)*kali);
            }
            jawab += (temu)*(temu-1) / 2;
        }
        printf("Case #%d: %I64d\n",l,jawab);
    }
    return 0;
}
