#include <cstdio>
typedef long long LL;

int T, n, m, c;

void Work(){
	scanf("%d %d %d", &n, &m, &c);
	if(c < (n / m) + (n % m != 0))
		{printf(" IMPOSSIBLE\n"); return;}
	
	LL now = 1, ly = 1;
	for(int i = 1; i <= n - 1; i ++){
		if(ly + 1 > m){printf(" %lld", now); now = i + 1; ly = 1;}
		else{now = (now - 1) * n + i + 1; ly++;}
	}
	if(ly + 1 <= m)
		while(ly + 1 <= m){now = (now - 1) * n + 1; ly++;}
	printf(" %lld\n", now);
}

int main(){
	//freopen("d.in", "r", stdin), freopen("d.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		printf("Case #%d:", ++t);
		Work();
	}
	
	return 0;
}