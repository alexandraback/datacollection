#include <stdio.h>

int T, Smax, C=1;
char syn[2000];
int main(){
	scanf("%d", &T);
	while(T--){
		int ans = 0, stand;
		scanf("%d %s", &Smax, syn);
		stand = syn[0]-'0';
		for(int i=1; i<=Smax; ++i){
			if(stand + ans < i) ans++;
			stand += syn[i]-'0';
		}

		printf("Case #%d: %d\n", C++, ans);
	}
	return 0;
}
