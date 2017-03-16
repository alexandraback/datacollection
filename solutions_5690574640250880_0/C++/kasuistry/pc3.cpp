
#include <cstdio>

int main(){
	
	int testcase; scanf("%d", &testcase);
	int r, c, m;
	int s[51][51];

	for(int t=1; t<=testcase; ++t){
		
		int found;

		scanf("%d%d%d", &r, &c, &m);

		printf("Case #%d:\n", t);

		if(m == r*c-1){
			for(int i=1; i<=r; ++i){
				for(int j=1; j<=c; ++j){
					if(i == r && j == c){
						printf("c");
					}else{
						printf("*");
					}
				}
				printf("\n");
			}
		}else if(r == 1 || c == 1){
			for(int i=1; i<=r; ++i){
				for(int j=1; j<=c; ++j){
					if(i == r && j == c){
						printf("c");
					}else if(m > 0){
						printf("*");
						-- m;
					}else{
						printf(".");
					}
				}
				printf("\n");
			}
		}else if(r == 2 || c == 2){
			if(m%2 != 0 || m > r*c-4){
				printf("Impossible\n");
			}else{
				for(int i=1; i<=r; ++i){
					for(int j=1; j<=c; ++j){
						if(i == r && j == c){
							printf("c");
						}else if((j <= m/2 && r == 2) || (i <= m/2 && c == 2)){
							printf("*");
						}else{
							printf(".");
						}
					}
					printf("\n");
				}
			}
		}else{
			found = 0;
			for(int i=0; i<=r-2 && !found; ++i){
				for(int j=0; j<=c-2 && !found; ++j){
					int s = i*c+j*r-i*j;
					if(m>=s && m-s <= (r-2-i)*(c-2-j)){
						found = 1;
						for(int u=1; u<=r; ++u){
							for(int v=1; v<=c; ++v){
								if(u <= i || v <= j){
									printf("*");
								}else if(u <= r-2 && v <= c-2){
									if(s < m){
										++s; printf("*");
									}else{
										printf(".");
									}
								}else if(u == r && v == c){
									printf("c");
								}else{
									printf(".");
								}
							}
							printf("\n");
						}
					}
				}
			}
			if(!found){
				printf("Impossible\n");
			}
		}
	}
	return 0;
}
