#include"iostream"
#include"fstream"
#include"string"
#include"vector"

using namespace std;

int main(){

    freopen("d:D-large.in","r",stdin);
    freopen("d:outD.txt","w",stdout);

    int T;
    cin>>T;
    int casenum=0;
    while(casenum++<T){
        int X,R,C;
        cin>>X>>R>>C;
        bool ok=true;
        if(X==1){ok=true;}
        else if(X==2){
            ok=false;
            if(R*C%2==0){ok=true;}

        }else if(X==3){
            ok=false;
            if(R*C%3==0){
                if(min(R,C)>=2){
                    ok=true;
                }
            }
        }else if(X==4){
            ok=false;
            if(R*C%4==0){
                if(min(R,C)>=3){
                    ok=true;
                }
            }
        }else if(X==5){
            ok=false;
            if(R*C%5==0){
                if(min(R,C)>3){ok=true;}
                else if(min(R,C)==3){
                     if(max(R,C)>=10){ok=true;}
                }
            }
        }
        else if(X==6){
            ok=false;
            if(R*C%6==0){
                if(min(R,C)>3){ok=true;}
            }
        }else{
            ok=false;
        }
        printf("Case #%d: %s\n",casenum,ok?"GABRIEL":"RICHARD");
    }


return 0;}
