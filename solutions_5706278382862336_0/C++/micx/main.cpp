#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
#define  LL long long
LL gcd(LL a,LL b){
    if(b==0)return a;
    return gcd(b,a%b);
}
LL getcnt(LL M){
    LL b=1,i;
    for(i=1;i<13;++i){
        b=b<<1;
        if(b==M)return i;
    }
    return -1;
}

LL getcnt1(LL M){
    LL b=1,i;
    for(i=1;i<13;++i){
        b=b<<1;
        if(b>=M)return i;
    }
    return -1;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out1.txt","w",stdout);

    LL T,i,j,k,c,P,Q,M,M1;
    cin>>T;
    for(c=1;c<=T;++c){

        scanf("%lld/%lld",&P,&Q);
//        cout<<P<<"/"<<Q<<endl;
//        cout<<gcd(P,Q)<<endl;
        M=Q/gcd(P,Q);
        M1=P/gcd(P,Q);
//        cout<<"M = "<<M<<endl;
        LL ans=getcnt(M);
        LL ans1=getcnt1(M1);
//        cout<<"M1="<<M1<<"\t ans1="<<ans1<<endl;
        cout<<"Case #"<<c<<": ";
        if(ans>0)
            cout<<ans+1-ans1<<endl;
        else
            cout<<"impossible"<<endl;
    }

    return 0;
}
