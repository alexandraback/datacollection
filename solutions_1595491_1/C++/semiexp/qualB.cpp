#include <cstdio>
#include <vector>

using namespace std;

int T, N, S, P, t;

int main()
{
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		scanf("%d%d%d", &N, &S, &P);

		int ret = 0, cand = 0;
		for(int j=0;j<N;j++){
			scanf("%d", &t);
			if((t+2)/3 >= P) ret++;
			if(t<=1||t>=29) continue;
			else if(t==3*P-3 || t==3*P-4){
				cand++;
			}
		}
		cand = min(cand, S);
		printf("Case #%d: %d\n", i+1, ret+cand);
	}

	return 0;
}
