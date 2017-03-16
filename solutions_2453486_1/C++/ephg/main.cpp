#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string s[6];
int t;

int main (){
    int i,j,l;
    cin>>t;
    for(l=1;l<=t;++l){
        int wx=0,wo=0,cx=0,co=0,cg=0;
        for(i=0;i<4;++i)cin>>s[i];
        for(i=0;i<4;++i){
            cx=0,co=0;
            for(j=0;j<4;++j){
                if(s[i][j]=='X'||s[i][j]=='T')++cx;
                if(s[i][j]=='O'||s[i][j]=='T')++co;
                if(s[i][j]=='.')++cg;
            }
            if(cx==4)wx=1;
            if(co==4)wo=1;
            //if(l==2)fprintf(stderr,"%d %d %d\n",cx,co,wo);
        }
        for(j=0;j<4;++j){
            cx=0,co=0;
            for(i=0;i<4;++i){
                if(s[i][j]=='X'||s[i][j]=='T')++cx;
                if(s[i][j]=='O'||s[i][j]=='T')++co;
            }
            if(cx==4)wx=1;
            if(co==4)wo=1;
            //if(l==2)fprintf(stderr,"%d %d %d\n",cx,co,wo);
        }
        co=cx=0;
        for(i=0;i<4;++i){
            if(s[i][i]=='X'||s[i][i]=='T')++cx;
            if(s[i][i]=='O'||s[i][i]=='T')++co;
        }
        if(cx==4)wx=1;
        if(co==4)wo=1;
        co=cx=0;
        for(i=0;i<4;++i){
            j=4-i-1;
            if(s[i][j]=='X'||s[i][j]=='T')++cx;
            if(s[i][j]=='O'||s[i][j]=='T')++co;
        }
        if(cx==4)wx=1;
        if(co==4)wo=1;
        cout<<"Case #"<<l<<": ";
        if(wx==1)cout<<"X won\n";
        else if(wo==1)cout<<"O won\n";
        else if(cg)cout<<"Game has not completed\n";
        else cout<<"Draw\n";
    }
    return 0;
}
