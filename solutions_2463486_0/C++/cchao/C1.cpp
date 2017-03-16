#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a, b;

int ispalin(int x){
	int l[20], sz=0;
	while(x){l[sz++]=x%10; x/=10;}
	for(int i = 0; i < sz/2; ++i){
		if(l[i]!=l[sz-i-1])return 0;
	}
	return 1;
}
void judge(){
	int low=sqrt(double(a)), hi = sqrt(double(b)), ans = 0;
	while(low*low<a)++low;
	while(hi*hi>b)--hi;
	for(int i = low; i <= hi; ++i){
		if(ispalin(i) && ispalin(i*i)) ans++;
	}
	printf("%d\n", ans);
}
int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d", &a, &b);
		printf("Case #%d: ", kase);
		judge();
	}
	return 0;
}
