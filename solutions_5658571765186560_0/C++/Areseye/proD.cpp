#include"iostream"
#include"fstream"
#include"string"
#include"vector"

using namespace std;

int main(){

    freopen("d:D-small-attempt0.in","r",stdin);
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
            ;
        }
        else if(X==6){
            ;
        }else{
            ok=false;
        }
        printf("Case #%d: %s\n",casenum,ok?"GABRIEL":"RICHARD");
    }


return 0;}
