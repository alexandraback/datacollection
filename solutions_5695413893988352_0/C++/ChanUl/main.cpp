#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char a[15],b[15];
int an,bn,mn;
int ans_a,ans_b;
void make_b (int d,int num)
{
    if(d==n){
        bn=num;
        if(abs(an-bn)<mn){
            ans_a=an;
            ans_b=bn;
            mn=abs(an-bn);
        }
        return ;
    }
    num*=10;
    if(b[d]!='?'){
        num+=(b[d]-'0');
        make_b(d+1,num);
    }
    else{
        for(int i=0;i<10;i++)
            make_b(d+1,num+i);
    }

    return ;
}
void make_a (int d,int num)
{
    if(d==n){
        an=num;
        make_b(0,0);
        return ;
    }
    num*=10;
    if(a[d]!='?'){
        num+=(a[d]-'0');
        make_a(d+1,num);
    }
    else{
        for(int i=0;i<10;i++)
            make_a(d+1,num+i);
    }
}
void solve (void)
{
    an=bn=ans_a=ans_b=0; mn=999;
    n=strlen(a);
    make_a(0,0);

    int t,x=1;
    for(int i=1;i<n;i++) x*=10;

    t=x;
    while(t>0){
        printf("%d",ans_a/t);
        ans_a%=t;
        t/=10;
    }

    printf(" ");
    t=x;
    while(t>0){
        printf("%d",ans_b/t);
        ans_b%=t;
        t/=10;
    }
    printf("\n");

    return ;
}
int main (void)
{
    int i,t;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s %s",a,b);
        printf("Case #%d: ",i+1);
        solve();
    }

    return 0;
}
