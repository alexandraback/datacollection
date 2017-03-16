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
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        //memset(make,false,sizeof(make));
        ll finalans=0;
        ll c,d,v;
        f1>>c>>d>>v;
        ll a[d+1];
        for(int i=1;i<=d;i++){
            f1>>a[i];
        }
        sort(a+1,a+d+1);
        ll donetill=0;
        for(int i=1;i<=d&&donetill<=v;i++){
            //cout<<"dontill:"<<donetill<<endl;
            if(donetill<a[i]-1){
                finalans++;
                //cout<<"inserting:"<<donetill+1<<endl;
                donetill+=c*(donetill+1);
                i--;
            }
            else{
                donetill+=a[i]*c;
            }
        }
        while(donetill<v){
            finalans++;
            donetill+=(donetill+1)*c;
        }
       // cout<<endl;
        //finalans=r*solve(c,w);
        f2<<"Case #"<<tt<<": "<<finalans<<"\n";
        printf("Case #%d: %d\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
