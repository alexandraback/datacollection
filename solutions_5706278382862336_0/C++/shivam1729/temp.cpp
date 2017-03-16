#include<bits/stdc++.h>
#define ll long long
#define pn() printf("\n")
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%.8Lf",x)
#define MOD 1000000007LL
using namespace std;
int main(void){
    int a,b,t,tc=1;
    ifstream f1("input.txt");
    ofstream f2("output.txt");
    f1>>t;
    while(t--){
        long long a,b;
        char ch;
        f1>>a;
        f1>>ch;
        f1>>b;
        long long gcd=__gcd(a,b);
        a/=gcd;
        b/=gcd;
        if(b>(1LL<<40)){
            f2<<"Case #"<<tc<<": "<<"impossible"<<"\n";
            tc++;
            //cout<<"hello\n";
            continue;
        }
        if(a>b){
            f2<<"Case #"<<tc<<": "<<"impossible"<<"\n";
            tc++;
            cout<<"hello\n";
            continue;
        }
        if(a==b){
            f2<<"Case #"<<tc<<": "<<"0"<<"\n";
            tc++;
            cout<<"hello\n";
            continue;
        }
        int pos=0;
        if((b&(b-1))==0){
            pos=1;
        }
        int ans=0;
        while(a<b/2){
            ans++;
            b>>=1;
        }
        if(!pos){
            f2<<"Case #"<<tc<<": "<<"impossible"<<"\n";
        }
        else{
            f2<<"Case #"<<tc<<": "<<ans+1<<"\n";
        }
        tc++;
    }
    return 0;
}
