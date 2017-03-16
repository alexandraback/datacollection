/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<ll>
#define PII pair<ll,ll>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define MEM(x,val) memset((x),val,sizeof(x))
#define scan(x) scanf("%lld",&(x))
#define scan2(x,y) scanf("%lld%lld",&(x),&(y))
#define scan3(x,y,z) scanf("%lld%lld%lld",&(x),&(y),&(z))
#define scan4(x,y,z,k) scanf("%lld%lld%lld%lld",&(x),&(y),&(z),&(k))
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define fuck(x) cout<<#x<<" - "<<x<<endl
char s1[1999];
char s2[1999];
#define P(x) ((x)-'0')
ll len;
ll dif,ans1,ans2;
void print(ll x,ll len){
    char tmp[100];
    sprintf(tmp,"%lld",x);
    ll l = strlen(tmp);
    for(ll i=0;i<len-l;i++) putchar('0');
    printf("%s",tmp);
}
void dfs(ll now,ll st,ll n1,ll n2){
    if(now == len){
        if(abs(n1-n2) < dif){
            dif = abs(n1-n2);
            ans1 = n1 , ans2 = n2;
        }else if(abs(n1-n2) == dif && n1 < ans1){
            ans1 = n1 , ans2 = n2;
        }else if(abs(n1-n2) == dif && n1 == ans1 && n2 < ans2){
            ans1 = n1 , ans2 = n2;
        }
        return;
    }
    ll i = now;
    if(isdigit(s1[i]) ){
        if(isdigit(s2[i]) ){
            if(st == 0) {
                if(s1[i]>s2[i]) dfs(now+1, 1, n1*10+P(s1[i]), n2*10+P(s2[i]) );
                else if(s1[i]<s2[i]) dfs(now+1, -1, n1*10+P(s1[i]), n2*10+P(s2[i]) );
                else{
                    dfs(now+1, 0, n1*10+P(s1[i]), n2*10+P(s2[i]) );
                }
            }else if(st==1){
                dfs(now+1, 1, n1*10+P(s1[i]), n2*10+P(s2[i]) );
            }else{
                dfs(now+1, -1, n1*10+P(s1[i]), n2*10+P(s2[i]) );
            }
        }else{
            if(st==0){
                dfs(now+1, 0, n1*10+P(s1[i]), n2*10+P(s1[i]) );
                if(P(s1[i])+1 <= 9) dfs(now+1, -1, n1*10+P(s1[i]), n2*10+P(s1[i])+1 );
                if(P(s1[i])-1 >= 0) dfs(now+1, 1, n1*10+P(s1[i]), n2*10+P(s1[i])-1 );
            }else if(st == 1){
                dfs(now+1, 1, n1*10+P(s1[i]), n2*10+P('9') );
            }else{
                dfs(now+1, -1, n1*10+P(s1[i]), n2*10+P('0') );
            }
        }
    }else{
        if(isdigit(s2[i]) ){
            if(st == 0){
                dfs(now+1, 0, n1*10+P(s2[i]), n2*10+P(s2[i]) );
                if(P(s2[i])+1 <= 9) dfs(now+1, 1, n1*10+P(s2[i])+1, n2*10+P(s2[i]) );
                if(P(s2[i])-1 >= 0) dfs(now+1, -1, n1*10+P(s2[i])-1, n2*10+P(s2[i]) );
            }else if(st==1){
                dfs(now+1, 1, n1*10+P('0'), n2*10+P(s2[i]) );
            }else{
                dfs(now+1, -1, n1*10+P('9'), n2*10+P(s2[i]) );
            }
        }else{
            if(st==0){
                dfs(now+1, 0, n1*10+P('0'), n2*10+P('0') );
                dfs(now+1, 1, n1*10+P('1'), n2*10+P('0') );
                dfs(now+1, -1, n1*10+P('0'), n2*10+P('1') );
            }else if(st == 1){
                dfs(now+1, 1, n1*10+P('0'), n2*10+P('9') );
            }else{
                dfs(now+1, -1, n1*10+P('9'), n2*10+P('0') );
            }
        }
    }
}
int main(){
    //freopen("C:/OJ/OJ/in.txt","r",stdin);
    //freopen("B-large.in","r",stdin);
    //freopen("B-large-2.out","w",stdout);
    ll T;scan(T);
    for(ll cas=1;cas<=T;cas++){
        dif = 0x7fffffffffffffffLL;
        scanf("%s %s",s1,s2);
        len = strlen(s1);
        dfs(0,0,0,0);
        printf("Case #%lld: ", cas);
        //printf("%s %s\n",s1, s2);
        print(ans1,len);
        putchar(' ');
        print(ans2,len);
        putchar('\n');
    }
    return 0;
}
