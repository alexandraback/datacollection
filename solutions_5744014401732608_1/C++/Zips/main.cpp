#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    int B, M;
    int t;

    for(int i=0; i<T; i++){
        printf("Case #%d: ", i+1);

        scanf("%d %d", &B, &M);

        t=M;

        if( (1<<(B-2)) < M ) printf("IMPOSSIBLE\n");
        else{
            printf("POSSIBLE\n");
            if( (1<<(B-2)) == M){
				for(int j=0; j<B; j++){
					for(int k=0; k<=j; k++){
						printf("0");
					}
					for(int k=0; k<B-j-1; k++){
						printf("1");
					}
					printf("\n");
				}
            }
            else{
				for(int j=0; j<B; j++){
					for(int k=0; k<=j; k++){
						printf("0");
					}
					for(int k=0; k<B-j-2; k++){
						printf("1");
					}
					if(j==0) printf("0");
					else if(j!=(B-1)){
                        printf("%d", t%2);
                        t/=2;
					}
					printf("\n");
				}
            }
        }
    }

	return 0;
}
