#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

bool submit=true;
int T,Testc;
LL l,r;
bool is_palin(LL n){
	int s[29],p=0;
	while(n>0){
		s[p++]=n%10;
		n/=10;
	}
	for(int i=0;i<p/2;i++){
		if(s[i]!=s[p-1-i]) return false;
	}
	return true;
}
int f(LL n){
	int ans=0;
	for(LL i=1;i*i<=n;i++){
		if(is_palin(i) && is_palin(i*i)) ans++;
	}
	return ans;
}
int main(){
	if(submit){
		freopen("C-small-attempt0.in.txt","r",stdin);
		freopen("C-small-attempt0.txt","w",stdout);
	}
	scanf("%d",&T);
	for(int Testc=1;Testc<=T;Testc++){
		scanf("%I64d %I64d",&l,&r);
		printf("Case #%d: %d\n",Testc,f(r)-f(l-1));
	}
	return 0;
}
