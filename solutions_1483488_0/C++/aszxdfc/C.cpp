#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;
int ct[1010][1010];
bool check(int n,int m)
{
    int a[10],b[10],k=0;
    while(n) {
        a[k]=n%10;
        b[k++]=m%10;
        n/=10;
        m/=10;
    }
    if(k==1&&a[0]==b[0]) return true;
    if(k==2) {
        if(a[0]==b[1]&&a[1]==b[0]) return true;
    }
    if(k==3) {
        if(a[0]==b[2]&&a[1]==b[0]&&a[2]==b[1]) return true;
        if(a[0]==b[1]&&a[1]==b[2]&&a[2]==b[0]) return true;
    }
    return false;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.txt","w",stdout);
    int A,B,i,T,ans,n,m;
    scanf("%d",&T);
    for(i=1;i<=T;i++) {
        scanf("%d%d",&A,&B);
        ans=0;
        for(n=A;n<=B;n++) {
            for(m=n+1;m<=B;m++) {
                if(check(n,m)) ans++;
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
