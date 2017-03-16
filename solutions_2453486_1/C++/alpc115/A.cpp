#include<iostream>
#include<cstdio>
using namespace std;
const string X="X won";
const string O="O won";
char st[4][4];
int cheak(){
    int tot,tt;
    for (int i=0; i<4; i++){
        tot=0; tt=0;
        for (int j=0; j<4; j++){
            if (st[i][j]=='T')
                tt++;
            if (st[i][j]=='X') tot++;
            if (st[i][j]=='O') tot--;
        }
        //cout<<tot<<' '<<tt<<endl;
        if (tot>0){
            if (tot+tt==4) return 1;
        } else {
            if (-tot+tt==4) return -1;
        }
    }

    for (int j=0; j<4; j++){
        tot=0; tt=0;
        for (int i=0; i<4; i++){
            if (st[i][j]=='T') tt++;
            if (st[i][j]=='X') tot++;
            if (st[i][j]=='O') tot--;
        }
        if (tot>0){
            if (tot+tt==4) return 1;
        } else {
            if (-tot+tt==4) return -1;
        }
    }

    tot=0;tt=0;
    for (int i=0; i<4; i++){
        if (st[i][i]=='T') tt++;
        if (st[i][i]=='X') tot++;
        if (st[i][i]=='O') tot--;
    }
    if (tot>0){
        if (tot+tt==4) return 1;
    } else {
        if (-tot+tt==4) return -1;
    }

    tot=tt=0;
    for (int i=0; i<4; i++){
        if (st[i][3-i]=='T') tt++;
        if (st[i][3-i]=='X') tot++;
        if (st[i][3-i]=='O') tot--;
    }
    if (tot>0){
        if (tot+tt==4) return 1;
    } else {
        if (-tot+tt==4) return -1;
    }
    return 0;
}
int draw(){
    for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
    if (st[i][j]=='.') return 0;
    return 1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1;tt<=T;tt++){
        printf("Case #%d: ",tt);
        for (int i=0; i<4; i++) scanf("%s",st[i]);
        int tt=cheak();
        if(tt==1) printf("%s\n",X.c_str()); else
        if (tt==-1) printf("%s\n",O.c_str());
        if (tt!=0) continue;
        if (draw()) puts("Draw"); else puts("Game has not completed");
    }
}
