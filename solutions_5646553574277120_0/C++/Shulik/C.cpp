#include <cstdio>

#define REP(i, n)for (int i = 0; i < n; i++)

using namespace std;


int main(){
	int t;

	scanf("%d", &t);
	REP(testcase, t){
		int c, d, v;
		scanf("%d %d %d", &c, &d, &v);

		int coins[10];
		REP(i, d)scanf("%d", &coins[i]);

		bool pos[40];
		REP(i, v+1)pos[i]=false;
		pos[0] = true;
		REP(j, d){
			for(int i = v; i >=0; i--)if(pos[i] && i + coins[j] <= v)pos[i + coins[j]] = true;
		}
		int ret = 0;
		int cur = 0;
		REP(i, v+1){
			if(!pos[i])cur++;
			else{
				if(cur > ret)ret = cur;
				cur = 0;
			}
		}
		

		printf("Case #%d: %d\n", testcase+1, ret);
	}

	return 0;
}