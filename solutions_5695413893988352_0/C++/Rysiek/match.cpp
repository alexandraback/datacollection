#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<inttypes.h>

// Dane wejściowe
char numC[20], numJ[20];
// Długość
int len;
// wynik
uint64_t c, j;

char *toString(uint64_t v) {
	static char buf[20];
	
	buf[19]='\0';
	for(int i=0;i<len;++i) {
		buf[18-i]=(v%10)+'0';
		v/=10;
	}
	return &buf[19-len];
}

// Funkcja testująca, czy dana wartość jest zgodna z zapisem
bool test(uint64_t t, char* d) {
	for(int i=len-1;i>=0;--i) {
		char l=d[i];
		if(l!='?') {
			int v=t%10;
			if((l-'0')!=v) return false;
		}
		
		t/=10;
	}
	return true;
}

// wersja głupia implemntacji - dla poziomu prostego
void solveSimple() {
	int max=1;
	for(int i=0;i<len;++i) max*=10;	// maksymalna liczba
	int bestDist=max;	// najlepszy obecny wynik
	c=max;
	j=max;
	
	// na poziomie prostym po prostu wszystkie opcje sprawdzimy
	// i zwrócimy najlepszą zgodnie z wymaganiami zadania
	for(int a=0;a<max;++a) {
		if(!test(a, numC)) continue;	// pomijamu niezgodne wartości
		for(int b=0;b<max;++b) {
			int dist=abs(a-b);	// dystans
			if(dist>bestDist || !test(b, numJ)) continue;
			
			if(dist<bestDist) {	// spamiętujemy wynik
				c=a;
				j=b;
				bestDist=dist;
			} 
//			else if(dist==bestDist) {	// jeżeli wynik taki sam, to może wartość mniejsza
//				if(a<c) {	// to chyba nie powinno nastąpić, bo wartości są rosnące
//					c=a;
//					j=b;
//				} else if(a==c) {	// jeżeli wynik jest taki sam, 
//					if(b<j) {
//						j=b;
//					}
//					
//				}
//			}
		}
	}
	
}

int main(int argc, char** argv) {
	int tests;
	scanf("%d",&tests);
	
	for(int t=1;t<=tests;++t) {
		scanf("%s %s", numC, numJ);
		len=strlen(numC);
		
		solveSimple();
		
		printf("Case #%d:", t);
		printf(" %s", toString(c));
		printf(" %s\n", toString(j));
	}
}