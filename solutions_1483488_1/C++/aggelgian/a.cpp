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

long generate (long x, long limit) {

	long num, i, j, len, n, ck;
	std::string sX, s1, s2;
	std::stringstream strX;
	std::string a[10];
	
	n = 0;
	
	for(i=0; i<10; i++)
		a[i] = "";
	
	strX << x;
	sX = strX.str();
	len = sX.length();
	
	for(i=1; i<len; i++) {
		s1 = sX.substr(0, i);
		s2 = sX.substr(i, len-1);
		s2.append(s1);
		
		ck = 0;
		for(j=0; j<=n; j++)
			if ((a[j] == s2) || (s2 == sX) || (atol(s2.data()) <= atol(sX.data())) || (atol(s2.data()) > limit))
				ck = 1;
		
		if (ck == 0) {
			n++;
			a[n] = s2;
		}
		
	}

	return n;
}


int main () {

	long T, A, B, ii, num, i, j;
	
	T = readLong();
	
	for(ii=1; ii<=T; ii++) {
	
		A = readLong();
		B = readLong();	
		num = 0;

		for(i=A; i<B; i++)
			num += generate(i, B);
		
		printf("Case #%ld: %ld\n", ii, num);
		
	}
	
	return 0;
}
