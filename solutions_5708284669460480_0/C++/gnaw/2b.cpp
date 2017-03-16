
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define randin srand((unsigned int)time(NULL))
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define MAXN
#define N 22
#define M
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readLL(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s1[100],s2[100];
int k,l,s;
int apptime[100],maxitime,fail[100];
inline void build_fail(char *s,int lens){
    int i=0,j;
    fail[0]=j=-1;
    while(i<lens){
        if(j==-1||s[i]==s[j]){
            fail[i+1]=j+1;
            i++;
            j=j+1;
        }
        else j=fail[j];
    }
}
int kmp(string &text,char *word,int lenword){
    int lentext=(int)text.length();
    int i=0,j=0,res=0;
    while(i<lentext){
        if(j==-1||text[i]==word[j]){
            i++;
            j++;
        }
        else j=fail[j];
        if(j==lenword){
            res+=1;
            j=fail[j];
        }
    }
    return res;
}
inline void dfs(int lens,string& str){
    if(lens==s){
        int t=kmp(str,s2,l);
        maxitime=max(maxitime,t);
        apptime[t]+=1;
        return;
    }
    for(int i=0;i<k;i++){
        string str2=str+s1[i];
        dfs(lens+1,str2);
    }
}
int quickpow(int x,int y){
    if(!y) return 1;
    int res=quickpow(x,y>>1);
    res=res*res;
    if(y&1) res=res*x;
    return res;
}
int main(){
    //input;
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("hehe.out","w",stdout);
    int T=read();
    for(int kase=1;kase<=T;kase++){
        printf("Case #%d: ",kase);
        k=read(),l=read(),s=read();
        scanf("%s",s1);//len=k
        scanf("%s",s2);//len=l
        memset(apptime,0,sizeof(apptime));
        maxitime=0;
        build_fail(s2,l);
        string str;
        str.clear();
        dfs(0,str);
        int tot=quickpow(k,s);
        double ans=0.0;
        for(int i=0;i<=maxitime;i++){
            int le=maxitime-i;
            ans+=(1.0*apptime[i]/tot)*le;
        }
        printf("%.7f\n",ans);
    }
    return 0;
}

