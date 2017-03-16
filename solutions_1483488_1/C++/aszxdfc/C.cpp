#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;
int A,B;
int sol(int n)
{
    int temp=n,ct=0,temp1,p=1,ans=0;
    while(temp) {
        temp/=10;
        ct++;
        
    }
    for(int i=1;i<ct;i++) p*=10;
    temp=n;
    while(ct--) {
        temp1=temp%10;
        temp=temp1*p+(temp/10);
        if(temp>n&&temp<=B) ans++;
        //printf("%d %d\n",temp,n);
    }
    printf("%d %d\n",n,ans);
    return ans;
}
int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    freopen("C1.txt","w",stdout);
    int i,T,ans,n,m;
    scanf("%d",&T);
    for(i=1;i<=T;i++) {
        scanf("%d%d",&A,&B);
        ans=0;
        for(n=A;n<B;n++) {
            ans+=sol(n);
        }
       // printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
