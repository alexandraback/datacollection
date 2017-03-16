#include <cstdio>

#define REP(i, n)for (int i = 0; i < n; i++)

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	REP(testcase, t){
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		int res = r*(c/w);
		res+=w-1;
		if(c%w != 0)res++;

		printf("Case #%d: %d\n", testcase+1, res);
	}

	return 0;
}