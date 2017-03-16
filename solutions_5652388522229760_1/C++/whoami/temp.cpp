#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
	int testt;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testt);
	for (int test = 1; test <= testt; test++){
		long long n;
		printf("Case #%d: ", test);
		scanf("%lld", &n);
		bool check[10] = { 0, };
		char digit[20] = { 0, };
		long long temp = 0;
		bool flag = 0;
		for (int i = 0; i <= 100; i++){
			temp += n;
			sprintf(digit, "%lld", temp);
			for (int j = 0; j < strlen(digit); j++){
				check[digit[j] - '0'] = 1;
			}

			int cnt = 0;
			for (int j = 0; j < 10; j++){
				cnt += check[j];
			}
			if (cnt == 10){
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("%lld\n", temp);
		else
			printf("INSOMNIA\n");
	}
	return 0;
}
