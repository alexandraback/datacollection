#include <stdio.h>

void fail(){
	puts("Impossible");
}

void solve1(int r, int c){
	printf("c");
	for(int i = 1; i < c; i++)
		printf("*");
	puts("");
	for(int i = 1; i < r; i++){
		for(int j = 0; j < c; j++)
			printf("*");
		puts("");
	}
}
void solve1n(int c, int m){
	printf("c");
	for(int i = 0; i < m - 1; i++)
		printf(".");
	for(int i = 0; i < c - m; i++)
		printf("*");
	puts("");
}
void solven1(int r, int m){
	puts("c");
	for(int i = 0; i < m - 1; i++)
		puts(".");
	for(int i = 0; i < r - m; i++)
		puts("*");
}

void solve2(){
	fail();
}
void solve2n(int c, int m){
	if(m & 1){
		fail();
		return;
	}
	m /= 2;
	printf("c");
	for(int i = 0; i < m - 1; i++)
		printf(".");
	for(int i = 0; i < c - m; i++)
		printf("*");
	puts("");
	for(int i = 0; i < m; i++)
		printf(".");
	for(int i = 0; i < c - m; i++)
		printf("*");
	puts("");
}
void solven2(int r, int m){
	if(m & 1){
		fail();
		return;
	}
	m /= 2;
	puts("c.");
	for(int i = 0; i < m - 1; i++)
		puts("..");
	for(int i = 0; i < r - m; i++)
		puts("**");
}

void solve(int r, int c, int m){
	if(m == 3 || m == 5 || m == 7){	// O RLY?
		fail();
		return;
	}
	if(m - 3 * (m & 1) <= c * 2){
		bool shit = m & 1;
		if(shit)
			m -= 3;
		m /= 2;
		printf("c");
		for(int i = 1; i < m; i++)
			printf(".");
		for(int i = 0; i < c - m; i++)
			printf("*");
		puts("");
		for(int i = 0; i < m; i++)
			printf(".");
		for(int i = 0; i < c - m; i++)
			printf("*");
		puts("");
		if(shit){
			printf("...");
			for(int i = 3; i < c; i++)
				printf("*");
			puts("");
			r--;
		}
		for(int i = 2; i < r; i++){
			for(int i = 0; i < c; i++)
				printf("*");
			puts("");
		}
		return;
	}
	bool shit = m % c == 1;
	if(shit)
		m -= 2;
	printf("c");
	for(int i = 1; i < c; i++)
		printf(".");
	puts("");
	m -= c;
	r--;
	while(m >= c){
		for(int i = 0; i < c; i++)
			printf(".");
		puts("");
		m -= c;
		r--;
	}
	if(r){
		for(int i = 0; i < m; i++)
			printf(".");
		for(int i = 0; i < c - m; i++)
			printf("*");
		puts("");
		r--;
	}
	if(shit){
		printf("..");
		for(int i = 2; i < c; i++)
			printf("*");
		puts("");
		r--;
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			printf("*");
		puts("");
	}
}

int main(){
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; test++){
		printf("Case #%d:\n", test);
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		m = r * c - m;	//	sorry
		if(m == 1){
			solve1(r, c);
			continue;
		}
		if(r == 1){
			solve1n(c, m);
			continue;
		}
		if(c == 1){
			solven1(r, m);
			continue;
		}
		if(m == 2){
			solve2();
			continue;
		}
		if(r == 2){
			solve2n(c, m);
			continue;
		}
		if(c == 2){
			solven2(r, m);
			continue;
		}
		solve(r, c, m);
	}
}
