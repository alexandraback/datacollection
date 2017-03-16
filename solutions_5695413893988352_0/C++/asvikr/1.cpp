#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
inline int read()
{
    int ret = 0,temp=1;
    int c = getchar_unlocked();
    while(c<'0' || c>'9'){
        c = getchar_unlocked();
    }
    while(c>='0' && c<='9')
    {
        ret = (ret<<3) + (ret<<1) + c - '0';
        c = getchar_unlocked();
    }
        return ret;
}

 int n;
 string ans1,ans2;
 LL a1,a2;
 LL diff=LONG_LONG_MAX;
 void solve(int i,LL x,LL y,string s1,string s2){
    if(i==n) {
        if(diff>abs(x-y)){
            ans1=s1;
            ans2=s2;
            a1=x,a2=y;
            diff=abs(x-y);
        }
        else if(diff==abs(x-y)){
            if(a1>x){
                a1=x;
                a2=y;
                ans1=s1;ans2=s2;
            }
            else if(a1==x && a2>y){
                a1=x;
                a2=y;
                ans1=s1;ans2=s2;
            }
        }
        return;
    }
    if(s1[i]=='?' && s2[i]=='?'){
        if(x==y){
            s1[i]='0';s2[i]='0';
           solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';s2[i]='?';
            s1[i]='0';s2[i]='1';
           solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';s2[i]='?';
            s1[i]='1';s2[i]='0';
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';s2[i]='?';
        }
        else if(x>y){
            s1[i]='0';
            s2[i]='9';
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';s2[i]='?';
        }
        else if(y>x){
            s1[i]='9';
            s2[i]='0';
           solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';s2[i]='?';   
        }
    }
    else if(s1[i]=='?' && s2[i]!='?'){
        if(x==y){
            s1[i]=s2[i];
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';
            s1[i]=s2[i]-1;
            if(s2[i]=='0') s1[i]='9';
           solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';
            s1[i]=s2[i]+1;
            if(s2[i]=='9') s1[i]='0';
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';
        }
        else if(x>y){
            s1[i]='0';
             solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?';
        }
        else if(y>x){
            s1[i]='9';
             solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s1[i]='?'; 
        }
    }
    else if(s1[i]!='?' && s2[i]=='?'){
        if(x==y){
            s2[i]=s1[i];
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s2[i]='?';
            s2[i]=s1[i]-1;
            if(s1[i]=='0') s2[i]='9';
           solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s2[i]='?';
            s2[i]=s1[i]+1;
            if(s1[i]=='9') s2[i]='0';
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s2[i]='?';
        }
        else if(x>y){
            s2[i]='9';
            solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s2[i]='?';
        }
        else if(y>x){
            s2[i]='0';
             solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
            s2[i]='?'; 
        }
    }
    else solve(i+1,x*10LL+(s1[i]-'0'),y*10LL+(s2[i]-'0'),s1,s2);
 }
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        printf("Case #%d: ",tt);
        string s1,s2;
        cin>>s1>>s2;
         n=s1.size();
        LL x=0,y=0;
        diff=LONG_LONG_MAX;
        solve(0,x,y,s1,s2);
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
