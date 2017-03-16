#include <bits/stdc++.h>
using namespace std;
const int maxn = 411500;
bool run(int X,int R,int C){\
    if(R<C){
        swap(R,C);
    }
    if(X==4&&R==4&&C==2){
        return true;
    }
    if(X>R){
        return true;
    }
    int k=(X+1)>>1;
    if(k>C){
        return true;
    }
    if(X>=7){
        return true;
    }
    if(X>=2*C+1&&C>1){
        return true;
    }
    if((R*C)%X){
        return true;
    }

//    cout<<"dfa"<<endl;
    return false;
}
int main(){
    freopen("E:\\in.txt","r",stdin);
    freopen("E:\\out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cout<<"Case #"<<cas<<": ";
        int X,R,C;
        cin>>X>>R>>C;
        if(run(X,R,C)){
            cout<<"RICHARD"<<endl;
        }else{
            cout<<"GABRIEL"<<endl;
        }
    }
    return 0;
}

