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
int dp[21][21];
int solve(int c,int w){
    if(c==w){
        return c;
    }
    else if(w>c){
        return 0;
    }
    else if(dp[c][w]){
        return dp[c][w];
    }
    else{
        dp[c][w]=max(w+1,1+solve(c-w,w));
        return dp[c][w];
    }
}
int main(void){
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        ll finalans=0;
        int r,c,w;
        f1>>r>>c>>w;
        finalans=r*solve(c,w);
        f2<<"Case #"<<tt<<": "<<finalans<<"\n";
        printf("Case #%d: %lld\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
