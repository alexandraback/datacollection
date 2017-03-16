#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int x,r,c,i,cases,c1;
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        cin>>x>>r>>c;
        cout<<"Case #"<<c1<<": ";
        if(x>=7){
            cout<<"RICHARD"<<endl;
            continue;
            }
        if(x==1){
            cout<<"GABRIEL"<<endl;
            continue;
        }
        if(x==2){
            if((r%2==0)||(c%2==0))cout<<"GABRIEL"<<endl;
            else cout<<"RICHARD"<<endl;
            continue;
        }
        if(x==3){
            if((r==1)||(c==1)||((r*c)%3!=0))cout<<"RICHARD"<<endl;
            else cout<<"GABRIEL"<<endl;
            continue;
        }
        if(x==4){
            if((r<=2)||(c<=2)||((r*c)%4!=0))cout<<"RICHARD"<<endl;
            else cout<<"GABRIEL"<<endl;
            continue;
        }
        if(x==5){
            continue;
        }
        if(x==6){
            continue;
        }
    }
}
