#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int T,X,R,C;

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d %d %d",&X,&R,&C);
        if (R <= C) swap(R,C);
        bool temu = false;
        if ((R*C)%X != 0) temu = true;
        if (X >= 8) temu = true; //Bikin aja tengahnya kosong 1 kotak, dikurung.
        
        for (int i=1;i<=X && !temu;++i) {
            int d = X+1-i;
            if (d <= R && i <= C) continue;
            if (d <= C && i <= R) continue;
            temu = true;
        }
        
        if (X >= 2*C) {
            for (int i=0;i<=X-C && !temu;++i) {
                //Bagi jadi 2 bagian, dimana salah satunya ga bisa diisi.
                bool bisa = false;
                for (int j=0;j<=R-1 && !bisa;++j) {
                    int atas = j*C;
                    int bawah = (R-j-1)*C;
                    atas -= i;
                    bawah -= (X-C)-i;
                    
                    if (atas >= 0 && bawah >= 0 && (atas%X == 0) && (bawah%X==0)) bisa = true;
                }
                if (!bisa) temu = true;
            }
        }
        
        if (temu) printf("Case #%d: RICHARD\n",l);
        else printf("Case #%d: GABRIEL\n",l);
    }
    return 0;
}
