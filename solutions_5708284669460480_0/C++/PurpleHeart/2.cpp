#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int T, K, L, S;
char KEY[20], TAR[20];
string now;
int maxBanana, totalBanana, totalCount;

int count(){
	int ret = 0;
	for(int i = 0; i <= S - L; ++i){
		bool ok = true;
		for(int j = 0; j < L; ++j)
			if(now[i + j] != TAR[j]){
				ok = false;
				break;
			}
		ret += ok;
	}
	return ret;
}

int gao(int dep){
	if(dep == S){
		totalCount++;
		int cntBanana = count();
		maxBanana = max(maxBanana, cntBanana);
		totalBanana += cntBanana;
		return 0;
	}
	for(int i = 0; i < K; ++i){
		string tmp = now;
		now = now + KEY[i];
		gao(dep + 1);
		now = tmp;
	}
	return 0;
}

int main(){
	scanf("%d", &T);
	for(int xx = 1; xx <= T; ++xx){
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", KEY);
		scanf("%s", TAR);
		now = "";
		maxBanana = 0;
		totalBanana = 0;
		totalCount = 0;
		gao(0);
		printf("Case #%d: %.8lf\n", xx, maxBanana - (totalBanana * 1.0 / totalCount));
	}
}
