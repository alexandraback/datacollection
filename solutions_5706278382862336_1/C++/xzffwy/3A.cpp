/////////////////////////////////////////////////////////////////////////
// File Name: 3A.cpp
// Author: wang
// mail: 1062239606@qq.com
// Created Time: 2014/5/11 17:16:26
/////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cmath>

#include <algorithm>
#include<iostream>
#include<queue>
#include <map>
using namespace std;
typedef long long ll;
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define N 100000
int n;
ll p,q;
char s[40];
ll gcd(ll x,ll y){
	if(x<y) swap(x,y);
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	int n;
	freopen("e:/acm/pro/in","r",stdin);
	freopen("e:/acm/pro/out.out","w",stdout);
	cin>>n;
	repf(ror,1,n)
	{
		scanf("%s",s);
		int len=strlen(s);
		int i=0;
		p=0,q=0;
		for(i=0; s[i]!='/'; ++i) p=p*10+s[i]-'0';
		for(i=i+1; i<len; ++i) q=q*10+s[i]-'0';
		ll tmp=((ll)2)<<40;
		ll g=gcd(p,q);
		p/=g; q/=g;
		int flag=0;
		if(tmp%q==0){
			p=p*tmp/q;
			int i=1;tmp=tmp>>1;
			while(i<=40){
				if(p>=tmp){
					p-=tmp;
					if(flag==0)
						flag=i;
					break;
				}
				++i;
				tmp=tmp>>1;
			}
		}
		printf("Case #%d: ",ror);
		if(flag==0) puts("impossible");
		else printf("%d\n",flag);
	}
}
