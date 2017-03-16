#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int mark[1010];
int as[1010][2];

pair<int, int> lvl1[1010], lvl2[1010];

int main(){
	int casos, caso = 0;
	scanf("%d", &casos);
	
	int a, b;
	while(casos--){ ++caso;
		memset(mark, 0, sizeof(mark));
		int n; scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			lvl1[i] = make_pair(a, i);
			lvl2[i] = make_pair(b, i);
			as[i][0] = a; as[i][1] = b;
		}
		int i = 0, j = 0;
		sort(lvl1, lvl1 + n);
		sort(lvl2, lvl2 + n);
		int tot = 0, jogadas = 0;;
		for(; j < n; ){
			if(lvl2[j].first <= tot){
				tot += mark[lvl2[j].second]==0 ? 2 : 1;
				mark[lvl2[j].second] = 2;
				++j;
				++jogadas;
			//	printf("lvl2 %d\n", lvl2[j].second);
			} else {
				bool ok = false;
				int maior = 0, ii = 0;
				for(int i = 0; i < n; ++i){
					if(lvl1[i].first <= tot) {
						if(as[lvl1[i].second][1] > maior && mark[lvl1[i].second] == 0){
							ii = lvl1[i].second;
							maior = as[lvl1[i].second][1];
							ok = true;
						}
					} else {
						break;
					}
				}
				if(ok){
			//		printf("lvl1 %d\n", ii);
					mark[ii] = 1;
					++jogadas;
					++tot;
				} else {
					break;
				}
				
			
			}
			
		}
		printf("Case #%d: ", caso);
		if( j != n){
			printf("Too Bad\n");
		} else {
			printf("%d\n", jogadas);
		}
		
	}
	
	return 0;
}