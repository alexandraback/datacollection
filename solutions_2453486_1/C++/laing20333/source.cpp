#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#include<cmath>
#include<memory.h>
#include<sstream>
#include<queue>
#include<time.h>

using namespace std;


typedef long long ll;

char table[4][4];

bool ishorizontal(char symbol){
    int r,c;
    for(r=0;r<4;r++){
        int nsymbol = 0;
        int nt = 0;
        for(c=0;c<4;c++){
            if(table[r][c] == symbol){
                nsymbol++;
            }else if(table[r][c] == 'T'){
                nt++;
            }
        }
        if(nsymbol == 4 || (nsymbol == 3 && nt==1) ){
            return true;
        }
    }
    return false;
}

bool isvertical(char symbol){
    int r,c;
    for(c=0;c<4;c++){
        int nsymbol = 0;
        int nt = 0;
        for(r=0;r<4;r++){
            if(table[r][c] == symbol){
                nsymbol++;
            }else if(table[r][c] == 'T'){
                nt++;
            }
        }
        if(nsymbol == 4 || (nsymbol == 3 && nt==1) ){
            return true;
        }
    }
}

bool isdiagonal(char symbol){
    int nsymbol =0 ;
    int nt = 0;
    for(int d=0;d<4;d++){
        if(table[d][d] == symbol){
            nsymbol++;
        }else if(table[d][d] == 'T'){
            nt++;
        }
    }
    if(nsymbol == 4 || (nsymbol == 3 && nt==1) ){
        return true;
    }
    nsymbol = nt = 0;
    for(int d=0;d<4;d++){
        if(table[d][3-d] == symbol){
            nsymbol++;
        }else if(table[d][3-d] == 'T'){
            nt++;
        }
    }
    if(nsymbol == 4 || (nsymbol == 3 && nt==1) ){
        return true;
    }
    return false;
}


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.csv", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ntest;
    while(cin>>ntest){

    for(int tt=1; tt<=ntest; tt++){
        if(tt > 1){
            getchar();
        }
        int isover = 1;
        for(int r=0;r<4;r++){
            for(int c=0; c< 4; c++){
                cin>>table[r][c];
                if(table[r][c] == '.'){
                    isover = 0;
                }
            }
        }

        printf("Case #%d: ", tt);
        if(ishorizontal('X') || isvertical('X') || isdiagonal('X')){
            cout<<"X won"<<endl;
        }else if(ishorizontal('O') || isvertical('O') || isdiagonal('O')){
            cout<<"O won"<<endl;
        }else if(isover){
            cout<<"Draw"<<endl;
        }else cout<<"Game has not completed"<<endl;

    }

    }
    return 0;
}
