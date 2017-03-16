//Google codeJam 2013 Round 1C Problem B
//Abdurrahman Akkas
//recursive fonksiyon yazmayacagima yemin ederim
#include<iostream>
using namespace std;
    char ch[500];
    int chn;
    int X,Y,x,y;
int rec(){
    if(X==x&&Y==y){
        return 1;
    }
    if(x>150||x<-150||y>150||y<-150)
        return 0;
    if(chn==50)
        return 0;
    ch[chn]='N';
    chn++;
    y+=chn;
    if(rec())
        return 1;
    y-=chn;
    chn--;
    
    ch[chn]='S';
    chn++;
    y-=chn;
    if(rec())
        return 1;
    y+=chn;
    chn--;
    
    ch[chn]='E';
    chn++;
    x+=chn;
    if(rec())
        return 1;
    x-=chn;
    chn--;
    
    ch[chn]='W';
    chn++;
    x-=chn;
    if(rec())
        return 1;
    x+=chn;
    chn--;
    return 0;
}
int main(){
    int T,i;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        x=0;y=0;chn=0;
        cin>>X>>Y;
        rec();
        cout<<"Case #"<<i<<": ";
        int ii;
        for(ii=0;ii<chn;ii++)
            cout<<ch[ii];
        cout<<"\n";
    }
    cin>>T;
    return 0;
}
