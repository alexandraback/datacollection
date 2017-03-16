#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char kata[10005];
int multab[5][5],T,L,isi[10005],depan[10005],belakang[10005];
long long X;

int qmul(int x,int y) {
    int sign = 1;
    if (x < 0) {
        sign *= -1;
        x = -x;
    }
    
    if (y < 0) {
        sign *= -1;
        y = -y;
    }
    
    return sign*multab[x][y];
}

int main() {
    multab[1][1] = 1;
    multab[1][2] = 2;
    multab[1][3] = 3;
    multab[1][4] = 4;
    
    multab[2][1] = 2;
    multab[2][2] = -1;
    multab[2][3] = 4;
    multab[2][4] = -3;
    
    multab[3][1] = 3;
    multab[3][2] = -4;
    multab[3][3] = -1;
    multab[3][4] = 2;
    
    multab[4][1] = 4;
    multab[4][2] = 3;
    multab[4][3] = -2;
    multab[4][4] = -1;    
    
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d %I64d",&L,&X);
        scanf("%s",kata);
        for (int i=0;i<L;++i) {
            if (kata[i] == 'i') isi[i] = 2;
            else if (kata[i] == 'j') isi[i] = 3;
            else isi[i] = 4;
        }
        
        depan[0] = 1;
        for (int i=1;i<=L;++i) depan[i] = qmul(depan[i-1],isi[i-1]);
        belakang[0] = 1;
        for (int i=1;i<=L;++i) belakang[i] = qmul(isi[L-i],belakang[i-1]);
        
        bool bisa = false;
        for (int i=0;i<=L && !bisa;++i) {
            for (int k=0;k<=L && !bisa;++k) {
                int segmen = 0;
                int cobai = depan[i];
                bool flag = false;
                for (int o = 0;o<4&&!flag;++o) {
                    if (cobai == 2) {
                        flag = true;
                        segmen += o;
                    }
                    cobai = qmul(depan[L],cobai);
                }
                
                if (!flag) continue;
                
                int cobak = belakang[k];
                flag = false;
                for (int o = 0;o<4&&!flag;++o) {
                    if (cobak == 4) {
                        flag = true;
                        segmen += o;
                    }
                    cobak = qmul(cobak,belakang[L]);
                }
                
                if (!flag) continue;

                if (L-i-k >= 0) {
                    //Bagian tengah tidak fleksibel.
                    
                    if (depan[L] == qmul(qmul(depan[i],3),belakang[k]) && 
                        segmen+1 <= X && (X-segmen-1)%4 == 0) bisa = true;
                }
                
                segmen += 2; //Yang dibelah, biar bagian tengah juga fleksibel nambahnya.
                
                flag = false;
                for (int o=0;o<4&&!flag;++o) {
                    int cobaj = belakang[L-i];
                    for (int j=1;j<=o;++j) cobaj = qmul(cobaj,depan[L]);
                    cobaj = qmul(cobaj,depan[L-k]);
                    if (cobaj == 3) {
                        flag = true;
                        segmen += o;
                    }
                }
                
                if (!flag) continue;
                if (segmen <= X && ((X-segmen) % 4 == 0)) bisa = true;
            }
        }
        
        if (bisa) printf("Case #%d: YES\n",l);
        else printf("Case #%d: NO\n",l);
    }
    return 0;
}
