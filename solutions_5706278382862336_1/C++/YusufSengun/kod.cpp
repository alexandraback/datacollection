#include <bits/stdc++.h>

using namespace std;
typedef long long int Lint;

Lint gcd(Lint a,Lint b){
	return (!b) ? (a) : gcd(b,a%b);
}

Lint kont(Lint a){
	for(Lint i=1;i<=a;i*=2)
		if(i==a)
			return 1;
	return 0;
}

Lint find(Lint a){
	for(Lint i=1,j=1;;j++,i*=2)
		if(i>a)
			return j-1;
}

int main(){
	Lint a,b,tmp,N;
	char ch;
	scanf(" %lld",&N);
	for(Lint i=1;i<=N;i++){
		scanf("%lld%c%lld",&a,&ch,&b);
		tmp=gcd(a,b);
		a/=tmp;
		b/=tmp;
		printf("Case #%lld: ",i);
		if(!kont(b))
			printf("impossible\n");
		else
			printf("%lld\n",find(b)-find(a));
	}
	return 0;
}
