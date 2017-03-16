#include <cstdio>
char s[5][5];
int ck(char s[][5],char w)
{
    for(int i=0;i<4;i++){
        int ct1=0,ct2=0,ct3=0,ct4=0;
        for(int j=0;j<4;j++){
            if(s[i][j]==w) ct1++;
            else if(s[i][j]=='T') ct2++;
            if(s[j][i]==w) ct3++;
            else if(s[j][i]=='T') ct4++;
        }
        if(ct1+ct2==4&&ct1>=3) return 1;
        if(ct3+ct4==4&&ct3>=3) return 1;
    }
    int ct1=0,ct2=0,ct3=0,ct4=0;
    for(int i=0;i<4;i++){
        if(s[i][i]==w) ct1++;
        else if(s[i][i]=='T') ct2++;
        if(s[3-i][i]==w) ct3++;
        else if(s[3-i][i]=='T') ct4++;
    }
    if(ct1+ct2==4&&ct1>=3) return 1;
    if(ct3+ct4==4&&ct3>=3) return 1;
    return 0;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<4;i++) scanf("%s",s[i]);
        printf("Case #%d: ",++ca);
        if(ck(s,'X')) puts("X won");
        else if(ck(s,'O')) puts("O won");
        else {
            int flag=0;
            for(int i=0;i<4;i++) 
                for(int j=0;j<4;j++) {
                    if(s[i][j]=='.') {
                        flag=1;
                        break;
                    }
                }
            if(flag) puts("Game has not completed");
            else puts("Draw");
        }
    }
}
