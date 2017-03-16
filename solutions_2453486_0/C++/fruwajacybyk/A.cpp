#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

char s[10][10];

bool check(char c){
    FOR(i,0,4){
        bool flaga = true;
        FOR(j,0,4)
            if(s[i][j]!=c && s[i][j]!='T') flaga = false;
        if(flaga) return true;
    }
    FOR(i,0,4){
        bool flaga = true;
        FOR(j,0,4)
            if(s[j][i]!=c && s[j][i]!='T') flaga = false;
        if(flaga) return true;
    }
    bool flaga = true;
    FOR(i,0,4) if(s[i][i]!=c && s[i][i]!='T') flaga = false;
    if(flaga) return true;
    flaga = true;
    FOR(i,0,4) if(s[i][3-i]!=c && s[i][3-i]!='T') flaga = false;
    return flaga;
}

bool checkdraw(){
    FOR(i,0,4) FOR(j,0,4) if(s[i][j]=='.') return false;
    return true;
}


int main(){
    int z; scanf("%d",&z);
    FOR(tn,1,z+1){
        FOR(i,0,4) scanf("%s",s[i]);
        string result;
        if(check('X')) result = "X won";
        else if(check('O')) result = "O won";
        else if(checkdraw()) result = "Draw";
        else result = "Game has not completed";
        cout<<"Case #"<<tn<<": "<<result<<endl;
    }
}


