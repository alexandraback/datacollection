#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int cases;
long long A, B;
vector< pair<long long, int> > gao;

bool check(long long g){
	long long gg = 0, tg = g;
	while(tg != 0){
		gg = gg * 10 + tg % 10;
		tg /= 10;
	}
	if(gg == g) return true;
	else return false;
}

int main(){
	int cnt = 0;
	for(int i = 1; i <= 10000000; ++i){
		long long sq = i * 1LL * i;
		if(check(i) && check(sq)){
			cnt++;
			gao.push_back(make_pair(sq, cnt));
		}
	}
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%I64d%I64d", &A, &B);
		int l = (*lower_bound(gao.begin(), gao.end(), make_pair(A, 0))).second;
		int r = (*lower_bound(gao.begin(), gao.end(), make_pair(B + 1, 0))).second - 1;
		printf("Case #%d: %d\n", xx, r - l + 1);
	}
}
