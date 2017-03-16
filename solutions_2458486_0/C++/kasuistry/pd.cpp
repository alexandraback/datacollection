
#include <cstdio>
#include <cstring>

int key[201];
int f[200];
int stack[200];
int open[200], ptr[200];
int box[200][400];
char hash[1024*1024];

int sch(int lev, int lmt, int encode){
	if(lev == lmt){
		return 1;
	}
	for(int i=0; i<lmt; ++i){
		if(!f[i] && key[open[i]] && !hash[encode|(1u << i)]){
			f[i] = 1; key[open[i]] --;
			stack[lev] = i;
			for(int j=0; j<ptr[i]; ++j){
				key[box[i][j]] ++;
			}
			if(sch(lev+1, lmt, encode|(1u<<i))) return 1;
			hash[encode | (1u << i)] = 1;
			for(int j=0; j<ptr[i]; ++j){
				key[box[i][j]] --;
			}
			f[i] = 0; key[open[i]] ++;
		}
	}
	return 0;
}

int main(){
	
	int t; scanf("%d", &t);
	int k, n;

	for(int testcase=1; testcase<=t; ++testcase){
		scanf("%d %d", &k, &n);
		for(int i=0; i<201; ++i){
			key[i] = 0;
		}
		for(int i=0; i<k; ++i){
			int tmp; scanf("%d", &tmp); key[tmp]++;
		}
		for(int i=0; i<n; ++i){
			f[i] = 0;
			scanf("%d %d", &open[i], &ptr[i]);
			for(int j=0; j<ptr[i]; ++j){
				scanf("%d", &box[i][j]);
			}
		}
		memset(hash, 0, sizeof(hash));
		printf("Case #%d:", testcase);
		/*
		printf("%d %d\n", k, n);
		for(int i=0; i<n; ++i){
			printf("%d: ", open[i]);
			for(int j=0; j<ptr[i]; ++j){
				printf("%d ", box[i][j]);
			}
			printf("\n");
		}*/
		
		if(sch(0, n, 0)){
			for(int i=0; i<n; ++i){
				printf(" %d", stack[i]+1);
			}
			printf("\n");
		}else{
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}
