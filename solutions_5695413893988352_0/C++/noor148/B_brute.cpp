#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define si(a) scanf("%d",&a)

char s1[25],s2[25];

void func(char s[],int x,int tot)
{
    int i;
    for(i=0;i<tot;i++){
        s[i]=x%10+'0';
        x/=10;
    }
    for(i=0;i<tot/2;i++)
        swap(s[i],s[tot-i-1]);
    return ;
}

void solve(int ca)
{
    int i,j;
    scanf("%s%s",s1,s2);
    int len=strlen(s1),mnabs=1000000000,ma,mb;
    int tot=1;
    for(i=0;i<len;i++)
        tot*=10;
    for(i=0;i<tot;i++){
        for(j=0;j<tot;j++){
            char t1[25],t2[25];
            int k;
            func(t1,i,len);
            func(t2,j,len);
            for(k=0;k<len;k++){
                if((s1[k]!='?' && s1[k]!=t1[k]) || (s2[k]!='?' && s2[k]!=t2[k]))
                    break;
            }
            if(k==len){
                if(abs(i-j)<mnabs){
                    mnabs=abs(i-j);
                    ma=i;
                    mb=j;
                }
                else if(abs(i-j)==mnabs){
                    if(i<ma){
                        ma=i;
                        mb=j;
                    }
                    else if(i==ma && j<mb){
                        mb=j;
                    }
                }
            }
        }
    }
    func(s1,ma,len);
    func(s2,mb,len);
    printf("Case #%d: %s %s\n",ca,s1,s2);
}

int main()
{
    //freopen("B-small-attempt2.in","r",stdin);
    //freopen("B-small-attempt2.out","w",stdout);
    int t;
    si(t);
    for(int ca=1;ca<=t;ca++)
        solve(ca);
    return 0;
}
