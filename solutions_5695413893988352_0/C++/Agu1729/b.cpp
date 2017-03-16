#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T, cs, l, p[4];
    p[0]=1;
    p[1]=10;
    p[2]=100;
    p[3]=1000;
    string c, j;
    int C, J, bC, bJ, bD, chC, chJ;
    cin>>T;
    for(cs=1;cs<=T;cs++){
        cout<<"Case #"<<cs<<": ";
        cin>>c>>j;
        l=c.length();
        bD=1<<25;
        for(int C=0;C<=p[l]-1;C++){
            chC=0;
            for(int i=0;i<=l-1;i++){
                if(c[i]!='?'&&(c[i]!=(C/p[l-1-i])%10+'0')){
                    chC=1;
                }
            }
            if(chC==1){
                continue;
            }
            for(int J=0;J<=p[l]-1;J++){
                chJ=0;
                for(int i=0;i<=l-1;i++){
                    if(j[i]!='?'&&(j[i]!=(J/p[l-1-i])%10+'0')){
                        chJ=1;
                    }
                }
                if(chJ==1){
                    continue;
                }
                if(max(C,J)-min(C,J)<bD){
                    bD=max(C,J)-min(C,J);
                    bC=C;
                    bJ=J;
                }
                else if((max(C,J)-min(C,J)==bD)&&C<bC){
                    bC=C;
                    bJ=J;
                }
                else if((max(C,J)-min(C,J)==bD)&&(C==bC)&&(J<bJ)){
                    bJ=J;
                }
            }
        }
        if(l==1){
            printf("%d %d", bC, bJ);
        }
        if(l==2){
            printf("%02d %02d", bC, bJ);
        }
        if(l==3){
            printf("%03d %03d", bC, bJ);
        }
        cout<<endl;
    }
    return 0;
}
