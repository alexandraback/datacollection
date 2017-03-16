#include <stdio.h>
#include <stdlib.h>

long long unsigned h[]  = {2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 , 2048 , 4096 , 8192 , 16384 , 32768 , 65536 , 131072 , 262144 , 524288 , 1048576 , 2097152 , 4194304 , 8388608 , 16777216 , 33554432 , 67108864 , 134217728 , 268435456 , 536870912 , 1073741824 , 2147483648 , 4294967296 , 8589934592 , 17179869184 , 34359738368 , 68719476736 , 137438953472 , 274877906944 , 549755813888 , 1099511627776};


long long unsigned gcd(long long unsigned a,long long unsigned b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

long long unsigned getint(){
	long long unsigned n = 0;
	int c;
	while((c=getchar_unlocked()) < '0' || c > '9');
	while(c >= '0' && c <= '9'){
		n = n*10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int main(int argc, char const *argv[]){
	long long unsigned P,Q,T,hcf,value;
	double ans;
	int i,j,count;
	T = getint();
	for(i=1;i<=T;i++){
		P = getint();
		Q = getint();
		hcf = gcd(Q,P);
		P = P/hcf;
		Q = Q/hcf;
		for(j=0;j<40;j++){
			if(Q == h[j]){
				break;
			}
		}
		if(j == 40){
			printf("Case #%d: impossible\n",i);
		}
		else{
		value = Q;
		count = 0;
		while(1){
			value = value/2;
			count += 1;
			if(P >= value){
				break;
			}
		}
		printf("Case #%d: %d\n",i,count);
	}
	}
	return 0;
}
