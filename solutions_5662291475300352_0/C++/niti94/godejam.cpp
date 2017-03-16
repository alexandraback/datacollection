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
int a[20][20],r,c;int ans;

int check(int i,int j){
if(i>=r||j>=c||i<0||j<0){return 0;}return 1;}

int rec(int i,int j,int k){

//cout<<i<<" "<<j<<" "<<k;pn;


if(k==0){int sum=0;//cout<<"hh";pn;
for(int ind1=0;ind1<r;ind1++){
for(int ind2=0;ind2<c;ind2++){
//cout<<a[ind1][ind2];pw;
if(check(ind1-1,ind2)==1&&a[ind1][ind2]==1){if(a[ind1-1][ind2]==1){sum++;}}
if(check(ind1+1,ind2)==1&&a[ind1][ind2]==1){if(a[ind1+1][ind2]==1){sum++;}}
if(check(ind1,ind2-1)==1&&a[ind1][ind2]==1){if(a[ind1][ind2-1]==1){sum++;}}
if(check(ind1,ind2+1)==1&&a[ind1][ind2]==1){if(a[ind1][ind2+1]==1){sum++;}}

}}
//cout<<sum;pn;
ans=min(ans,sum);return 0;}

if(i>=r||j>=c||i<0||j<0){return 0;}


if(j==c-1){a[i][j]=1;rec(i+1,0,k-1);a[i][j]=0;rec(i+1,0,k);}
else{a[i][j]=1;rec(i,j+1,k-1);a[i][j]=0;rec(i,j+1,k);}
return 0;}



int main(){
int t,kase=0;
cin>>t;
while(t--){kase++;

int n,i,j,k,m;ans=inf;
cin>>r>>c>>n;
memset(a,0,sizeof(a));//cout<<n;pn;
rec(0,0,n);
printf("Case #%d: ",kase);
cout<<ans/2;
pn;}
return 0;}


