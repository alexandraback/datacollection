#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int MAXN = 1005;

int N, cases;
bool Gr[MAXN][MAXN], flag[MAXN];
int lk[MAXN];
int zz1, zz2;
map<string, int> fw, sw;
char xxx[50], yyy[50];

bool h(int x){
	for(int i = 0; i < zz2; ++i)
		if(Gr[x][i] && !flag[i]) {
			flag[i] = true;
			if(lk[i] == -1 || h(lk[i])){
				lk[i] = x;
				return true;
			}
		}
	return false;
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		zz1 = 0, zz2 = 0;
		memset(Gr, 0, sizeof(Gr));
		fw.clear(), sw.clear();
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%s%s", xxx, yyy);
			string x(xxx), y(yyy);
			if(!fw.count(x)){
				fw[x] = zz1;
				zz1++;
			}
			if(!sw.count(y)){
				sw[y] = zz2;
				zz2++;
			}
			Gr[fw[x]][sw[y]] = true;
		}

		memset(lk, 255, sizeof(lk));
		int ans = zz1 + zz2;
		for(int i = 0; i < zz1; ++i) {
			memset(flag, false, sizeof(flag));
			if(h(i)) ans--;
		}
		printf("Case #%d: %d\n", xx, max(N - ans, 0));
	}
}
