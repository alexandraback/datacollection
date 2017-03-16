#include <cstdio>
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t;
	long long n;
	bool visited[15];
	scanf("%d", &t);
	for(int x = 1;x<=t;++x) {
		printf("Case #%d: ", x);
		scanf("%lld", &n);
		for(int i = 0;i<10;++i)
			visited[i] = false;
		if(n == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		long long counter = 2;
		long long origin = n;
		while(true) {
			bool flag = true;
			for(int i = 0;i<10;++i) {
				if(visited[i] == false)
					flag = false;
			}
			if(flag)
				break;
			long long temp = n;
			while(temp > 0) {
				visited[temp % 10] = true;
				temp /= 10;
			}
			n = origin * counter;
			++counter;
		}
		printf("%lld\n", origin * (counter - 2));
	}
	return 0;
}
