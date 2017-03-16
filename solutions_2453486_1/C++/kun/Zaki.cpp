#include<cstdio>
int T,a,b;
char s[5][5];
bool chk(char c){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(s[i][j] != c){
                goto gd;
            }
       return true;
       gd:;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(s[j][i] != c){
                goto gd2;
            }
       return true;
       gd2:;
    }
    for(int i=0;i<4;i++){
        if(s[i][i]!=c)
            goto gd3;
    }
    return true;
    gd3:;
    for(int i=0;i<4;i++){
        if(s[i][3-i]!=c)
            return false;
    }
    return true;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int u = 0;
    for(int r=1;r<=T;r++){
        a = -1; b = -1;
        u = 0;
        for(int i=0;i<4;i++)
            scanf("%s",s[i]);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(s[i][j]=='T')
                    a = i,b = j;
        if(a != -1)
        s[a][b] = 'X';
        if(chk('X')){
            u = -1;
            printf("Case #%d: X won\n",r);
        }
        if(a != -1)
        s[a][b] = 'O';
        if(chk('O')){
            u = -1;
            printf("Case #%d: O won\n",r);
        }
        
        for(int i=0;u>=0 && i<4;i++)
            for(int j=0;j<4;j++)
                if(s[i][j]=='.')
                    u++;
        if(u>0)
            printf("Case #%d: Game has not completed\n",r);
        else if(u==0)
            printf("Case #%d: Draw\n",r);
    }
    return 0;
}
