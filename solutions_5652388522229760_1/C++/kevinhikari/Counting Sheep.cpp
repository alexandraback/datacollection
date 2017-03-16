#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
long long n, cnt, a, b, t;
bool flag[12];
int main() {
	scanf("%lld",&t);
	for (int q = 1; q <= t; q++) {
		scanf("%lld", &n);
		bool selesai = false;
		memset(flag,false,sizeof(flag));
		cnt = 0;
		printf("Case #%d: ",q);
		for (int i = 1; i <= 100; i++) {
			long long tmp = n;
			tmp = tmp * i;
			while (tmp > 0) {
				if (flag[tmp % 10] == false) {
					flag[tmp % 10] = true;
					cnt++;
				}
				tmp /= 10;
			}
			if (cnt == 10) {
				selesai = true;
				tmp = n*i;
				printf("%lld\n", tmp);
				break;
			}
		}
		if (!selesai) printf("INSOMNIA\n");
	}
}
