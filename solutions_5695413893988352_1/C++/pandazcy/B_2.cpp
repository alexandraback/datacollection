#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int T,t,n,m;
char s[2][20];
ll ans1,ans2,a,b,POW[20];
ll dig[30];
bool solve(int pos,int cha){
    a=0;b=0;
    int i,j;
    int l1,l2,r1,r2,k1,k2;
    bool flag;
    for(i=1;i<pos;i++){
        if(s[0][i]=='?' && s[1][i]=='?')
            continue;
        else if(s[0][i]=='?'){
            a+=POW[i]*(s[1][i]-'0');
            b+=POW[i]*(s[1][i]-'0');
        }
        else if(s[1][i]=='?'){
            a+=POW[i]*(s[0][i]-'0');
            b+=POW[i]*(s[0][i]-'0');
        }
        else if(s[0][i]==s[1][i]){
            a+=POW[i]*(s[0][i]-'0');
            b+=POW[i]*(s[0][i]-'0');
        }
        else
            return false;
        //if(pos==3 && cha==0)
        //    printf("i=%d a=%lld b=%lld\n",i,a,b);
    }
    l1=l2=0;
    r1=r2=9;
    if(s[0][pos]!='?')
        l1=r1=s[0][pos]-'0';
    if(s[1][pos]!='?')
        l2=r2=s[1][pos]-'0';
    flag=0;
    for(k1=l1;k1<=r1 && !flag;k1++)
        for(k2=l2;k2<=r2;k2++)
            if(k1-k2==cha){
                flag=1;
                a+=k1*POW[pos];
                b+=k2*POW[pos];
                break;
            }
    if(!flag)
        return false;
    for(i=pos+1;i<=n;i++){
        if(cha<=0){
            if(s[0][i]=='?')
                a+=9*POW[i];
            else
                a+=(s[0][i]-'0')*POW[i];
            if(s[1][i]=='?')
                b+=0*POW[i];
            else
                b+=(s[1][i]-'0')*POW[i];
        }
        else if(cha>0){
            if(s[0][i]=='?')
                a+=0*POW[i];
            else
                a+=(s[0][i]-'0')*POW[i];
            if(s[1][i]=='?')
                b+=9*POW[i];
            else
                b+=(s[1][i]-'0')*POW[i];
        }

    }
    //if(a==455 && b==455)
    //    printf("check %d %d\n",pos,cha);
    return true;
}
void print(ll num){
    int i,j,k=0;
    ll ret=num;
    while(ret>0){
        k++;
        ret/=10;
    }
    //printf("num=%lld   n=%d k=%d\n",num,n,k);
    for(i=k+1;i<=n;i++)
        printf("0");
    if(num!=0)
    printf("%lld",num);
}
int main(){
        freopen("B-large.in","r",stdin);    //数据读入
    freopen("out2.txt","w",stdout);  //数据输出
    int i,j,k;
    bool flag;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        ans1=1e18;ans2=1e18+1e18+10;
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        n=strlen(s[0]+1);
        POW[n]=1;
        for(i=n-1;i>=1;i--)
            POW[i]=POW[i+1]*10;
        for(i=1;i<=n;i++)
            for(j=-9;j<=9;j++){
                flag=solve(i,j);
                if(!flag)
                    continue;
                    if(abs(a-b)<abs(ans1-ans2)){
                        ans1=a;
                        ans2=b;
                    }
                    else if(abs(a-b)==abs(ans1-ans2)){
                        if(a<ans1){
                            ans1=a;
                            ans2=b;
                        }
                        else if(a==ans1)
                            ans2=min(ans2,b);
                    }
            }
        printf("Case #%d: ",t);
        print(ans1);
        printf(" ");
        print(ans2);
        printf("\n");
    }
}
