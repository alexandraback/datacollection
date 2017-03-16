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

bool Porownaj(long long l1,long long l2,long long p,long long q){
	long long nwd;
	if( l2 > q) nwd = NWD(l2,q);
	else nwd = NWD(q,l2);
	q /= nwd;
	l2 /= nwd;
	if( l1*q < l2*p ) return true;
	return false;
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
		while( Porownaj(l1,l2,licznik,mianownik) ){
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
