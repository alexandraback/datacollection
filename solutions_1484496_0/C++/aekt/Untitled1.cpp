#include <cstdio>
#define max 2000001

int cc, n, s[20], q[max], f[max], t, s1, s2;
bool v[max];

void re(int i){
	if (i){
		re(f[i]);
		printf("%d", i - f[i]);
		if (i == s1) printf("\n");
		else printf(" ");
	}
}

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &cc);
	for(int ca = 1; ca <= cc; ca++){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &s[i]);
		}
		for(int i = 0; i < max; i++){
			f[i] = 0;
			v[i] = false;
		}
		t = 1;
		q[0] = 0;
		v[0] = true;
		for(int i = 0; i < n; i++){
			for(int j = 0, k = t; j < k; j++){
				if (v[q[j]+s[i]]){
					s1 = q[j] + s[i];
					s2 = q[j];
					break;
				}else{
					f[q[j]+s[i]] = q[j];
					v[q[j]+s[i]] = true;
					q[t++] = q[j] + s[i];
				}
			}
		}
		printf("Case #%d:\n", ca);
		re(s1);
		re(s2);
		printf("%d\n", s1 - s2);
	}
	scanf("\n");
	return 0;
}
