#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas = 1; cas <= t; ++cas){
        int r, c, w;
        cin>>r>>c>>w;
        cout<<"Case #"<<cas<<": ";
        if(c%w == 0)cout<<(c/w)*r + w - 1<<endl;
        else cout<<(c/w)*r + w<<endl;
    }



    return 0;
}
