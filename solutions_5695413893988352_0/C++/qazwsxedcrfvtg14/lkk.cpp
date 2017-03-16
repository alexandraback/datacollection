#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic error "-std=c++11"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
char s[100],ss[100];
int n;
//0 cant' change
//1 s can add
//2 s can minus
//3 s can both
int F(int i,int type){
    if(i==n)return 0;
    if(s[i]=='?'&&ss[i]=='?'){
        int ret=F(i+1,3);
        ss[i]='0'+ret/2;
        s[i]='0'+ret%2;
        if(ret/2&&type/2&&i&&s[i-1]=='?'&&ss[i-1]!='?'){
            s[i]='9';
            ss[i]='0';
            return 2;
            }
        return 0;
        }
    else if(s[i]=='?'){
        int ret;
        if(ss[i]=='0'&&!(type/2))
            ret=F(i+1,1);
        else if(ss[i]=='9'&&!(type%2))
            ret=F(i+1,2);
        else
            ret=F(i+1,3);
        s[i]=ss[i];
        if(ret==1){
            if(ss[i]=='9'){
                s[i]='0';
                return 1;
                }
            s[i]++;
            return 0;
            }
        else if(ret==2){
            if(ss[i]=='0'){
                s[i]='9';
                return 2;
                }
            s[i]--;
            return 0;
            }
        else return 0;
        }
    else if(ss[i]=='?'){
        int ret;
        if(s[i]=='0'&&!(type%2))
            ret=F(i+1,2);
        else if(s[i]=='9'&&!(type/2))
            ret=F(i+1,1);
        else
            ret=F(i+1,3);
        ss[i]=s[i];
        if(ret==1){
            if(s[i]=='0'){
                ss[i]='9';
                return 1;
                }
            ss[i]--;
            return 0;
            }
        else if(ret==2){
            if(s[i]=='9'){
                ss[i]='0';
                return 2;
                }
            ss[i]++;
            return 0;
            }
        else return 0;
        }
    else{
        if(s[i]==ss[i]){
            F(i+1,0);
            return 0;
            }
        else if(s[i]>ss[i]){
            if(!(type/2)){
                for(int j=i;j<n;j++)
                    if(s[j]=='?')s[j]='0';
                for(int j=i;j<n;j++)
                    if(ss[j]=='?')ss[j]='9';
                return 0;
                }
            else{
                long long int a=0,b=0,c=0,d=1;
                for(int j=i;j<n;j++)
                    if(s[j]=='?')a=a*10+0;
                    else a=a*10+s[j]-'0';
                for(int j=i;j<n;j++)
                    if(ss[j]=='?')b=b*10+9;
                    else b=b*10+ss[j]-'0';
                for(int j=i;j<n;j++)
                    if(s[j]=='?')c=c*10+9;
                    else c=c*10+s[j]-'0';
                for(int j=i;j<n;j++)
                    if(ss[j]=='?')d=d*10+0;
                    else d=d*10+ss[j]-'0';
                if(a-b<d-c){
                    for(int j=i;j<n;j++)
                        if(s[j]=='?')s[j]='0';
                    for(int j=i;j<n;j++)
                        if(ss[j]=='?')ss[j]='9';
                    return 0;
                    }
                else if(a-b>d-c){
                    for(int j=i;j<n;j++)
                        if(s[j]=='?')s[j]='9';
                    for(int j=i;j<n;j++)
                        if(ss[j]=='?')ss[j]='0';
                    return 2;
                    }
                else{
                    if(i&&s[i-1]=='?'&&ss[i-1]!='?'){
                        for(int j=i;j<n;j++)
                            if(s[j]=='?')s[j]='9';
                        for(int j=i;j<n;j++)
                            if(ss[j]=='?')ss[j]='0';
                        return 2;
                        }
                    else{
                        for(int j=i;j<n;j++)
                            if(s[j]=='?')s[j]='0';
                        for(int j=i;j<n;j++)
                            if(ss[j]=='?')ss[j]='9';
                        return 0;
                        }
                    }
                }
            }
        else{
            if(!(type%2)){
                for(int j=i;j<n;j++)
                    if(s[j]=='?')s[j]='9';
                for(int j=i;j<n;j++)
                    if(ss[j]=='?')ss[j]='0';
                return 0;
                }
            else{
                long long int a=1,b=0,c=0,d=0;
                for(int j=i;j<n;j++)
                    if(s[j]=='?')a=a*10+0;
                    else a=a*10+s[j]-'0';
                for(int j=i;j<n;j++)
                    if(ss[j]=='?')b=b*10+9;
                    else b=b*10+ss[j]-'0';
                for(int j=i;j<n;j++)
                    if(s[j]=='?')c=c*10+9;
                    else c=c*10+s[j]-'0';
                for(int j=i;j<n;j++)
                    if(ss[j]=='?')d=d*10+0;
                    else d=d*10+ss[j]-'0';
                if(a-b<d-c){
                    for(int j=i;j<n;j++)
                        if(s[j]=='?')s[j]='0';
                    for(int j=i;j<n;j++)
                        if(ss[j]=='?')ss[j]='9';
                    return 1;
                    }
                else{
                    for(int j=i;j<n;j++)
                        if(s[j]=='?')s[j]='9';
                    for(int j=i;j<n;j++)
                        if(ss[j]=='?')ss[j]='0';
                    return 0;
                    }
                }
            }
        }
    }
//0 nothing
//1 s add
//2 s minus
int m=999,a=0,b=0,ma,mb;
void G(int i){
    if(i==n){
        if(abs(a-b)<m){
            m=abs(a-b);
            ma=a;
            mb=b;
            }
        else if(abs(a-b)==m){
            if(a<ma||(a==ma&&b<mb)){
                ma=a;
                mb=b;
                }
            }
        return;
        }
    if(ss[i]=='?'){
        for(int j=0;j<10;j++)
            b=b*10+j,G(i+1),b/=10;
        }
    else{
        b=b*10+ss[i]-'0';
        G(i+1);
        b/=10;
        }
    }
void H(int i){
    if(i==n){
        G(0);
        return;
        }
    if(s[i]=='?'){
        for(int j=0;j<10;j++)
            a=a*10+j,H(i+1),a/=10;
        s[i]='?';
        }
    else{
        a=a*10+s[i]-'0';
        H(i+1);
        a/=10;
        }
    }
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        scanf("%s%s",s,ss);
        n=strlen(s);
        m=999,a=0,b=0;
        H(0);
        F(0,0);
        int x,y;
        sscanf(s,"%d",&x);
        sscanf(ss,"%d",&y);
        //if(ma!=x||mb!=y){
        if(n==1)
        printf("Case #%d: %01d %01d\n",T,ma,mb);
        if(n==2)
        printf("Case #%d: %02d %02d\n",T,ma,mb);
        if(n==3)
        printf("Case #%d: %03d %03d\n",T,ma,mb);
            //printf("Case #%d: %03s %03s\n",T,s,ss);
            //}
        }
    }
