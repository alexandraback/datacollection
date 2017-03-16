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
map<int,int> m;
int n;
int rev(int x){
    int ans=0;
    while(x){
        ans*=10;
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int solve(int x){
    //cout<<"solving:"<<x<<endl;
    if(0){
        return 1;
    }
    else{
        if(m.find(x)!=m.end()){
            return m[x];
        }
        else{
            if(x%10!=0&&rev(x)<x)
                m[x]=1+min(solve(x-1),solve(rev(x)));
            else
                m[x]=1+solve(x-1);
            //cout<<x<<"ans"<<m[x]<<endl;
            return m[x];
        }
    }
}
int main(void){
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    m[1]=1;
//    for(int i=2;i<=1000000;i++){
//        m[i]=solve(i);
//    }
    int t,tt=1;
    f1>>t;
    while(t--){
        f1>>n;
        int finalans=solve(n);
        f2<<"Case #"<<tt<<": "<<finalans<<"\n";
        printf("Case #%d: %d\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
