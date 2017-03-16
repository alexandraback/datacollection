#include<stdio.h>
#include <algorithm>
#include <string.h>

char ans[4][4];

bool checkrow(int i, char c){
    for(int j=0; j<4; j++){
        //printf("value of ans[%d][%d] is %c \n",i,j,ans[i][j]);
        if( (ans[i][j] != c)&&(ans[i][j] != 'T') ) return false;
    }
    return true;
}

bool checkcol(int j, char c){
    for(int i=0; i<4; i++){
        //printf("value of ans[%d][%d] is %c \n",i,j,ans[i][j]);
        if( (ans[i][j] != c)&&(ans[i][j] != 'T') ) return false;
    }
    //printf("returning true\n");
    return true;
}

bool checkd1(char c){
    for(int i=0; i<4; i++){
        int j = i;
        if( (ans[i][j] != c)&&(ans[i][j] != 'T') ) return false;
    }
    return true;
}

bool checkd2(char c){
    for(int i=0; i<4; i++){
        int j = 3-i;
        //printf("value of ans[%d][%d] is %c \n",i,j,ans[i][j]);
        if( (ans[i][j] != c)&&(ans[i][j] != 'T') ) return false;
    }
    return true;
}

bool xwon(){
    //printf("called x won\n");
    for(int i=0; i<4; i++){
        if(checkrow(i, 'X')) return true;
    }
    for(int j=0; j<4; j++){
        if(checkcol(j, 'X')) return true;
    }
    if(checkd1('X')) return true;
    if(checkd2('X')) return true;
    return false;
}
bool owon(){
    for(int i=0; i<4; i++){
        if(checkrow(i, 'O')) return true;
    }
    for(int j=0; j<4; j++){
        if(checkcol(j, 'O')) return true;
    }
    if(checkd1('O')) return true;
    if(checkd2('O')) return true;
    return false;
}
bool draw(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(ans[i][j] == '.') return false;
        }
    }
    return true;
}


int main(){
    int T;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);

    for(int t=0; t<T; t++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                scanf(" %c",&ans[i][j]);
                //ans[i][j] = tmp;
            }
        }
       /*
        printf("the input is\n\n");
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                printf("%c\t",ans[i][j]);
                //ans[i][j] = tmp;
            }
            printf("\n\n");
        }
        /*/
        if(xwon()) printf("Case #%d: X won\n",t+1);
        else if(owon()) printf("Case #%d: O won\n",t+1);
        else if(draw()) printf("Case #%d: Draw\n",t+1);
        else printf("Case #%d: Game has not completed\n",t+1);
            //*/
    }
return 0;
}
