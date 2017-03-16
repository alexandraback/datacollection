#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char A[1000];
int n;


void solve(){
	int l = strlen(A),cons;
	int ans = 0,i,j,k;
	for (i = 0; i < l; i++) {
		cons = 0;
		for (j = i; j < l; j++) {
			if (A[j] != 'a' && A[j] != 'e' && A[j] != 'i' && A[j] != 'o' && A[j] != 'u') {
				cons++;		
				if (cons == n) {	
					ans += (l - j);
					break;
				}
			} else {
				cons = 0;
			}
 
		}

	}
	printf("%d",ans);
}


int main(){
	int i,j,t;
    scanf("%d\n",&t);
    for(i=1;i<=t;i++){
    	scanf("%s%d",A,&n);
        printf("Case #%d: ",i);
        solve();
        printf("\n");
    }
}