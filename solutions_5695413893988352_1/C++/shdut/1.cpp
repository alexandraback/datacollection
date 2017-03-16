#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <map>
#include <string.h>
#include <assert.h>
#include <set>
#include <cmath>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
//#define dprintf(...) 
#define hash _hash
//#define dprintf(...) fprintf(outFile,__VA_ARGS__)
 
#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ull unsigned long long
#define ll long long
#define N 135010
 
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}
 
//FILE* outFile;
 
inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}
 
int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*(ll)a%mod;
        a=(ll)a*a%mod;b>>=1;
    }
    return ans;
}

char s[20],t[20],a[20],b[20];
int n;
void cal(char s[],char t[],int x,ll &a,ll &b){
    rep(i,x,n){
        a*=10;
        if(s[i]!='?')a+=(s[i]-'0');
        b*=10;
        if(t[i]!='?')b+=(t[i]-'0');else b+=9;
    }
}
ll ans=-1,A,B;
void upd(ll a,ll b,int k){
    if(k)swap(a,b);
    if(ans==-1||abs(a-b)<ans|| (abs(a-b)==ans&& a<A) || (abs(a-b)==ans&&a==A&&b<B)){
        ans=abs(a-b);
        A=a;
        B=b;
    }
}
void solve(char s[],char t[],int rev){
    //puts(s);
    ll a=0,b=0;
    rep(i,0,n){
        if(s[i]=='?'&&t[i]=='?'){
            s[i]='1',t[i]='0';
            ll aa=a,bb=b;
            cal(s,t,i,aa,bb);
            upd(aa,bb,rev);
            s[i]='0',t[i]='0';
            a*=10,b*=10;
        }
        else if(s[i]=='?'){
            if(t[i]-'0'<9){
                s[i]=t[i]-'0'+1+'0';
                ll aa=a,bb=b;
                cal(s,t,i,aa,bb);
                upd(aa,bb,rev);
            }
            s[i]=t[i];
            a=a*10+(s[i]-'0');
            b=b*10+(t[i]-'0');
        }
        else if(t[i]=='?'){
            if(s[i]-'0'>0){
                t[i]=s[i]-'0'-1+'0';
                ll aa=a,bb=b;
                cal(s,t,i,aa,bb);
                upd(aa,bb,rev);
            }
            t[i]=s[i];
            a=a*10+(s[i]-'0');
            b=b*10+(t[i]-'0');
        }
        else{
            if(s[i]<t[i])return;
            if(s[i]>t[i]){
                cal(s,t,i,a,b);
                upd(a,b,rev);
                return;
            }
            a=a*10+(s[i]-'0');
            b=b*10+(t[i]-'0');
        }
    }
    upd(a,b,rev);
}
void print(ll x,int n){
    static int b[20];
    int k=0;
    while(x)b[k++]=x%10,x/=10;
    while(k<n)b[k++]=0;
    per(i,0,k)printf("%d",b[i]);putchar(' ');
}
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int m,j,k,i,T,ca=0;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++ca);
        scanf("%s%s",s,t);
        n=strlen(s);
        int ok=1;
        rep(i,0,n)if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i]){ok=0;break;}
        if(ok){
            rep(i,0,n){
                if(s[i]=='?'&&t[i]!='?')s[i]=t[i];
                else if(t[i]=='?'&&s[i]!='?')t[i]=s[i];
                else if(s[i]=='?'&&t[i]=='?')s[i]=t[i]='0';
            }
            printf("%s %s\n",s,t);
            continue;
        }
        rep(i,0,n)a[i]=s[i],b[i]=t[i];
        ans=-1;
        solve(s,t,0);
        //DBG(ans)
        solve(b,a,1);
        //DBG(ans)
        print(A,n);
        print(B,n);
        puts("");
    }
    //cerr<<1.*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}