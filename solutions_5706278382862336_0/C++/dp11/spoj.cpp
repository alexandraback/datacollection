#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
ll pow[42];
ll gcd(ll a,ll b)
{
	if(b==0)	return a;
	return gcd(b,a%b);
}
int check(ll p)
{
	for(int i=0;i<=40;i++)	if(p==pow[i])	return i;
	return -1;
}
int main()
{
	pow[0]=1;
	for(int i=1;i<=40;i++)	pow[i]=pow[i-1]<<1;
	ll p,q,r;
	int test,v1,v2;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		scanf("%lld/%lld",&p,&q);
		r=gcd(p,q);
		p/=r;
		q/=r;
		v2=check(q);
		if(v2==-1 || p>q){
			printf("Case #%d: impossible\n",i);
			continue;
		}
		v1=0;
		while(p!=1){
			p/=2;
			v1++;	
		}
		printf("Case #%d: %d\n",i,v2-v1);
	}	
	return 0;
}
