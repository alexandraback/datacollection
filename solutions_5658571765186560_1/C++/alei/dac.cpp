#include<bits/stdc++.h>

using namespace std;

int main(){ 
    freopen("dl.in","r",stdin);
    freopen("dl.out","w",stdout);
    int t,x,n,m;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d %d %d",&x,&n,&m);
        if(n>m)swap(n,m);

        bool ok=false;
        if(x<=7 && (n*m)%x==0){
            if(x==1) ok=true;
            else if(x==2){
                if(n>=1 && m>=2) ok=true;
            }
            else if(x==3){
                if(n>=2 && m>=3)ok=true;
            }
            else if(x==4){
                if(n>=3 && m>=4)ok=true;
            }
            else if(x==5){
                if(n>=4 && m>=5)ok=true;
                if(n>=3 && m>=10)ok=true;
            }
            else if(x==6){
                if(n>=4 && m>=6)ok=true;
            }
            else if(x==7){
                if(n>=5 && m>=7)ok=true;
                if(n>=4 && m>=14)ok=true;
            }

        }
        if(ok)printf("Case #%d: GABRIEL\n",tt);
        else  printf("Case #%d: RICHARD\n",tt);

    }
    return 0;
}

