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
#define int long long
#define MOD 1000000007LL
using namespace std;
void func1(char c,char a[2]){
    if(a[0]=='+'){
        if(a[1]=='1'){
            a[0]='+';
            a[1]=c;
        }
        else if(a[1]=='i'){
            if(c=='i'){
                a[0]='-';
                a[1]='1';
            }
            else if(c=='j'){
                a[0]='-';
                a[1]='k';
            }
            else{
                a[0]='+';
                a[1]='j';
            }
        }
        else if(a[1]=='j'){
            if(c=='i'){
                a[0]='+';
                a[1]='k';
            }
            else if(c=='j'){
                a[0]='-';
                a[1]='1';
            }
            else{
                a[0]='-';
                a[1]='i';
            }
        }
        else{
            if(c=='i'){
                a[0]='-';
                a[1]='j';
            }
            else if(c=='j'){
                a[0]='+';
                a[1]='i';
            }
            else{
                a[0]='-';
                a[1]='1';
            }
        }
    }
    else{
        if(a[1]=='1'){
            a[0]='-';
            a[1]=c;
        }
        else if(a[1]=='i'){
            if(c=='i'){
                a[0]='+';
                a[1]='1';
            }
            else if(c=='j'){
                a[0]='+';
                a[1]='k';
            }
            else{
                a[0]='-';
                a[1]='j';
            }
        }
        else if(a[1]=='j'){
            if(c=='i'){
                a[0]='-';
                a[1]='k';
            }
            else if(c=='j'){
                a[0]='+';
                a[1]='1';
            }
            else{
                a[0]='+';
                a[1]='i';
            }
        }
        else{
            if(c=='i'){
                a[0]='+';
                a[1]='j';
            }
            else if(c=='j'){
                a[0]='-';
                a[1]='i';
            }
            else{
                a[0]='+';
                a[1]='1';
            }
        }
    }
}
void func(char a[2],char c){
    if(a[0]=='+'){
        if(a[1]=='1'){
            a[0]='+';
            a[1]=c;
        }
        else if(a[1]=='i'){
            if(c=='i'){
                a[0]='-';
                a[1]='1';
            }
            else if(c=='j'){
                a[0]='+';
                a[1]='k';
            }
            else{
                a[0]='-';
                a[1]='j';
            }
        }
        else if(a[1]=='j'){
            if(c=='i'){
                a[0]='-';
                a[1]='k';
            }
            else if(c=='j'){
                a[0]='-';
                a[1]='1';
            }
            else{
                a[0]='+';
                a[1]='i';
            }
        }
        else{
            if(c=='i'){
                a[0]='+';
                a[1]='j';
            }
            else if(c=='j'){
                a[0]='-';
                a[1]='i';
            }
            else{
                a[0]='-';
                a[1]='1';
            }
        }
    }
    else{
        if(a[1]=='1'){
            a[0]='-';
            a[1]=c;
        }
        else if(a[1]=='i'){
            if(c=='i'){
                a[0]='+';
                a[1]='1';
            }
            else if(c=='j'){
                a[0]='-';
                a[1]='k';
            }
            else{
                a[0]='+';
                a[1]='j';
            }
        }
        else if(a[1]=='j'){
            if(c=='i'){
                a[0]='+';
                a[1]='k';
            }
            else if(c=='j'){
                a[0]='+';
                a[1]='1';
            }
            else{
                a[0]='-';
                a[1]='i';
            }
        }
        else{
            if(c=='i'){
                a[0]='-';
                a[1]='j';
            }
            else if(c=='j'){
                a[0]='+';
                a[1]='i';
            }
            else{
                a[0]='+';
                a[1]='1';
            }
        }
    }
}
 main(void){
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        ll l,x;
        f1>>l>>x;
        string s;
        f1>>s;
        string save=s;
        //x=min(x,12);
        //cout<<s<<" "<<x;
        if(x>15){
            int extra=x-12;
            extra/=4;
            extra*=4;
            x-=extra;
        }
        for(int i=1;i<x;i++){
            s=s+save;
        }

        //cout<<endl<<s;
        char cur[3];
        cur[0]='+';
        cur[1]='1';
        bool foundi=false;
        bool foundk=false;
        bool foundj=false;
        int idxi,idxk;
        for(int i=0;i<s.length()-2;i++){
           // cout<<cur[0]<<cur[1]<<"*"<<"+"<<s[i]<<"=";
            func(cur,s[i]);
         //   cout<<cur[0]<<cur[1]<<endl;
            if(cur[0]=='+'&&cur[1]=='i'){
                foundi=true;
                idxi=i;
                break;
            }
        }
        if(foundi){
           // cout<<"found i at:"<<idxi<<endl;
            cur[0]='+';
            cur[1]='1';
            if(s[s.length()-1]=='k'){
                foundk=true;
                idxk=s.length()-1;
                goto label;
            }
            for(int i=s.length()-1;i>idxi+1;i--){
                func1(s[i],cur);
                if(cur[0]=='+'&&cur[1]=='k'){
                    foundk=true;
                    idxk=i;
                    break;
                }
            }
            if(foundk){
                label:
                //cout<<"found k at:"<<idxk<<endl;
                cur[0]='+';
                cur[1]='1';
                for(int i=idxi+1;i<idxk;i++){
                    func(cur,s[i]);
                }
                if(cur[0]=='+'&&cur[1]=='j'){
                    f2<<"Case #"<<tt<<": YES"<<"\n";
                    printf("Case #%d: YES\n",tt);
                }
                else{
                    f2<<"Case #"<<tt<<": NO"<<"\n";
                    printf("Case #%d: NO\n",tt);
                }
            }
            else{
                f2<<"Case #"<<tt<<": NO"<<"\n";
                printf("Case #%d: NO\n",tt);
            }
        }
        else{
            f2<<"Case #"<<tt<<": NO"<<"\n";
            printf("Case #%d: NO\n",tt);
        }
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
