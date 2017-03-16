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
int a[1001];
int mm=-1;
int main(void){
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        mm=-1;
        int d;
        f1>>d;
        for(int i=1;i<=d;i++){
            f1>>a[i];
            mm=max(mm,a[i]);
        }
        int finalans=100000;
        int curans;
        for(int i=1;i<=mm;i++){
            curans=i;
            int red=0;
            for(int j=1;j<=d;j++){
                if(i<a[j]){
                    if(a[j]%i==0){
                        red+=a[j]/i-1;
                    }
                    else{
                        red+=a[j]/i;
                    }
                }
            }
            //printf("for %d reductions cnt of splits=%d\n",i,red);
            curans=curans+red;
            finalans=min(finalans,curans);
        }
        f2<<"Case #"<<tt<<": "<<finalans<<"\n";
        printf("Case #%d: %d\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
