#include <cstdio>
#include <algorithm>

const int MAX=1000020;

int size, n, data[MAX];

void input(){
	scanf("%d%d", &size, &n);

	int i;
	for(i=0; i<n; i++)
		scanf("%d", &data[i]);
}

int res;

void solve(){
	res = n;

	if(size != 1){
		std::sort(data, data+n);

		int i, cnt=0;
		for(i=0; i<n; i++){
			while(size <= data[i]){
				size += size-1;
				cnt++;
			}

			if(res > n-1-i+cnt)
				res = n-1-i+cnt;

			size += data[i];
		}
	}
	
	printf("%d\n", res);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cc, t;
	scanf("%d", &cc);
	for(t=1; t<=cc; t++){
		printf("Case #%d: ", t);

		input();

		solve();
	}

	return 0;
}