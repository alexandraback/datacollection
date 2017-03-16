#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int b;
char graph[60][60];

long long depth(long long *count, int at){
	if(count[at]){
		return count[at];
	}
	long long out = 0;
	for(int i = at + 1; i < b; i++){
		if(graph[at][i] == '1'){
			out += depth(count, i);
		}
	}
	return count[at] = out;
}

int main(){
	int t = 0;
	scanf("%d", &t);
	for(int u = 1; u <= t; u++){
		printf("Case #%d: ", u);
		long long m;
		scanf("%d %lld", &b, &m);
		for(int i = 0; i < 60; i++){
			memset(graph[i], '0', 60);
		}
		int perm = 1 << (b*(b-1)/2);
		for(int i = 0; i < perm; i++){
			for(int j = 0; j < b-1; j++){
				for(int k = j+1; k < b; k++){
					graph[j][k] = (i & (1 << ((b*(b-1)/2)-((b-j)*(b-j-1)/2) + k - j - 1))) ? '1' : '0';
				}
			}
			long long count[55];
			memset(count,0,55);
			count[b-1] = 1;
			if(m == depth(count, 0)){
				printf("POSSIBLE\n");
				for(int j = 0; j < b; j++){
					for(int k = 0; k < b; k++){
						printf("%c",graph[j][k]);
					}
					printf("\n");
				}
				m = 0;
				break;
			}
		}
		if(m){
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

