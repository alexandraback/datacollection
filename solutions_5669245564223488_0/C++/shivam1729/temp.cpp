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
        string finalans="";
        int n;
        //cout<<t;
        f1>>n;
        string a[n];
        for(int i=0;i<n;i++){
            f1>>a[i];
        }
        int per[n];
        for(int i=0;i<n;i++){
            per[i]=i;
        }
        int ans=0;
        do{
            finalans="";
            for(int i=0;i<n;i++){
                finalans+=a[per[i]];
                //cout<<per[i]<<" ";
            }
            //cout<<endl<<finalans<<endl;
            bool come[26];
            int wrong=0;
            memset(come,false,sizeof(come));
            int l=finalans.length();
            for(int i=0;i<l;i++){
                if(!come[finalans[i]-'a']){
                    come[finalans[i]-'a']=true;
                }
                else{
                    if(finalans[i]!=finalans[i-1]){
                        wrong=1;
                        break;
                    }
                }
            }
            if(!wrong){
                ans++;
                //cout<<"adding:"<<finalans<<endl;
            }
        }while(next_permutation(per,per+n));
        f2<<"Case #"<<tc<<": "<<ans<<"\n";
        tc++;
    }
    return 0;
}
