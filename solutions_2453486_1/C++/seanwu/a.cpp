#include <stdio.h>

char c[5][5];

int main(){
    int tt,TT,i,j,d,f;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        for( i=0; i<4; i++ ){
            scanf("%s",c[i]);
        }
        f=0;
        for( i=0; i<4; i++ ){
            d=0;
            for( j=0; j<4; j++ ){
                if(c[i][j]=='O' || c[i][j]=='T') d++;
            }
            if(d==4){
                f=1;
                goto out;
            }
            d=0;
            for( j=0; j<4; j++ ){
                if(c[j][i]=='O' || c[j][i]=='T') d++;
            }
            if(d==4){
                f=1;
                goto out;
            }
        }
        d=0;
        for( j=0; j<4; j++ ){
            if(c[j][j]=='O' || c[j][j]=='T') d++;
        }
        if(d==4){
            f=1;
            goto out;
        }
        d=0;
        for( j=0; j<4; j++ ){
            if(c[j][3-j]=='O' || c[j][3-j]=='T') d++;
        }
        if(d==4){
            f=1;
            goto out;
        }


        for( i=0; i<4; i++ ){
            d=0;
            for( j=0; j<4; j++ ){
                if(c[i][j]=='X' || c[i][j]=='T') d++;
            }
            if(d==4){
                f=2;
                goto out;
            }
            d=0;
            for( j=0; j<4; j++ ){
                if(c[j][i]=='X' || c[j][i]=='T') d++;
            }
            if(d==4){
                f=2;
                goto out;
            }
        }
        d=0;
        for( j=0; j<4; j++ ){
            if(c[j][j]=='X' || c[j][j]=='T') d++;
        }
        if(d==4){
            f=2;
            goto out;
        }
        d=0;
        for( j=0; j<4; j++ ){
            if(c[j][3-j]=='X' || c[j][3-j]=='T') d++;
        }
        if(d==4){
            f=2;
            goto out;
        }

        d=0;
        for( i=0; i<4; i++ ){
            for( j=0; j<4; j++ ){
                if(c[i][j]!='.') d++;
            }
        }
        if(d==16){
            f=3;
            goto out;
        }


        f=4;
out:
        if(f==1){
            printf("Case #%d: O won\n",tt+1);
        }else if(f==2){
            printf("Case #%d: X won\n",tt+1);
        }else if(f==3){
            printf("Case #%d: Draw\n",tt+1);
        }else{
            printf("Case #%d: Game has not completed\n",tt+1);
        }
    }
    return 0;
}
