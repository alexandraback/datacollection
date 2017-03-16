#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;
typedef __int64 LL;
const int N=20;
char ss[N],tt[N];
int aa[N],bb[N];
LL ans=1LL<<62;
string ans1,ans2;
int n;
void fun(){
    LL a1=0,b1=0;
    for(int i=0;i<n;i++){
        a1=a1*10+aa[i];
        b1=b1*10+bb[i];
    }
    a1=abs(a1-b1);
    if(a1<ans){
        ans=a1;ans1="";
        for(int i=0;i<n;i++){
            ans1+=aa[i]+'0';
        }
        for(int i=0;i<n;i++){
            ans1+=bb[i]+'0';
        }
    }
    else if(a1==ans){
        ans2="";
        for(int i=0;i<n;i++){
            ans2+=aa[i]+'0';
        }
        for(int i=0;i<n;i++){
            ans2+=bb[i]+'0';
        }
        if(ans1.compare(ans2)>0)ans1=ans2;
    }
}
void gun(int i){
    if(ss[i]=='?'&&tt[i]=='?'){
        aa[i]=1;bb[i]=0;
        fun();
    }
    else if(ss[i]=='?'){
        if(tt[i]!='9'){
            aa[i]=tt[i]-'0'+1;bb[i]=tt[i]-'0';
            fun();
        }
    }
    else if(tt[i]=='?'){
        if(ss[i]!='0'){
            aa[i]=ss[i]-'0';
            bb[i]=ss[i]-'0'-1;
            fun();
        }
    }
    else if(ss[i]>tt[i]){
        aa[i]=ss[i]-'0';
        bb[i]=tt[i]-'0';
        fun();
    }
}
void tun(int i){
    if(ss[i]=='?'&&tt[i]=='?'){
        aa[i]=0;bb[i]=1;
        fun();
    }
    else if(ss[i]=='?'){
        if(tt[i]!='0'){
            aa[i]=tt[i]-'0'-1;bb[i]=tt[i]-'0';
            fun();
        }
    }
    else if(tt[i]=='?'){
        if(ss[i]!='9'){
            aa[i]=ss[i]-'0';
            bb[i]=ss[i]-'0'+1;
            fun();
        }
    }
    else if(ss[i]<tt[i]){
        aa[i]=ss[i]-'0';
        bb[i]=tt[i]-'0';
        fun();
    }
}
int main()
{
    #ifdef DouBi
    freopen("in.cpp","r",stdin);
    freopen("out.cpp","w",stdout);
    #endif // DouBi
    //printf("%I64d\n",ans);
    int T;scanf("%d",&T);
    int cas=1;
    while(T--){
        ans=1LL<<62;
        scanf("%s%s",ss,tt);
        n=strlen(ss);
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                if(ss[j]=='?'&&tt[j]=='?')aa[j]=bb[j]=0;
                else if(ss[j]=='?')aa[j]=bb[j]=tt[j]-'0';
                else if(tt[j]=='?')aa[j]=bb[j]=ss[j]-'0';
                else aa[j]=bb[j]=ss[j]-'0';
            }
            if(i==n){
                fun();continue;
            }
            for(int j=i+1;j<n;j++){
                if(ss[j]!='?')aa[j]=ss[j]-'0';
                else aa[j]=0;
                if(tt[j]!='?')bb[j]=tt[j]-'0';
                else bb[j]=9;
            }
            gun(i);
            for(int j=i+1;j<n;j++){
                if(ss[j]!='?')aa[j]=ss[j]-'0';
                else aa[j]=9;
                if(tt[j]!='?')bb[j]=tt[j]-'0';
                else bb[j]=0;
            }
            tun(i);
            if(ss[i]!='?'&&tt[i]!='?'&&ss[i]!=tt[i])break;
        }
        printf("Case #%d: ",cas++);
        for(int i=0;i<n;i++)printf("%c",ans1[i]);printf(" ");
        for(int i=0;i<n;i++)printf("%c",ans1[n+i]);printf("\n");
    }
    return 0;
}
