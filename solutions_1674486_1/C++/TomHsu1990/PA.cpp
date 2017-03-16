#include <stdio.h>
#pragma g++ optimize ("O2")
int table[1010][1010], t, n;
int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		scanf("%d", &n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				table[i][j] = 0;
		for(int i=1;i<=n;++i){
			int num, tmp;
			scanf("%d", &num);
			for(int j=0;j<num;++j){
				scanf("%d", &tmp);
				table[i][tmp] = 1;
			}
		}
		bool find = false;
		for(int k=1;!find && k<=n;++k){
			for(int i=1;!find && i<=n;++i){
				for(int j=1;!find && j<=n;++j){
					if(table[i][k] > 0 && table[k][j] > 0){
						++table[i][j];
					}
					if(table[i][j] >= 2) find = true;
				}
			}
		}
		printf("Case #%d: ", cc);
		if(!find) 	printf("No\n");
		else		printf("Yes\n");
	}
	return 0;
}
