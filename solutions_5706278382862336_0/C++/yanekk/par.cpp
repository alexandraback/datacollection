#include <stdio.h>

using namespace std;

long long Pot[50];

long long NWD(long long a,long long b){
	long long c;
	while( b>0 ){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	bool czy;
	char cos;
	int t,i,j;
	long long licznik,mianownik,l1,l2,nwd;
	Pot[1] = 1;
	for(i=2; i<=49; i++) Pot[i] = Pot[i-1]*2;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		czy = false;
		scanf("%lld%c%lld", &l1,&cos,&l2);
		nwd = NWD( l2,l1 );
		l1 /= nwd;
		l2 /= nwd;
		for(j=0; j<43; j++){
			if( Pot[j] == l2 ) czy = true;
		}
		j = 1;
		licznik = 1;
		mianownik = 2;
		while( l1*mianownik < l2*licznik ){
			j++;
			mianownik *= 2;
		}
		if( czy==true ){
			printf("Case #%d: %d\n", i+1,j);
		}
		else{
			printf("Case #%d: impossible\n", i+1);
		}
	}
	return 0;
}
