#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL long long

int TTT,num;
LL A,B;
int d[20];
int p[2000000];

bool pal(LL x){
	LL xx=x;
	LL y=0;
	while (x>0){
		y=y*10+x%10; x/=10;
	}
	return xx==y;
}

void init(){
	/*
	for (int i=1; i<=1e7; i++){
		if (pal(i)){
			LL j=i;
			j=j*j;
			if (pal(j)){
				p[num++]=i;
			}
		}
	}
	freopen("pal.txt","w",stdout);
	printf("%d\n",num);
	for (int i=0; i<num; i++){
		printf("%d\n",p[i]);
	}
	fclose(stdout);*/
	freopen("pal.txt","r",stdin);
	scanf("%d",&num);
	for (int i=0; i<num; i++){
		scanf("%d",&p[i]);
	}
	fclose(stdin);
}

int main(){
	init();
	
	freopen("C-large-1.in","r",stdin);
	freopen("C.out","w",stdout);
	
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		scanf("%lld %lld",&A,&B);
		int cnt=0;
		
		for (int i=0; i<num; i++){
			LL j=p[i];
			j=j*j;
			if (j>=A && j<=B) cnt++;
		}
		
		printf("%d\n",cnt);
	}
	
	fclose(stdout);
	fclose(stdin);
	
}
