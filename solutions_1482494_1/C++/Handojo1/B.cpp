#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool sudah[2002][2];
pair<int,int> data[2002];
int kasus,banyak;

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&banyak);
        for (int i=0;i<banyak;++i) scanf("%d %d",&data[i].first,&data[i].second);
        memset(sudah,0,sizeof(sudah));
        
        int indeks = 0,jawab = 0;
        int satu = 0, dua = 0;
        int total = 0, star = 0;
        bool temu;
        
        do {
            temu = false;
            int best = -1;
            for (int i=0;i<banyak && !temu;++i) {
                if (!sudah[i][1] && data[i].second <= star) {
                    ++jawab;
                    ++total;
                    star += 2 - (sudah[i][0]);
                    sudah[i][0] = sudah[i][1] = true;
                    temu = true;
                } else if (!sudah[i][0] && (data[i].first <= star)) {
                    if ((best == -1)||(data[i].second > data[best].second)) best = i;
                }
            }
            
            if (!temu && (best > -1)) {
                temu = sudah[best][0] = true;
                ++star;
                ++jawab;
            }
        } while ((temu)&&(total < banyak));
        
        printf("Case #%d: ",l);
        if (total < banyak) printf("Too Bad\n");
        else printf("%d\n",jawab);
    }
    return 0;
}
