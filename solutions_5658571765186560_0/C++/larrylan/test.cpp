#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, X, R, C;
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>X>>R>>C;
        if(R>C) swap(R,C);
        bool y=false|(R*C%X!=0)|(X>=7)|(X==5&&R==3&&C==5)|
        (X==3&&R==1)|(X==4&&R<=2)|(X==5&&R<=2)|(X==6&&R<=3);
        cout<<"Case #"<<tt<<": "<<(y?"RICHARD":"GABRIEL")<<endl;
    }
    return 0;
}
