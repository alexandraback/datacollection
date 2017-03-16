#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
 * 1:1
 * 2:i
 * 3:j
 * 4:k
 */

#define N 10005
#define LL long long

char s[N];
int cti[256];
int val[N];
int pa[10][10];
int tab[5][5] = {
	0, 0, 0, 0, 0,
	0, 1, 2, 3, 4,
	0, 2, -1, 4, -3,
	0, 3, -4, -1, 2,
	0, 4, 3, -2, -1
};

int comput(int a, int b){
	if(a < 0){
		if(b < 0){
			return tab[-a][-b];
		}
		else{
			return -tab[-a][b];
		}
	}
	else{
		if(b < 0){
			return -tab[a][-b];
		}
		else{
			return tab[a][b];
		}
	}
}

void init(){
	cti['i'] = 2;
	cti['j'] = 3;
	cti['k'] = 4;
	memset(pa, 0, sizeof(pa));
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			pa[i][tab[i][j] + 5] = j;
		}
	}
}

int sol(int a, int b){
	if(a > 0){
		if(pa[a][b + 5])
			return pa[a][b + 5];
		else
			return -pa[a][-b + 5];
	}
	else{
		if(pa[-a][b + 5])
			return -pa[-a][b + 5];
		else
			return pa[-a][-b + 5];
	}
}

int pow(int a, LL b){
	int ans = 1;
	for(LL i = 0; i < b; i++){
		ans = comput(ans, a);
	}
	return ans;
}
int main(){
	init();
	int l, t;
	int p[10];//+5
	bool f[10];//+5
	LL x, len;
	scanf("%d", &t);
	for(int id = 1; id <= t; id++){
		scanf("%d%lld", &l, &x);
		len = l * x;
		scanf("%s", s);
		memset(p, -1, sizeof(p));
		memset(f, 0, sizeof(f));
		val[0] = cti[s[0]];
		for(int i = 1; i < l; i++){
			val[i] = comput(val[i - 1], cti[s[i]]);
			//printf("%d %d %d\n", val[i - 1], cti[s[i]], val[i]);
		}
		LL mod = x % 4;
		if(pow(val[l - 1], mod) != -1){
			printf("Case #%d: NO\n", id);
			continue;
		}
		for(int i = 0; i < l; i++){
			if(!f[val[i] + 5]){
				f[val[i] + 5] = true;
				p[val[i] +5] = i;
			}
		}
		int a1 = 1, a2 = 1, a3 = 1;
		bool flag = false;
		for(int i = 0; i < 4 && i < x; i++){
			if(i)
				a1 = comput(a1, val[l - 1]);
			if(a1 == 2){
				a2 = 1;
				for(int j = 0; j < 4 && i + j < x; j++){
					if(j)
						a2 = comput(a2, val[l - 1]);
					int t2 = sol(a2, 3);
					if(f[t2 + 5] && p[t2 + 5] != l - 1){
						flag = true;
						break;
					}
				}
			}
			else{
				int t1 = sol(a1, 2);
			//	printf("hhh\n");
				if(f[t1 + 5] && p[t1 + 5] != l - 1){
			//		printf("%d\n", p[t1 + 5]);
					int t3 = 2;
					for(int k = p[t1 + 5] + 1; k < l; k++){
						t3 = comput(t3, cti[s[k]]);
						if(t3 == 4){
							flag = true;
							break;
						}
					}
					if(flag)
						break;
					a2 = sol(t1, val[l - 1]);
					for(int j = 0; j < 4 && i + j + 1 < x; j++){
						if(j)
							a2 = comput(a2, val[l - 1]);
						if(a2 == 3){
							flag = true;
							break;
						}
						int t2 = sol(a2, 3);
						if(f[t2 + 5] && p[t2 + 5] != l - 1){
							flag = true;
							break;
						}
					}
				}
			}
			if(flag)
				break;
		}
		if(flag){
			printf("Case #%d: YES\n", id);
		}
		else{
			printf("Case #%d: NO\n", id);
		}
	}
	return 0;
}
