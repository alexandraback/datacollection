#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int field[110][110];
int maxi[2][110];

int main(){
	int tc, tcn;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		printf("Case #%d: ", tc+1);
		int w, h;
		scanf("%d %d", &h, &w);
		memset(maxi, 0, sizeof(maxi));
		for(int j=0; j<h; ++j){
			for(int i=0; i<w; ++i){
				scanf("%d", &field[j][i]);
				maxi[0][j] = max(maxi[0][j], field[j][i]);
				maxi[1][i] = max(maxi[1][i], field[j][i]);
			}
		}
		bool works = true;
		for(int j=0; j<h; ++j)
			for(int i=0; i<w; ++i)
				if(field[j][i] < maxi[0][j] && field[j][i] < maxi[1][i])
					works = false;
		if(works)
			puts("YES");
		else
			puts("NO");
	}
}
