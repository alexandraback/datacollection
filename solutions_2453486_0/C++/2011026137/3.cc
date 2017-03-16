#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c[10][10];
bool f(int x,bool t,char f){
    int i;
    if(t){
        for(i=1;i<=4;i++)
            if(c[i][x]==f||c[i][x]=='T')
                continue;
            else
                break;
    }
    else{
        for(i=1;i<=4;i++)
            if(c[x][i]==f||c[x][i]=='T')
                continue;
            else
                break;
    }
    if(i==5)
        return 1;
    return 0;
}
bool f1(bool t,char f){
    int i;
    if(t){
        for(i=1;i<=4;i++)
            if(c[i][i]==f||c[i][i]=='T')
                continue;
            else
                break;
    }
    else{
        for(i=1;i<=4;i++)
            if(c[i][5-i]==f||c[i][5-i]=='T')
                continue;
            else
                break;
    }
    if(i==5)
        return 1;
    return 0;
}
int main(){
    freopen("out.out","w",stdout);
    int i,T,j,k,n,m;
    scanf("%d",&T);
    for(int ii=1;ii<=T;ii++){
        m=0;
        for(i=1;i<=4;i++){
            scanf("%s",c[i]+1);
            for(j=1;j<=4;j++)
                if(c[i][j]=='.')
                    m=1;
        }
        int x=0,y=0;
        if(f1(1,'X')||f1(0,'X'))
            x=1;
        if(f1(1,'O')||f1(0,'O'))
            y=1;
        for(i=1;i<=4;i++){
            if(f(i,1,'X'))
                x=1;
            if(f(i,1,'O'))
                y=1;
            if(f(i,0,'X'))
                x=1;
            if(f(i,0,'O'))
                y=1;
        }
        printf("Case #%d: ",ii,x,y);
        if(x==1)
            printf("X won\n");
        else if(y==1)
            printf("O won\n");
        else if(m==1)
            printf("Game has not completed\n");
        else
            printf("Draw\n");
    }
    return 0;
}
