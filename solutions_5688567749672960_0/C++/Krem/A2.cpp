#include<cstdio>
#include<cstring>

int tab[1000010];

int main() {
	memset(tab,60,sizeof(tab));
	tab[1] = 1;
	for(int i = 2; i <= 1e6; i++) {
		int x = 0;
		for(int j = i; j > 0; j /= 10)
			x = x*10 + j%10;
		bool t = 1;
		int xx = x, ii = i;
		while(ii) {
			if(!xx) {t = 0;break;}
			ii/=10; xx/=10;
		}
		if(tab[x] < tab[i-1] && t)
			tab[i] = tab[x]+1;
		else
			tab[i] = tab[i-1]+1;
	}
	int t; scanf("%d", &t);
	for(int _ = 0; _ < t; _++) {
		int n; scanf("%d", &n);
		printf("Case #%d: %d\n", _+1, tab[n]);
	}
	return 0;
}
