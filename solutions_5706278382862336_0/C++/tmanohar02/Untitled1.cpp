#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


LL gc(LL p , LL q){
    if(p==0)return q;
    else return gc(q%p , p);
}

LL ans(LL p,LL q){
    if(p>q) return -1;
    while(q < (1LL<<40) ){
        p *= 2;
        q *= 2;
    }
    if( q != (1LL<<40) ) return -1;
    int a = 0;
    while(p){
        a++;
        p /= 2;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int T;
    LL p,q;
    char ch;
    cin>>T;
    for (int t = 0; t < T; ++t){
        cin>>p>>ch>>q;
        LL g = gc(p,q);
        p /= g;
        q /= g;
        //cout<<p<<" "<<q<<" here"<<endl;
        cout<<"Case #"<<t+1<<": ";
        LL a = ans(p,q);
        if(a==-1) cout<<"impossible"<<endl;
        else{
            cout<<41-a<<endl;
        }
    }
    return 0;
}