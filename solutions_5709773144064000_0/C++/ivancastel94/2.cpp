#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t,cases;
    long double tmin,taqui,cps,c,f,x;
    cin>>t;
    for(cases=1;cases<=t;cases++){
        cin>>c>>f>>x;
        cout<<"Case #"<<cases<<": ";
        cps=2;
        tmin=x/cps;
        taqui=0;
        if(c<x){
            taqui+=c/cps;
            cps+=f;
            while(tmin>taqui+x/cps){
                tmin=taqui+x/cps;
                taqui+=c/cps;
                cps+=f;
            }
        }
        double round = tmin;
        printf("%.7lf\n",round);
    }
}
