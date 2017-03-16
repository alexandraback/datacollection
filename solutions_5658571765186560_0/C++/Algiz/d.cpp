#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

string solve(){
    int x,r,c;
    cin>>x>>r>>c;
    if(c > r) swap(c,r);
    if((r*c)%x!=0 || x>max(r,c))return "RICHARD";

    if(x==4){
        if(c==4 && r==4)return "GABRIEL";
        if(c==3 && r==4)return "GABRIEL";
        else return "RICHARD";
    }
    if(x==3){
        if(c==3 && r==4)return "GABRIEL";
        if(c==2 && r==3)return "GABRIEL";
        if(c==3 && r==3)return "GABRIEL";
        return "RICHARD";
    }
    if(x==2){
        return "GABRIEL";
    }
    if(x==1){
        return "GABRIEL";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);

    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        string t = solve();
        cout<<"Case #"<<i<<": "<<t<<"\n";
    }

    return 0;
}
