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
int i,j,k,m,n,ans=inf;

cin>>n;int a[n];
rep(i,n){cin>>a[i];}


for(j=1;j<=1000;j++){int sum=0;
rep(i,n){

if(a[i]<=j){continue;}


k=a[i]/j;
if(a[i]%j==0){k--;}
sum+=k;
}
ans=min(ans,j+sum);
}
printf("Case #%d: ",kase);pi(ans);
pn;}
return 0;}


