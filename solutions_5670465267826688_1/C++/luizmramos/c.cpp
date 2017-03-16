#include <stdio.h>

long long prod[4][4] = {
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}
};

long long sign[4][4]={
	{1,1,1,1},
	{1,-1,1,-1},
	{1,-1,-1,1},
	{1,1,-1,-1}
};

struct quartenion {
	long long type;
	long long signal;
};

quartenion operator *(const quartenion& a, const quartenion& b){
	quartenion c;
	c.type=prod[a.type][b.type];
	c.signal = sign[a.type][b.type] * a.signal * b.signal;
	return c;
}

quartenion v[10100];


quartenion unidade;

quartenion pow(quartenion a, long long n){
	if(n==0)return unidade;
	if(n==1)return a;
	if(n==2)return a*a;
	return pow(pow(a,n/2),2)*pow(a,n%2);
}

int main(){
	unidade.type=0;
	unidade.signal=1;
	long long t;
	scanf("%d",&t);
	for(long long xxx=0;xxx<t;xxx++){
		long long l;
		long long x;
		scanf("%lld %lld",&l,&x);
		for(long long i=0;i<l;i++){
			char c;
			scanf(" %c ",&c);
			v[i].signal=1;
			v[i].type = c-'i'+1;
		}
		quartenion prefix;
		prefix.type=0;
		prefix.signal=1;
		long long indicePref=-1;
		for(long long i=0;i<10*l;i++){
			if(i>=l*x)break;
			prefix=prefix*v[i%l];
			if(prefix.signal == 1 && prefix.type == 1) {
				indicePref = i;
				break;
			} 
		}

		quartenion suffix;
		suffix.type=0;
		suffix.signal=1;
		long long indiceSuf=-1;
		for(long long i=0;i<10*l;i++){
			if(i>=l*x)break;
			suffix=v[l-1-i%l]*suffix;
			if(suffix.signal == 1 && suffix.type == 3) {
				indiceSuf = l*x - 1 - i;
				break;
			} 
		}

		quartenion total;
		total.signal=1;
		total.type=0;
		for(long long i=0;i<l;i++){
			total=total*v[i];
		}
		total=pow(total,x);

		if(total.type==0 && total.signal==-1 && indiceSuf != -1 && indicePref != -1 && indiceSuf>indicePref+1) {
			printf("Case #%lld: YES\n", xxx+1);
			//printf("%lld %lld\n", indicePref, indiceSuf);
		}
		else {
			printf("Case #%lld: NO\n", xxx+1);
		}
	}
}