#include<bits/stdc++.h>
#define ll long long
#define pn() printf("\n")
#define si(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define MOD 1000000007LL
using namespace std;
int main(void){
    ifstream f1("input.txt");
    ofstream f2("output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        int a,b,k;
        f1>>a>>b>>k;
        bool flag[1001];
        memset(flag,false,sizeof(flag));
        for(int i=0;i<k;i++){
            for(int j=i;j<k;j++){
                int temp=i&j;
                flag[temp]=true;
            }
        }
        int winner=0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                int temp=i&j;
                if(flag[temp]){
                    winner++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        f2<<"Case #"<<tt<<": "<<winner<<"\n";
        printf("Case #%d: %d\n",tt,winner);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
