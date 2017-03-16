#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;++tt){
        char game[4][4+1];
        for(int i=0;i<4;++i){
            scanf("%s", game[i]);
        }
        bool flag=false;
        bool playerx,playero,draw;
        playerx=playero=draw=false;
        for(int i=0;i<4;++i){
                int x,o;
                x=o=0;
                int t=0;
                for(int j=0;j<4;++j){
                    if(game[i][j]=='T')
                            t++;
                    else if(game[i][j]=='O'){
                        o++;
                    }
                    else if(game[i][j]=='X'){
                        x++;
                    }
                    else
                        flag=true;
                }
                if(x==4 || (x==3 && t==1)){
                    playerx=true;
                    break;
                }
                else if(o==4 || (o==3 && t==1)){
                    playero=true;
                    break;
                }
        }
        if(playerx){
            printf("Case #%d: X won\n", tt);
            continue;
        }
        else if(playero){
            printf("Case #%d: O won\n", tt);
            continue;
        }
        for(int j=0;j<4;++j){
            int x,o,t;
            x=o=t=0;
            for(int i=0;i<4;++i){
                if(game[i][j]=='T')
                            t++;
                else if(game[i][j]=='O'){
                        o++;
                    }
                else if(game[i][j]=='X'){
                        x++;
                    }
                else
                    flag=true;
            }
            if(x==4 || (x==3 && t==1)){
                    playerx=true;
                    break;
                }
            else if(o==4 || (o==3 && t==1)){
                    playero=true;
                    break;
                }
        }
        if(playerx){
            printf("Case #%d: X won\n", tt);
            continue;
        }
        else if(playero){
            printf("Case #%d: O won\n", tt);
            continue;
        }
        int x,o,t;
        x=o=t=0;
        for(int i=0,j=3;i<4,j>=0;++i,--j){
            if(game[i][j]=='T')
                            t++;
            else if(game[i][j]=='O'){
                        o++;
                    }
            else if(game[i][j]=='X'){
                        x++;
                    }
            else
                flag=true;
        }
        if(x==4 || (x==3 && t==1)){
                    playerx=true;
                }
        else if(o==4 || (o==3 && t==1)){
                    playero=true;
                }
        if(playerx){
            printf("Case #%d: X won\n", tt);
            continue;
        }
        else if(playero){
            printf("Case #%d: O won\n", tt);
            continue;
        }
        x=o=t=0;
        for(int i=0,j=0;i<4,j<4;++i,++j){
            if(game[i][j]=='T')
                            t++;
            else if(game[i][j]=='O'){
                        o++;
                    }
            else if(game[i][j]=='X'){
                        x++;
                    }
            else
                flag=true;
        }
        if(x==4 || (x==3 && t==1)){
                    playerx=true;
                }
        else if(o==4 || (o==3 && t==1)){
                    playero=true;
                }
        if(playerx){
            printf("Case #%d: X won\n", tt);
            //continue;
        }
        else if(playero){
            printf("Case #%d: O won\n", tt);
            //continue;
        }
        else if(!flag){
            printf("Case #%d: Draw\n", tt);
            //continue;
        }
        else if(flag){
            printf("Case #%d: Game has not completed\n", tt);
        }
    }
return 0;
}
