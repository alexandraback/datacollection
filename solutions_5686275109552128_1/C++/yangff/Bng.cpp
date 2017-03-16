#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));
	freopen("B.in", "w", stdout);
	printf("100\n");
	for (int i = 0; i < 100; i++){
		printf("%d\n", 1000);
		for (int j = 0; j < 1000; j++){
			printf("1 ");
		}
		puts("");
	}
}