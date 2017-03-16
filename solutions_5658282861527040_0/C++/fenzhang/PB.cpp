#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long int lnt;
typedef double dou;
int a,b,c;
int dd[2000];
void sol(int uuu){
	scanf("%d %d %d",&a,&b,&c);
	for(int k=0;k<2000;k++){
		dd[k]=0;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			dd[i&j]++;
		}
	}
	lnt ans=0;
	for(int k=0;k<c;k++){
		ans=ans+dd[k];
	}
	printf("Case #%d: %I64d\n",uuu,ans);
	/*
	for(int i=0;i<31;i++){
		if((a&(1<<i))==0){a-=(1<<i);}
		if((b&(1<<i))==0){b-=(1<<i);}
		if((c&(1<<i))==0){c-=(1<<i);}
		if(a<0||b<0||c<0)break;
		
	}
	*/
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("pb_s.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)sol(ti);
	return 0;
}

