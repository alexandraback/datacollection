#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int N;
char mem[40][100];

int is_palyn(unsigned long long num){
	char str_num[32];
	snprintf(str_num,sizeof(str_num),"%llu",num);
	int n = strlen(str_num) - 1,i = 0;
	while(i < n){
		if(str_num[i] != str_num[n])
			return 0;
		i++,n--;
	}
	return 1;
}

void calculate_guys(){
	N = 0;
	unsigned long long i = 1,k;
	while(N < 40){
		if(is_palyn(i)){
			k = i*i;
			if(is_palyn(k)){
				snprintf(mem[N],sizeof(mem[N]),"%llu",k);
				N++;
			}
		}
		++i;
	}
}

int count_range(unsigned long long min, unsigned long long max){
	int i,total = 0;
	unsigned long long aux;
	for(i = 0;i < N;++i){
		aux = atoll(mem[i]);
		if(aux < min)
			continue;
		if(aux > max)
			break;
		total++;
	}
	return total;
}

int main(){
	int i,T;
	unsigned long long min,max;
	calculate_guys();
	scanf("%d\n",&T);
	for(i = 1;i <= T;++i){
		scanf("%llu %llu\n",&min,&max);
		printf("Case #%d: %d\n",i,count_range(min,max));
	}
	return 0;
}

