#include <cstdio>

int m, n, k, r;
int ls[15];

bool pos(int a, int b, int c){
	int sc[] = {a, b, c};
	bool reach[400];
	for(int i = 0; i < 300; i++) reach[i] = false;
	reach[1] = true;
	for(int i = 0; i < 3; i++){
		for(int j = 150; j > 0; j--){
			if(reach[j]){
				reach[j*sc[i]] = true;
			}
		}
	}
	bool ret = true;
	for(int i = 0; i < k; i++){
		if(!reach[ls[i]]){
			ret = false;
			break;
		}
	}
	return ret;
}

int main(){
	int fuc;
	scanf("%d", &fuc);
	printf("Case #1:\n");
	scanf("%d %d %d %d", &r, &n, &m, &k);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < k; j++){
			scanf("%d", &ls[j]);
		}
		bool done = false;
		for(int j = 2; j <= m; j++){
			for(int k = 2; k <= m; k++){
				for(int l = 2; l <= m; l++){
					if(pos(j,k,l)){
						printf("%d%d%d\n", j,k,l);
						done = true;
						break;
					}
				}
				if(done) break;
			}
			if(done) break;
		}
		if(!done) printf("222\n");
	}

	return 0;
}
	
