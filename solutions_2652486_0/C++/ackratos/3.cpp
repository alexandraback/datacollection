#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int K = 10;
int product[K];
int r, n, m, k;
void n1(){
	for(int i = 2; i <= m; i++){
		int ok = true;
		for(int p = 0; p < k; p++){
			if(product[p] != i && product[p] != 1){
				ok = false;
				break;
			}
		}
		if(ok == true){
			printf("%d\n", i);
			return;
		}
	}
}

void n2(){
	for(int i = 2; i <= m; i++){
		for(int j = 2; j <= m; j++){
			int ok = true;
			for(int p = 0; p < k; p++){
				if(product[p] != i && product[p] != j && product[p] != i * j && product[p] != 1){
					ok = false;
					break;
				}
			}
			if(ok == true){
				printf("%d%d\n", i, j);
				return;
			}
		}
	}
}

void n3(){
	for(int i = 2; i <= m; i++){
		for(int j = 2; j <=m; j++){
			for(int x = 2; x <=m; x++){
				int ok = true;
				for(int p = 0; p < k; p++){
					if(product[p] != i && product[p] != j && product[p] != x &&
						product[p] != i * j && product[p] != i * x && product[p] != j * x &&
						product[p] != i * j * x && product[p] != 1){
							ok = false;
							break;
					}
				}
				if(ok == true){
					printf("%d%d%d\n", i, j, x);
					return;
				}
			}
		}
	}
}

int main(){
	int ncase = 1;
	scanf("%d", &ncase);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	printf("Case #1:\n");
	for(int nn = 0; nn < r; nn++){
		for(int i = 0; i < k; i++){
			scanf("%d", &product[i]);
		}
		switch(n){
		case 1:
			n1();
			break;
		case 2:
			n2();
			break;
		case 3:
			n3();
			break;
		}
	}
	return 0;
}