#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<iostream>
#include<vector>
#include<sstream>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
#define inf 1e7
typedef long long int ll;
using namespace std;

int main(){
int t,kase=0;
cin>>t;
while(t--){kase++;
int z,i,j,k,r,c,x;
cin>>x>>r>>c;
int flag=1;
if(r>c){swap(r,c);}
if(x>r){
k=(r*c)-x-(x-r);z=x-r;
for(i=0;i<=z;i++){
for(j=0;j<=c-1;j++){
if(((j*r)-i)%x==0&&(((c-j-1)*r)-(z-i))%x==0){break;}}
if(j==c){flag=0;}
}
}
else{
k=(r*c)-x-(x-r);z=x-(r%x);if(r%x==0){z-=x;}
for(i=0;i<=z;i++){
for(j=0;j<=c-1;j++){
if(((j*r)-i)%x==0&&(((c-j-1)*r)-(z-i))%x==0){break;}}
if(j==c){flag=0;}
}
}
printf("Case #%d: ",kase);
if(flag==0){cout<<"RICHARD";}
else{cout<<"GABRIEL";}
pn;
}
return 0;}




