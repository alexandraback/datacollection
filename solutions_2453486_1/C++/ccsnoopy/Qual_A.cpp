#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string str[4];
bool isX(int i, int j){
    if(str[i].at(j)=='X' || str[i].at(j) == 'T') return true;
    return false;
}
bool isO(int i, int j){
    if(str[i].at(j)=='O' || str[i].at(j) == 'T') return true;
    return false;
}
int main(void){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc,casecounter = 1, coun;
    bool xwon, owon, full;

    string dummy;
    scanf("%d",&tc);
    getline(cin,dummy);
    while(tc--){
        xwon = owon = false;
        full = true;
        coun = 0;
        for(int i=0;i<4;i++){
            getline(cin,str[i]);
            for(int j=0;j<4;j++){
                if(str[i].at(j)=='.')full = false;
            }
        }
        getline(cin,dummy);

        for(int i=0;i<4;i++){
            if(isX(i,0) && isX(i,1) && isX(i,2) && isX(i,3)) xwon = true;
            if(isO(i,0) && isO(i,1) && isO(i,2) && isO(i,3)) owon = true;
            if(isX(0,i) && isX(1,i) && isX(2,i) && isX(3,i)) xwon = true;
            if(isO(0,i) && isO(1,i) && isO(2,i) && isO(3,i)) owon = true;
        }
        if(isX(0,0) && isX(1,1) && isX(2,2) && isX(3,3)) xwon = true;
        if(isO(0,0) && isO(1,1) && isO(2,2) && isO(3,3)) owon = true;
        if(isX(0,3) && isX(1,2) && isX(2,1) && isX(3,0)) xwon = true;
        if(isO(0,3) && isO(1,2) && isO(2,1) && isO(3,0)) owon = true;


        printf("Case #%d: ",casecounter++);
        if(owon) printf("O won\n");
        else if(xwon) printf("X won\n");
        else if(!full) printf("Game has not completed\n");
        else printf("Draw\n");
    }

    return 0;
}
