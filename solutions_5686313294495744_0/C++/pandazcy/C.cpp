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
map<string,int> match;
int num[20][2];
char s[100];
int real[20],fake;
bool check(int S){
    //printf("check %d\n",S);
    int i,j,k=0;
    fake=0;
    bool flag1,flag2;
    while(S){
        k++;
        if(S&1)
            real[k]=1;
        else
            real[k]=0,fake++;
        S/=2;
    }
    for(k++;k<=n;k++)
        real[k]=0,fake++;
    for(i=1;i<=n;i++)
        if(real[i]==0){
            flag1=flag2=0;
            for(j=1;j<=n;j++)
                if(real[j]==1){
                    if(num[j][0]==num[i][0])
                        flag1=1;
                    if(num[j][1]==num[i][1])
                        flag2=1;
                }
            if(flag1 && flag2)
                continue;
            else
                return false;
        }
    return true;
}
int main(){
        freopen("C-small-attempt0.in","r",stdin);    //数据读入
    freopen("out.txt","w",stdout);  //数据输出
    int i,j,k,S,MAXS,ans;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        match.clear();
        k=0;
        for(i=1;i<=n;i++)
            for(j=0;j<2;j++){
                scanf("%s",s);
                if(match.find(s)!=match.end())
                    num[i][j]=match[s];
                else{
                    match[s]=++k;
                    num[i][j]=k;
                }

            }
        ans=0;
        MAXS=1<<n;
        //printf("%d\n",MAXS);
        for(S=0;S<MAXS;S++)
            if(check(S))
               ans=max(ans,fake);
        printf("Case #%d: %d\n",t,ans);
    }
}
