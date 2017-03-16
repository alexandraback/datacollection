#include<cstdio>
#include<cmath>
#define llt long long int
llt gcd(llt a,llt b){
	if(a == 0)return b;
	if(b == 0)return a;
	return gcd(b,a%b);
}
bool isTwoEx(llt a){
	do{
		if(a % 2 == 1 && a != 1)return false;
	}while(a /= 2);
	return true;
}
int TwoEx(llt b,llt a){
	int result = 0;
	while(a > b){
		++result;
		a /= 2;
	}
	return result;
}
int main(){
	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		llt P,Q;
		scanf("%lld/%lld",&P,&Q);
		llt cd = gcd(P,Q);
		P /= cd;
		Q /= cd;
		printf("Case #%d: ",Case++);
		if(isTwoEx(Q)){
			printf("%d\n",TwoEx(P,Q));
		}else{
			puts("impossible");
		}
	}
	return 0;
}
