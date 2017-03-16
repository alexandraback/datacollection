#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int in[300];

int n;

int mark[5100010];

int main() {
	int casos; scanf("%d", &casos);
	int caso = 0;
	while(casos--){
		memset(mark, 0, sizeof(mark));
		int sum = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &in[i]);
		}
		printf("Case #%d:\n", ++caso);
		int at = 1, ate = (1<<n); 
		while(at < ate){
			sum = 0;
			for(int i = 0; i < n; ++i){
				if(at&(1<<i))
					sum += in[i];
			}
			
			if(mark[sum] != 0 ){
				bool fi = 0;
				for(int i = 0; i < n; ++i){
					if(mark[sum]&(1<<i)){
						if(fi) printf(" ");
						else fi = true;
						printf("%d", in[i]);
					}
				}
				printf("\n"); fi = false;
				for(int i = 0; i < n; ++i){
					if(at&(1<<i)){
						if(fi) printf(" ");
						else fi = true;
						printf("%d", in[i]);
					}
				}
				printf("\n");
				goto ok;
			} else {
				mark[sum] = at;
			}
		
			++at;
		}
		
		printf("Impossible\n");
		ok:;		
	}
	
	return 0;
}
