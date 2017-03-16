#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define Long (LL) 1E14
using namespace std;

bool submit=true;
int T,Testc,s[10000002];
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
void prep(LL n){
	s[0]=0;
	for(LL i=1;i*i<=n;i++){
		if(is_palin(i) && is_palin(i*i)) s[i]=s[i-1]+1;
		else s[i]=s[i-1];
	}
}
int f(LL n){return s[(int)sqrt(n)];}
int main(){
	if(submit){
		freopen("C-large-1.in.txt","r",stdin);
		freopen("C-large-1.txt","w",stdout);
	}
	scanf("%d",&T);
	prep(Long);
	for(int Testc=1;Testc<=T;Testc++){
		scanf("%I64d %I64d",&l,&r);
		printf("Case #%d: %d\n",Testc,f(r)-f(l-1));
	}
	return 0;
}
