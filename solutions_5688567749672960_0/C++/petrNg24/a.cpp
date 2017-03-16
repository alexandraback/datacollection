
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#define maxv 100000

using namespace std;


long long xxx9[15] = {0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999,99999999999,999999999999,9999999999999,99999999999999};
long long stepDec[15]; //10^i

void input(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
}

void init(){
    stepDec[0]=1;
    stepDec[1]=10;
    for (int i=2; i<=14;i++){
        if (i%2==0) {
            stepDec[i]=stepDec[i-1]+xxx9[i/2]+xxx9[i/2]+1;
        } else {
            stepDec[i]=stepDec[i-1]+xxx9[i/2+1]+xxx9[i/2]+1;
        }
        //cout<<stepDec[i]<<endl;
    }
}

int rev(int u) {
    int v=0;
    while (u!=0) {
        v=v*10+u%10;
        u=u/10;
    }
    return v;
}

void solve(){
    int T;
    long long x,y;
    int n;
    int a[16];
    long long res;
    cin>>T;
    init();
    for (int t=0; t<T; t++) {
        res=0;
        cin>>x;
        for (int i=0; i<=14; i++) {
            if (x==xxx9[i]+1) {
                res = stepDec[i];
            }
        }
        if (x<=10) {
            res=x;
        }
        if (res==0) {
            if (x%10==0) {
                res=1;
                x=x-1;
            }
            n=0;
            y=x;
            while (y!=0) {
                n++;
                y=y/10;
            }
            //cout<<n<<endl;

            if (n%2==0) {
                //cout<<rev(x/(xxx9[n/2]+1))<<endl;
                res = res+ stepDec[n-1]+ rev(x/(xxx9[n/2]+1)) + x%(xxx9[n/2]+1);
                if (rev(x/(xxx9[n/2]+1))==1) {
                    res-=1;
                }
            } else {
                res = res +stepDec[n-1]+ max(rev(x/(xxx9[n/2]+1)) + x%(xxx9[n/2]+1), rev(x/(xxx9[n/2+1]+1)) + x%(xxx9[n/2+1]+1) );
                if (rev(x/(xxx9[n/2]+1)) + x%(xxx9[n/2]+1)> rev(x/(xxx9[n/2+1]+1)) + x%(xxx9[n/2+1]+1) && rev(x/(xxx9[n/2]+1))==1) {
                    res-=1;
                }
                if (rev(x/(xxx9[n/2]+1)) + x%(xxx9[n/2]+1)<= rev(x/(xxx9[n/2+1]+1)) + x%(xxx9[n/2+1]+1) && rev(x/(xxx9[n/2+1]+1))==1) {
                    res-=1;
                }
            }
        }
        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
}

void output(){

}

void process(){
    input();
    solve();
    output();
}

int main() {
    process();
    return 0;
}

