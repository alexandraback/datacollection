#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d\n", &n);
	for(int t = 1; t <= n; t++){
		printf("Case #%d: ", t);
		int l;
		scanf("%d\n", &l);
		char a[20][25];
		char b[20][25];
		for(int i = 0; i < l; i++){
			scanf("%s %s\n", a[i], b[i]);
		}
		int m = 0;
		for(int i = 0; i < (1 << l); i++){
			bool ac = false, bc = false;
			for(int j = 0; j < l; j++){
				if(!((1 << j) & i)) continue;
				ac = false, bc = false;
				for(int k = 0; k < l; k++){
					if((1<<k) & i) continue;
					if(!strcmp(a[j],a[k])) ac = true;
					if(!strcmp(b[j],b[k])) bc = true;
				}
				if(!(ac && bc)) break;
			}
			if(ac && bc){
				int count = 0;
				for(int j = 1; j < 1<<l; j <<= 1){
					if(j & i) count++;
				}
				m = max(count, m);
			}
		}
		printf("%d\n",m);
	}
	return 0;
}

