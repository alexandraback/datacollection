#include<iostream>
#include<stdio.h>
using namespace std;

int input()
{
int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return(t);
}

int main(){
int test,t,r,am,ans,x,in,i;
t=input();
for(i=1;i<=t;++i){
    ans=0;
    in=0;
r=input();
am=input();
x=r;
while(ans<=am){
ans=ans+2*x+1;
x=x+2;
in++;
}
in--;
printf("Case #%d: %d\n",i,in);
}
return 0;
}
