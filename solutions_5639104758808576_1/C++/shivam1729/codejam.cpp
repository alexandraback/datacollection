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
        int n;
        f1>>n;
        string s;
        f1>>s;
        int finalans=0;
        int cur=s[0]-'0';
        for(int i=1;i<=n;i++){
            if(cur<i&&s[i]!='0'){
                finalans+=i-cur;
                cur=i+s[i]-'0';
            }
            else{
                cur+=s[i]-'0';
            }
        }
        f2<<"Case #"<<tt<<": "<<finalans<<"\n";
        printf("Case #%d: %d\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
