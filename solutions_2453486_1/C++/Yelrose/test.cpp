#include <iostream>
#include <cstdio>
using namespace std;
char chess[4][4];

int judge(){    //0 draw,-1 unfinish,1 O win,2X win
    bool finish = true;
    for(int i = 0;i < 4;i ++){

        for(int j = 0;j < 4;j ++){
            if(chess[i][j] == '.'){
                finish = false;
            }
        }
    }
    for(int i = 0;i < 4;i ++){
        bool win = true;
        char ch='.';
        for(int j = 0;j < 4;j ++){
           // cout << chess[i][j] << " damn" << endl;
            if(j == 0 || ch == 'T'){
                ch = chess[i][j];
                if(ch == '.'){

                    win = false;
                    break;
                }

            }
            else if(chess[i][j] != ch&& chess[i][j] != 'T'){
                win = false;
                break;
            }
        }
        if(win){
           // cout << "fuck" << endl;
            return (ch == 'X')?2:1;
        }
    }
    for(int i = 0;i < 4;i ++){
        bool win = true;
        char ch = '.';
        for(int j = 0;j < 4;j ++){
            if(j == 0 || ch == 'T'){
                ch = chess[j][i];
                if(ch == '.' ){
                    win = false;
                    break;
                }

            }
            else if(chess[j][i] != ch && chess[j][i]!='T'){
                win = false;
                break;
            }
        }
        if(win){
            return (ch == 'X')?2:1;
        }
    }
    char ch1 = '.';
    bool win1 = true;
    for(int i = 0;i < 4;i ++){
        if(i == 0 || ch1 == 'T'){
             ch1 = chess[i][i];
                if(ch1 == '.' ){
                    win1 = false;
                    break;
                }
        }
        else if(ch1 != chess[i][i]&& chess[i][i] != 'T'){
            win1= false;
            break;
        }
    }
    if(win1)return (ch1 == 'X')?2:1;
    win1= true;
    ch1 = '.';
     for(int i = 0;i < 4;i ++){
         if(i == 0 || ch1 == 'T'){
             ch1 = chess[3-i][i];
                if(ch1 == '.' ){
                    win1 = false;
                    break;
                }
        }
        else if(ch1 != chess[3-i][i]&& chess[3-i][i] != 'T'){
            win1= false;

            break;
        }
    }
    if(win1)return (ch1 == 'X')?2:1;
    return finish?0:-1;
}

int main(){
    int T;
    cin >>T;
    int ca = 1;
    while(T -- ){



        for(int i = 0;i < 4;i ++){
            for(int j = 0;j < 4;j ++){
                cin >> chess[i][j];
            }
        }
        int k = judge();
        printf("Case #%d: ",ca);
        ca ++;
        switch(k){
            case 0: printf("Draw\n");break;
            case -1: printf("Game has not completed\n");break;
            case 1: printf("O won\n");break;
            case 2:printf("X won\n");break;
        }

    }
}

