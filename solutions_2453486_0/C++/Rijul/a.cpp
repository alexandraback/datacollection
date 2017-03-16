#include<stdio.h>
#include<string.h>

#define maxm 10
#define n 4

char s[maxm][maxm];

int c_row();
int c_col();
int c_dia();
int empty();

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        for(i=1;i<=4;i++){
            scanf("%s",s[i]+1);
        }
        printf("Case #%d: ",t++);
        int val=c_row();
        if(val==1){
            printf("X won\n");
            continue;
        }
        else if(val==2){
            printf("O won\n");
            continue;
        }

        val=c_col();
        if(val==1){
            printf("X won\n");
            continue;
        }
        else if(val==2){
            printf("O won\n");
            continue;
        }
        val=c_dia();
        if(val==1){
            printf("X won\n");
            continue;
        }
        else if(val==2){
            printf("O won\n");
            continue;
        }

        if(empty()){
            printf("Game has not completed\n");
            continue;
        }
        else{
            printf("Draw\n");
            continue;
        }


    }

    return 0;
}

int c_row(){

    int i,j,c1,c2,c3;

    for(i=1;i<=n;i++){
        c1=c2=c3=0;
        for(j=1;j<=n;j++){
            if(s[i][j]=='X') c1++;
            else if(s[i][j]=='O') c2++;
            else if(s[i][j]=='T') c3++;
        }
        if(c1==4) return 1;
        if(c2==4) return 2;
        if(c1==3 && c3) return 1;
        if(c2==3 && c3) return 2;
    }

    return 0;

}

int c_col(){

    int i,j,c1,c2,c3;

    for(j=1;j<=n;j++){
        c1=c2=c3=0;
        for(i=1;i<=n;i++){
            if(s[i][j]=='X') c1++;
            else if(s[i][j]=='O') c2++;
            else if(s[i][j]=='T') c3++;
        }
        if(c1==4) return 1;
        if(c2==4) return 2;
        if(c1==3 && c3) return 1;
        if(c2==3 && c3) return 2;
    }

    return 0;

}

int c_dia(){

    int i,j,c1,c2,c3;

    c1=c2=c3=0;
    for(i=1,j=1;j<=n;j++,i++){
        if(s[i][j]=='X') c1++;
        else if(s[i][j]=='O') c2++;
        else if(s[i][j]=='T') c3++;
    }
    if(c1==4) return 1;
    if(c2==4) return 2;
    if(c1==3 && c3) return 1;
    if(c2==3 && c3) return 2;

    c1=c2=c3=0;
    for(i=1,j=n;i<=n;j--,i++){
        if(s[i][j]=='X') c1++;
        else if(s[i][j]=='O') c2++;
        else if(s[i][j]=='T') c3++;
    }
    if(c1==4) return 1;
    if(c2==4) return 2;
    if(c1==3 && c3) return 1;
    if(c2==3 && c3) return 2;


    return 0;

}

int empty(){

    int i,j;


    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(s[i][j]=='.') return 1;
        }
    }

    return 0;

}
