// Author : y07uc118
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;
long long int gcd(long long int a,long long int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
bool notpower(long long int b){
	if((b&(b-1))==0)
		return false;
	else
		return true;
}
template<typename T>
void scan(T& a,T&b){
	a=0; b=0;
	char c=getchar();
	while((c<'0' || c>'9') ) c=getchar();
	
	while(c>='0' && c<='9'){
		a = (a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	while((c<'0' || c>'9') ) c=getchar();
	while(c>='0' && c<='9'){
		b = (b<<3)+(b<<1)+c-'0';
		c=getchar();
	}

}

int main(){

	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	long long int a,b;
	int t,q=1,count;
	scanf("%d",&t);
	while(t--){
		printf("Case #%d: ",q++);
		scan(a,b);
		//printf("%lld %lld\n",a,b);
		if(a==1 && b==1) { printf("0\n"); continue; }
		long long int g=gcd(a,b);
		//printf("gcd:%lld\n",g);
		a/=g;
		b/=g;
		//printf("%lld %lld\n",a,b);
		if(b%2) {printf("impossible\n"); continue;}
		if(notpower(b)) {printf("impossible\n"); continue;}
		b/=2; count=1;
		while(a<b){
			b/=2;
			count++;
		}
		printf("%d\n",count);
	}

	return 0;
}
