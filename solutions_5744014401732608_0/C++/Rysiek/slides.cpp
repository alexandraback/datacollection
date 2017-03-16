#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<inttypes.h>

int b;
int64_t m;

void print(int64_t v) {
	for(int i=b-1;i>=0;--i) {
		putchar( ((v>>i)&1)?'1':'0');
	}
	putchar('\n');
}


int main(int argc, char** argv) {
	int tests;
	scanf("%d", &tests);
	
	for(int t=1;t<=tests;++t) {
		scanf("%d %"PRId64, &b, &m);
		int64_t max=1<<(b-2);
		
		printf("Case #%d: ", t);
//		printf("b=%d m=%"PRId64" ", b, m);
		
		if(m>max) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		if(m==1) {	// gdy jest wymagany 1
			print(1);
			for(int i=0;i<b-1;++i) print(0);
			continue;
		}
		if(m==2) {
			print(3);
			for(int i=0;i<b-3;++i) print(0);
			print(1);
			print(0);
			continue;
		}
		int g=2;
		while((((int64_t)1)<<g)<m) {
			++g;
		}
//		printf("b=%d, g=%d, m=%"PRId64"\n",b,g, m);
		print( (((int64_t)1)<<(g+1))-1);
		for(int i=g+2;i<b;++i) print(0);
		
		m-=((int64_t)1)<<(g-1);
//		printf(" nm=%"PRId64"\n",m);
		if(m<((((int64_t)1))<<(g-1))) {
			int64_t res=0;
			for(int i=b;i>=0;--i) {
				int64_t s;
				if(i==0 || i==1) s=1;
				else s=((int64_t)1)<<(i-1);
				if(s<=m) {
					res+=(1<<i);
					m-=s;
					if(m==0) break;
				}
			}
			--g;
			print(res);
//			printf(" Done %"PRId64"\n", m);
		}
		
		for(int i=g-1;i>=0;--i) {
			print( (((int64_t)1)<<(i+1))-1);
		}
		print(0);
	}
	
	return 0;
}