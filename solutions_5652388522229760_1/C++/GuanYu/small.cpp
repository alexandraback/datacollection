#include <cstdio>
typedef long long int llint;
using namespace std;

// Main
int main(void)
{
	int tc, cs, cnt;
	llint n, i, tmp;
	bool used[10];

	// Testcase
	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs++){
		printf("Case #%d: ", cs);
		scanf("%lld", &n);
		if(!n) printf("INSOMNIA\n");
		else{
			cnt = 0;
			for(i = 0; i < 10; i++) used[i] = false;
			for(i = 1; cnt < 10; i++){
				tmp = i*n;
				while(tmp){
					if(!used[tmp%10]){
						used[tmp%10] = true;
						cnt ++;
					}
					tmp /= 10;
				}
			}
			printf("%lld\n", --i*n);
		}
	}
	return 0;
}
