#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int T,C,l,f[101][2];
	char p[101];
	for (scanf("%d", &T), C = 1; C <= T; C++){
		printf("Case #%d: ", C);
		memset(p, 0, sizeof p);
		scanf("%s", p);
		l = strlen(p);
		f[0][0] = f[0][1] = 0;
		for (int i = 1; i <= l; i++){
			if (p[i-1] == '-'){
				f[i][0] = f[i-1][0];
				f[i][1] = f[i-1][0]+1;
			} else {
				f[i][0] = f[i-1][1]+1;
				f[i][1] = f[i-1][1];
			}
		}
		printf("%d\n", f[l][1]);
	}
	return 0;
}