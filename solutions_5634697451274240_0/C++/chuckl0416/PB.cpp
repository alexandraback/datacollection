#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int St[120];
int tmp[120];
char inputS[120];
int i, x, L, Ans;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		scanf("%s", inputS);
		L = strlen(inputS);
		for (i=0; i<L; i++){
			if (inputS[i]=='+') St[i] = 1;
			if (inputS[i]=='-') St[i] = 0;
		}
		Ans = 0;
		while(L && St[L-1]) L--;
		
		while(L){
			x = 0;
			if (St[0]){
				while(x<L && St[x]) x++;
				for (i=0; i<x; i++) St[i] = 0;
				Ans++;
			}
			
			for (i=0; i<L; i++) tmp[i] = St[L-i-1]^1;
			for (i=0; i<L; i++) St[i] = tmp[i];
			Ans++;
			while(L && St[L-1]) L--;
		}
		
		printf("%d\n", Ans);
	}
	
	return 0;
}


