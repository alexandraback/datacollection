
#include <cstdio>

int min(int a, int b){
	if(a < b) return a;
	return b;
}
int main(){
	
	int t; scanf("%d", &t);
	int n, m;
	int s[100][100];
	int a[100];
	int b[100];

	for(int testcase=1; testcase<=t; ++testcase){
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				scanf("%d ", &s[i][j]);
			}
		}
		for(int i=0; i<n; ++i){
			a[i] = s[i][0];
			for(int j=1; j<m; ++j){
				if(s[i][j] > a[i]){
					a[i] = s[i][j];
				}
			}
		}
		for(int j=0; j<m; ++j){
			b[j] = s[0][j];
			for(int i=1; i<n; ++i){
				if(s[i][j] > b[j]){
					b[j] = s[i][j];
				}
			}
		}
		int wit = 0;
		for(int i=0; i<n&&!wit; ++i){
			for(int j=0; j<m&&!wit; ++j){
				if(s[i][j] != min(a[i], b[j])){
					wit = 1;
				}
			}
		}
		printf("Case #%d: ", testcase);
		if(wit){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}
