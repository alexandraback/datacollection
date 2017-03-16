#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool check(int *m){
	for (int i = 0; i < 10; i++)
		if (m[i] == 0) return false;
	return true;
}

int main(){
	int T, N, C, m[10], now, tmp;
	for (scanf("%d", &T), C = 1; C <= T; C++){
		scanf("%d", &N);
		printf("Case #%d: ", C);
		if (N == 0) printf("INSOMNIA\n");
		else{
			memset(m, 0, sizeof m);
			now = tmp = 0;
			while (!check(m)){
				now = now + N;
				tmp = now;
				/*
				printf("%d:", now);
				for (int i = 0; i < 10; i++)
					printf("%d ", m[i]);
				printf("\n");*/
				while (tmp != 0){
					m[tmp%10] = 1;
					tmp/=10;
				}
			}
			printf("%d\n", now);
		}
	}
	return 0;
}