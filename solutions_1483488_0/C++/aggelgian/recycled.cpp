#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
#include<iostream>
#define BSIZE 1<<15

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

long readLong () {
	long d = 0L, x = 0L;
	char c;

	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}

int chk (std::string x, std::string y, int len, int n) {

	int i;
	
	for(i=0; i<n; i++) {
		if (x[i] != y[len-(n-i)])
			return 0;
	}
	
	for(i=n; i<len; i++) {
		if (x[i] != y[i-n])
			return 0;
	}

	return 1;
}

int isRecycled (long x, long y) {

	int i, lenX, lenY;
	std::string sX, sY;
	std::stringstream strX, strY;
	
	strX << x;
	sX = strX.str();
	lenX = sX.length();
	
	strY << y;
	sY = strY.str();
	lenY = sY.length();
		
	if (lenX == lenY) {

		for(i=1; i<lenX; i++)
			if (chk(sX, sY, lenX, i) == 1)
				return 1;
	}
	
	return 0;
}


int main () {

	long T, A, B, ii, num, i, j;
	
	T = readLong();
	
	for(ii=1; ii<=T; ii++) {
	
		A = readLong();
		B = readLong();	
		num = 0;
		
		for(i=A; i<B; i++)
			for(j=i+1; j<=B; j++) {
			
				if (isRecycled(i, j))
					num++;
			}
		
		printf("Case #%ld: %ld\n", ii, num);
		
	}
	

	return 0;
}
