#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<bitset>
using namespace std;

const int MAX_N = 20;

struct Chest{
	int need;
	vector<int>contents;
};
Chest chests[MAX_N];
int N;

typedef vector<int> VI;
typedef map<int,int> Keys;
bitset< 1<<MAX_N > memo;
VI Solve(int set, Keys &keys, int now){
	if(memo[set])	//引数はkeysは計算可能で、nowは到達可能かどうかは関与しない
		return VI();
	memo.set(set);

	if(set == (1<<N)-1){
		VI v;
		v.reserve(N);
		v.push_back(now);
		return v;
	}
	// 辞書順に舐めていく
	for(int i=0; i<N; ++i){
		if(set&(1<<i))
			continue;
		if(keys[chests[i].need]>0){
			--keys[chests[i].need];
			for(int x : chests[i].contents){
				++keys[x];
			}
			VI v = Solve(set|(1<<i), keys, i);
			if(!v.empty()){
				if(set!=0)
					v.push_back(now);
				return v;
			}
			//参照で受け取っているのでもとに戻す
			for(int x : chests[i].contents){
				--keys[x];
			}
			++keys[chests[i].need];
		}
	}
	return VI();
}

int main() {
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum) {
		memo.reset();
		int K;
		scanf("%d%d",&K,&N);
		Keys keys;
		while(K--){
			int x;
			scanf("%d",&x);
			++keys[x];
		}

		for(int i=0; i<N; ++i){
			int Ki;
			scanf("%d%d", &chests[i].need, &Ki);
			chests[i].contents.clear();
			while(Ki--){
				int x;
				scanf("%d",&x);
				chests[i].contents.push_back(x);
			}
		}

		printf("Case #%d: ", caseNum);
		VI res;
		for(int i=0; i<N; ++i){
			res = Solve(0, keys, i);
			if(!res.empty())
				break;
		}
		if(res.empty()){
			puts("IMPOSSIBLE");
		}
		else {
			for(int i=res.size()-1; i>=0; --i){
				printf("%d%c", res[i]+1, i==0?'\n':' ');
			}
		}
	}
	return 0;
}
