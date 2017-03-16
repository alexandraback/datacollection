#include <cstdio>

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    char m[4][5];
    int z[4][4];
    gets(m[0]);
    for(int C=1;C<=ncase;C++){
        for(int i=0;i<4;i++)gets(m[i]);
        int ans=0,dot=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(m[i][j]=='.')z[i][j]=0,dot=1;
                if(m[i][j]=='T')z[i][j]=3;
                if(m[i][j]=='O')z[i][j]=1;
                if(m[i][j]=='X')z[i][j]=2;
            }
        }
        for(int i=0;i<4;i++){
            int h=z[i][0]&z[i][1]&z[i][2]&z[i][3];
            int v=z[0][i]&z[1][i]&z[2][i]&z[3][i];
            int d1=z[0][0]&z[1][1]&z[2][2]&z[3][3];
            int d2=z[0][3]&z[1][2]&z[2][1]&z[3][0];
            if(h == 1 || v == 1 || d1 == 1 || d2 == 1){
                ans=1;
            }
            if(h == 2 || v == 2 || d1 == 2 || d2 == 2){
                ans=2;
            }
        }
        printf("Case #%d: ",C);
        if(ans==0 && dot==0)puts("Draw");
        if(ans==0 && dot==1)puts("Game has not completed");
        if(ans==1)puts("O won");
        if(ans==2)puts("X won");
        if(ncase>C)gets(m[0]);
    }
    return 0;
}