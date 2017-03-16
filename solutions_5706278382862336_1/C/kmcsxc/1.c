#include <stdio.h>

long long a[42];
int T;

void init(){
	a[0] = 1;
	for(int i=1;i<=41;i++){
		a[i] = 2*a[i-1];
	}
}

int getM(long long d){
	for(int i=0;i<=41;i++){
		if(a[i]==d)
			return i;
	}
	return -1;
}

long long getM1(long long d){
	for(int i=0;i<=41;i++){
		if(a[i]>d)
			return a[i-1];
	}
	return -1;
}

long long gcd(long long a, long long b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int dfs(long long P,long long Q,int age){
	int div = gcd(P,Q);
	P /= div;
	Q /= div;
	if(age>40){
		return -1;
	}
	if(P==1&&Q==1){
		return age;
	}
	if(P%2==0){
		return dfs(P/2,Q/2,age+1);
	}
	else {
		Q /= 2;
		if(P>=Q){
			return dfs(Q,Q,age+1);
		}
		else {
			P = getM1(P);
			return dfs(P,Q,age+1);
		}
		
	}
}

int main(){
	init();
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		long long P,Q;
		scanf("%lld/%lld",&P,&Q);
		printf("Case #%d:",Case);
		long long div = gcd(P,Q);
		P /= div;
		Q /= div;
		if(P>Q){
			printf(" impossible\n");
			continue;
		}
		int age = getM(Q);
		//printf("%lld\n",a[1]);
		if(age == -1){
			printf(" impossible\n");
			continue;
		}
		age = dfs(P, Q, 0);
		if(age==-1)
			printf(" impossible\n");
		else
			printf(" %d\n",age);
	}
}