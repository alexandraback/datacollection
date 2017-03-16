
#include <cstdio>

int minima(int a, int b, int c){
	if(a <= b){
		return (a<=c) ? a : c;
	}else{
		return (b<=c) ? b : c;
	}
}

int maxima(int a, int b, int c){
	if(a <= b){
		return (b<=c) ? c : b;
	}else{
		return (a<=c) ? c : a;
	}
}

int diff(int a, int b, int c){
	return maxima(a,b,c)-minima(a,b,c);
}

int main(){
	
	int testcase; scanf("%d", &testcase);

	for(int t=1; t<=testcase; ++t){
		int n, s, p; scanf("%d %d %d", &n, &s, &p);
		int r;
		int SorN = 0, S = 0, N = 0;
		for(int i=0; i<n; ++i){
			scanf("%d", &r);
			int sf=0, nf=0;
			///{{{
			for(int i=0; i<=10; ++i){
				for(int j=0; j<=10; ++j){
					for(int k=0; k<=10; ++k){
						if(i+j+k == r){
							if(maxima(i,j,k) >= p){
								if(diff(i,j,k) <= 2){
									if(diff(i,j,k) == 2){
										sf = 1;
									}else{
										nf = 1;
									}
								}
							}
						}
					}
				}
			}
			///}}}
			if(sf == 1 && nf == 1){
				SorN ++;
			}else if(sf == 1 && nf == 0){
				S ++;
			}else if(sf == 0 && nf == 1){
				N ++;
			}
		}
		if(s <= S){
			printf("Case #%d: %d\n", t, s+SorN+N);
		}else{
			//if(s <= S+SorN){
				printf("Case #%d: %d\n", t, S+SorN+N);
			/*
			}else{
				printf("%d %d %d IMPOSSIBLE\n", SorN, S, N);
			}*/
		}
	}

	return 0;
}
