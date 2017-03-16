#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>

#define REP(i,n) for(int i=0;i<n;i++)
#define LL long long int

using namespace std;

LL maxp;

LL gcd(LL a, LL b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

LL lcm(LL a, LL b)
{
    LL temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int solve(){
    LL p,q;
    cin>>p;
    cin.get();    
    cin>>q;

    LL tgcd=gcd(p,q);

    if(tgcd){
        p=p/tgcd;
        q=q/tgcd;
    }

    if(maxp%q){
        return -1;
    }

    LL curq=q;
    //cout<<curq<<" "<<p<<endl;
    int counter=1;
    while(true){
        if(curq<=0){
            cout<<"Error indivisibility"<<endl;
            return -1;
        }
        if(curq%2){
            return -1;
        }
        LL div2=curq/2;
        //cout<<div2<<" "<<p<<endl;
        if(div2<=p){
            LL cur=q;
            REP(i,counter)cur/=2;
            if(cur>p){
                cout<<"Fail"<<endl;
            }
            return counter;
        }
        counter++;
        curq=div2;
    }

}

int main(int argv,char** argc){

    maxp=1;
    REP(i,40){maxp*=2;}

    int n;
    cin>>n;

    REP(i,n){
        cout<<"Case #"<<i+1<<":"<<" ";
        int res=solve();
        if(res==-1){
            cout<<"impossible"<<endl;
        }else{
            cout<<res<<endl;
        }
    }

    return 0;
}
