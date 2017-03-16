#include <bits/stdc++.h>
#define mid (lo+hi)/2
#define win1 printf("Case #%d: GABRIEL\n",test)
#define win2 printf("Case #%d: RICHARD\n",test)
using namespace std;
const bool SUBMIT=true;
const int I=2;
const int J=3;
const int K=4;
const int MAXN=10010;
string s;
char frontt[4*MAXN];
int mul(int a,int b)
{
    bool sign1=a<0;
    bool sign2=b<0;
    a=abs(a);
    b=abs(b);
    bool inv;
    if(sign1!=sign2)
        inv=true;
    else inv=false;
    int ret;
    if(b==I)
    {
        if(a==1) ret= I;
        if(a==I) ret= -1;
        if(a==J) ret= -K;
        if(a==K) ret= J;
    }
    if(b==J)
    {
        if(a==1) ret= J;
        if(a==I) ret= K;
        if(a==J) ret= -1;
        if(a==K) ret= -I;
    }
    if(b==K)
    {
        if(a==1) ret= K;
        if(a==I) ret= -J;
        if(a==J) ret= I;
        if(a==K) ret= -1;
    }
    if(b==1)
    {
        if(a==1) ret= 1;
        if(a==I) ret= I;
        if(a==J) ret= J;
        if(a==K) ret= K;
    }
    if(inv) return -ret;
    return ret;
}
int c(char cc)
{
    if(cc=='i') return I;
    if(cc=='j') return J;
    if(cc=='k') return K;
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int l;
        long long x;
        scanf("%d%lld",&l,&x);
        cin >> s;
        int whole=1;
        for(int i=0;i<l;i++)
        {
            whole=mul(whole,c(s[i]));
        }
        int mod=x%4;
        int prod=1;
        while(mod--) prod=mul(prod,whole);
        //printf("PROD: %d\n",prod);
        if(prod!=-1)
        {
            printf("Case #%d: NO\n",test);
            continue;
        }
        if(x<=4)
        {
            int first=-1,last=-1;
            int ss=1;
            string to="";
            while(x--) to+=s;
            for(int i=0;i<to.length();i++)
            {
                ss=mul(ss,c(to[i]));
                if(ss==I) {first=i;break;}
            }
            ss=1;
            for(int i=0;i<to.length();i++)
            {
                ss=mul(ss,c(to[i]));
                //printf("%d ",ss);
                if(ss==K) {last=i;}
            }
            //printf("%d %d\n",first,last);
            if(first==-1||last==-1||first>=last) printf("Case #%d: NO\n",test);
            else printf("Case #%d: YES\n",test);
            continue;
        }
        long long first=-1,last=-1;
        for(int i=0;i<l;i++) frontt[i]=frontt[i+l]=frontt[i+2*l]=frontt[i+3*l]=s[i];
        int ss=1;
        for(int i=0;i<4*l;i++)
        {
            ss=mul(ss,c(frontt[i]));
            if(ss==I) {first=i;break;}
        }
        ss=1;
        for(int i=0;i<4*l;i++)
        {
            ss=mul(ss,c(frontt[i]));
            if(ss==-K) {last=i;}
        }
        if(first==-1||last==-1)
        {
            printf("Case #%d: NO\n",test);
            continue;
        }
        last=x*l+(last-4*l);
        if(first<last&&last!=(x*l-1))
        {
            printf("Case #%d: YES\n",test);
            continue;
        }
        else
        {
            printf("Case #%d: NO\n",test);
            continue;
        }
    }
    return 0;
}
