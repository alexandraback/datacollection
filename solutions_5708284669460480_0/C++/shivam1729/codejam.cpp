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
ll maxi,total;
string keys,a;
void rec(int cur,int n,string tt){
    if(cur==n){
        int cnt=0;
        for(int i=0;i+a.length()-1<n;i++){
            bool here=true;
            for(int j=0;j<a.length();j++){
                if(tt[i+j]!=a[j]){
                    here=false;
                    break;
                }
            }
            if(here){
                cnt++;
            }
        }
        total+=cnt;
        maxi=max(maxi,1ll*cnt);
    }
    else{
        string newtt=tt;
        for(int i=0;i<keys.length();i++){
            newtt+=keys[i];
            rec(cur+1,n,newtt);
            newtt=tt;
        }
    }
}
int main(void){
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        //memset(cntbanana,0,sizeof(cntbanana));
        total=0;
        maxi=-1;
        int k,l,s;
        f1>>k>>l>>s;
        f1>>keys>>a;
        string temp;
        rec(0,s,temp);
        double val=1.0;
        for(int i=1;i<=s;i++){
            val*=k;
        }
        double finalans=maxi-total/val;

        f2<<setprecision(8)<<"Case #"<<tt<<": "<<finalans<<"\n";
        //cout<<setprecision(6)<<"Case #"<<tt<<": "<<finalans<<"\n";
        //fprintf(f2,"Case #%d: %.6lf\n",tt,finalans);

        printf("Case #%d: %.6lf\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
