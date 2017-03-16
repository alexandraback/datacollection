#include <stdio.h>
#include <map>
using namespace std;

int T;

int cando(int p, int t, int surprise){
	for(int a=0;a<=10;a++){
		for(int b=a; b<=a+1+surprise && b<=10;b++){
			for(int c=b; c<=a+1+surprise && c<=10;c++){
				if(a+b+c == t && c>=p)return 1;
			}
		}
	}
	return 0;
}

void doFall(int fall){
	printf("Case #%d: ", fall);
	int N, S, p;
	int t;
	scanf("%d %d %d",&N,  &S, &p);
	int svar = 0;
	for(int i=0; i<N; i++){
		scanf("%d", &t);
		if(cando(p, t, 0)){
			svar++;
		} else if(S && cando(p, t, 1)){
			S--;
			svar++;
		}
	}
	printf("%d\n", svar);
}

int main(){
	scanf("%d", &T);
	for(int fall=1;fall<=T;fall++){
		doFall(fall);
	}	
}