#include<stdio.h>
char s[10][10];
bool check(char st[10],char c){
    for(int i=0;i<4;i++)
        if(st[i]!=c&&st[i]!='T')
            return 0;
    return 1;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cs,csi,i,j,k;
    char u[10];
    scanf("%d",&cs);
    for(csi=1;csi<=cs;csi++){
        printf("Case #%d: ",csi);
        for(i=0;i<4;i++)
            scanf("%s",s[i]);
        for(i=0;i<4;i++)
            if(check(s[i],'X'))
                break;
        if(i<4){puts("X won");continue;}
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                u[j]=s[j][i];
            if(check(u,'X'))
                break;
        }
        if(i<4){puts("X won");continue;}
        for(i=0;i<4;i++)
            u[i]=s[i][i];
        if(check(u,'X')){puts("X won");continue;}
        for(i=0;i<4;i++)
            u[i]=s[i][3-i];
        if(check(u,'X')){puts("X won");continue;}


        for(i=0;i<4;i++)
            if(check(s[i],'O'))
                break;
        if(i<4){puts("O won");continue;}
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                u[j]=s[j][i];
            if(check(u,'O'))
                break;
        }
        if(i<4){puts("O won");continue;}
        for(i=0;i<4;i++)
            u[i]=s[i][i];
        if(check(u,'O')){puts("O won");continue;}
        for(i=0;i<4;i++)
            u[i]=s[i][3-i];
        if(check(u,'O')){puts("O won");continue;}
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                if(s[i][j]=='.')
                    {i=j=9;}
        if(i==10)puts("Game has not completed");
        else puts("Draw");
    }
    return 0;

}
