#include <cstdio>

const int MAX = 10020;

int cap, heal, n, val[MAX];

void input(){
	scanf("%d%d%d", &cap, &heal, &n);

	int i;
	for(i=0; i<n; i++)
		scanf("%d", &val[i]);
}

void solve(){
	long long res = 0;

	int i, j, remain=cap;
	for(i=0; i<n;){
		for(j=i+1; j<n && j<=i+(cap/heal); j++){
			if(val[j] >= val[i]){
				int used = remain-(cap-heal*(j-i));
				if(used < 0) used = 0;
				
				res += (long long)used*val[i];
				remain = remain-used+heal*(j-i);
				i = j;
				break;
			}
		}

		if(j >= n || j > i+(cap/heal)){
			res += (long long)remain*val[i];
			i++;
			remain = heal;
		}
	}

	printf("%lld\n", res);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cc;

	scanf("%d", &cc);
	for(t=1; t<=cc; t++){
		printf("Case #%d: ", t);

		input();
		solve();
	}

	return 0;
}