#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int s[512];
int m[512];
int N;

int rek(int sum, int index, int empty){
	if(index == N){
		return !sum && empty;
	}
	for(int k=0;k<=2;k++){
		m[index] = k;
		int delta = 0;
		if(k==1)delta = s[index];
		if(k==2)delta = -s[index];
		
		int svar = rek(sum+delta, index+1, empty + k);
		if(svar)return svar;
	}
}

void run(int fall){
	printf("Case #%d:", fall);
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d", &s[i]);
	}
	int svar = rek(0, 0, 0);
	if(svar){
		printf("\n");
		for(int j=1;j<=2;j++){
			int first = 1;
			for(int i=0;i<N;i++){
				if(m[i] == j){
					if(!first)printf(" ");
					first = 0;
					printf("%d", s[i]);
				}
			}
			printf("\n");
		}
	} else {
		printf("Impossible\n");
	}
}


int main(){
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		run(i+1);
	}	
}